#-------------------------------------------------
#
# Project created by QtCreator 2015-04-12T23:37:27
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = chatClient
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    login.cpp \
    chatwindow.cpp \
	chatWorks.cpp \
	logInWork.cpp

FORMS += \
    login.ui \
    chatwindow.ui\
	

HEADERS += \
    login.h \
    chatwindow.h\
	chatWorks.h\
	logInWork.h