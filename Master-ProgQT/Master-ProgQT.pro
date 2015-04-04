#-------------------------------------------------
#
# Project created by QtCreator 2013-06-15T20:18:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Master-ProgQT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    USBInterface/USBInterfaceClass.cpp \
    USBInterface/hid.c \
    USBInterface/ProgCommand.cpp \
    USBInterface/DeviceFile.cpp \
    USBInterface/BinaryReader.cpp

HEADERS  += mainwindow.h \
    USBInterface/USBInterfaceClass.h \
    USBInterface/hidapi.h \
    USBInterface/ProgCommand.h \
    USBInterface/DeviceFile.h \
    USBInterface/BinaryReader.h

FORMS    += mainwindow.ui

LIBS += -framework IOKit -framework CoreFoundation

RESOURCES +=
