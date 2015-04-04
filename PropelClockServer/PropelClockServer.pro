#-------------------------------------------------
#
# Project created by QtCreator 2013-06-01T20:55:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PropelClockServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    USBInterface/USBInterfaceClass.cpp \
    USBInterface/hid.c

HEADERS  += mainwindow.h \
    USBInterface/USBInterfaceClass.h \
    USBInterface/hidapi.h

FORMS    += mainwindow.ui

LIBS += -framework IOKit -framework CoreFoundation
