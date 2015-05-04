#-------------------------------------------------
#
# Project created by QtCreator 2015-05-02T18:33:40
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatServer
TEMPLATE = app


SOURCES += \
    sslserver.cpp \
    server.cpp \
    main.cpp

HEADERS  += \
    sslserver.h \
    server.h

FORMS    += \
    server.ui

OTHER_FILES +=
