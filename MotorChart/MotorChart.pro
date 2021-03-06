#-------------------------------------------------
#
# Project created by QtCreator 2018-03-09T16:05:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MotorChart
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    odometer.cpp \
    chartviewzoom.cpp

HEADERS  += mainwindow.h \
    odometer.h \
    chartviewzoom.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/release/ -lQt5Charts
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/debug/ -lQt5Charts
else:unix: LIBS += -L/usr/lib/x86_64-linux-gnu/ -lQt5Charts

INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5/QtCharts
DEPENDPATH += /usr/include/x86_64-linux-gnu/qt5/QtCharts
