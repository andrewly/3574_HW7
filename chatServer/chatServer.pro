#-------------------------------------------------
#
# Project created by QtCreator 2015-04-13T01:10:37
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = chatServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    serverscreen.cpp \
	serverWorks.cpp

FORMS += \
    serverscreen.ui

HEADERS += \
    serverscreen.h \
	serverWorks.h
