#-------------------------------------------------
#
# Project created by QtCreator 2013-05-31T20:41:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PLCTerminalStateViewer
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
