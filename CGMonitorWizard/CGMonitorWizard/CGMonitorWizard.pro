#-------------------------------------------------
#
# Project created by QtCreator 2015-02-12T00:30:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CGMonitorWizard
TEMPLATE = app


SOURCES += main.cpp\
        wizard.cpp \
    wizard_mainpage.cpp \
    wizard_network_config.cpp \
    wizard_wired_config.cpp \
    wizard_wirless_config.cpp \
    wizard_sensor_config.cpp

HEADERS  += wizard.h \
    wizard_mainpage.h \
    wizard_network_config.h \
    wizard_wired_config.h \
    wizard_wirless_config.h \
    wizard_sensor_config.h

FORMS    += wizard.ui \
    wizard_mainpage.ui \
    wizard_network_config.ui \
    wizard_wired_config.ui \
    wizard_wirless_config.ui \
    wizard_sensor_config.ui
