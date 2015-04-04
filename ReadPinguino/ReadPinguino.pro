#-------------------------------------------------
#
# Project created by QtCreator 2013-07-17T20:08:23
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ReadPinguino
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    USBInterface/USBInterfaceClass.cpp \
    USBInterface/hid.c

HEADERS += \
    USBInterface/USBInterfaceClass.h \
    USBInterface/hidapi.h

LIBS += -framework IOKit -framework CoreFoundation
