#-------------------------------------------------
#
# Project created by QtCreator 2014-06-28T13:53:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HIDTerminal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    USBInterface/USBInterfaceClass.cpp \
    USBInterface/hid.c

HEADERS  += mainwindow.h \
    USBInterface/hidapi.h \
    USBInterface/USBInterfaceClass.h

FORMS    += mainwindow.ui

CXXFLAGS = -stdlib=libstdc++
LIBS += -framework IOKit -framework CoreFoundation
