#include "chartviewzoom.h"
#include <QApplication>
#include <QDebug>

ChartViewZoom::ChartViewZoom(QWidget *parent) : QChartView(parent)
{
    //setDragMode(QGraphicsView::NoDrag);
    this->setMouseTracking(true);
    isPanning = false;
    _modifiers = Qt::ControlModifier;

}

void ChartViewZoom::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        panStartX = event->x();
        panStartY = event->y();
        isPanning = true;
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        return;
    }
    QChartView::mousePressEvent(event);
}
void ChartViewZoom::mouseReleaseEvent(QMouseEvent *event)
{
    isPanning = false;
    if (event->button() == Qt::RightButton)
    {
        setCursor(Qt::ArrowCursor);
        event->accept();
        return;
    }
    QChartView::mousePressEvent(event);
}

void ChartViewZoom::mouseMoveEvent(QMouseEvent *event)
{
#if 0
    // pan the chart with a middle mouse drag
    if (event->buttons() & Qt::MiddleButton)
    {
        QRectF bounds = QRectF(0,0,0,0);
//        for(auto series : this->chart()->series())
//            bounds.united(series->bounds());
        bounds = this->chart()->boundingRect();

        auto dPos = this->chart()->mapToValue(event->pos()) - this->chart()->mapToValue(m_lastMousePos);

        if (this->rubberBand() == QChartView::RectangleRubberBand)
            this->chart()->zoomIn(bounds.translated(-dPos.x(), -dPos.y()));
        else if (this->rubberBand() == QChartView::HorizontalRubberBand)
            this->chart()->zoomIn(bounds.translated(-dPos.x(), 0));
        else if (this->rubberBand() == QChartView::VerticalRubberBand)
            this->chart()->zoomIn(bounds.translated(0, -dPos.y()));

        m_lastMousePos = event->pos();
        event->accept();
    }
#endif
    if (isPanning) {
               //chart()->scroll(-10, 0);
        this->chart()->scroll((qreal)(panStartX - event->x()), 0);
        panStartX = event->x();
        panStartY = event->y();
        event->accept();
        return;
    }
    QChartView::mouseMoveEvent(event);
}

void ChartViewZoom::wheelEvent(QWheelEvent *event)
{
    if (QApplication::keyboardModifiers() == _modifiers) {
        QWheelEvent* wheel_event = static_cast<QWheelEvent*>(event);
        if (wheel_event->orientation() == Qt::Vertical) {
            //        double angle = wheel_event->angleDelta().y();
            //        double factor = qPow(_zoom_factor_base, angle);
            //        gentle_zoom(factor);
            //        return true;

            chart()->zoomReset();

            scaleFactorX *= event->angleDelta().y() > 0 ? 0.5 : 2;

            QRectF rect = chart()->plotArea();
            QPointF c = chart()->plotArea().center();
            rect.setWidth(scaleFactorX*rect.width());
            rect.moveCenter(c);
            chart()->zoomIn(rect);
            return;
        }
    }

        QChartView::wheelEvent(event);
}
