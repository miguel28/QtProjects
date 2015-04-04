#-------------------------------------------------
#
# Project created by QtCreator 2013-06-17T20:41:10
#
#-------------------------------------------------

QT       -= core gui

TARGET = HidApi
TEMPLATE = lib
CONFIG += staticlib

SOURCES += hidapi.cpp

HEADERS += hidapi.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

LIBS += -framework IOKit -framework CoreFoundation
