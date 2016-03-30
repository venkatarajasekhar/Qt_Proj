#-------------------------------------------------
#
# Project created by QtCreator 2015-01-16T00:45:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenFileFromClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cycthread.cpp

HEADERS  += mainwindow.h \
    cycthread.h

FORMS    += mainwindow.ui

RESOURCES += \
    pic.qrc
