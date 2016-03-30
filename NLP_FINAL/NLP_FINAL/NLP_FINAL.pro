#-------------------------------------------------
#
# Project created by QtCreator 2014-06-06T19:22:19
#
#-------------------------------------------------

QT       += core gui
QT		+= network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NLP_FINAL
TEMPLATE = app
RC_ICONS = logo.ico

SOURCES += main.cpp\
        mainwindow.cpp \
    qmyhashthread.cpp \
    dialog.cpp \
    qmytextedit.cpp \
    inputdialog.cpp \
    qaddfilethread.cpp

HEADERS  += mainwindow.h \
    qmyhashthread.h \
    dialog.h \
    qmytextedit.h \
    inputdialog.h \
    qaddfilethread.h

FORMS    += mainwindow.ui \
    dialog.ui \
    inputdialog.ui

RESOURCES += \
    Image.qrc
