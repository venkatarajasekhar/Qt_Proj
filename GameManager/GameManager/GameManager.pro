#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T20:30:05
#
#-------------------------------------------------

QT       += core gui
QT += winextras
RC_ICONS = logo.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mybutton.cpp \
    cycthread.cpp

HEADERS  += mainwindow.h \
    mybutton.h \
    cycthread.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

OTHER_FILES +=
