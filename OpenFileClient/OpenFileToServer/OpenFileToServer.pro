#-------------------------------------------------
#
# Project created by QtCreator 2015-01-15T23:49:15
#
#-------------------------------------------------

QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenFileToServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cycthread.cpp

HEADERS  += mainwindow.h \
    cycthread.h

FORMS    += mainwindow.ui

RESOURCES += \
    pic.qrc
