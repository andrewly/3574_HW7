#-------------------------------------------------
#
# Project created by QtCreator 2015-05-02T18:55:32
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatClient
TEMPLATE = app


SOURCES += \
    main.cpp \
    client.cpp \
    chat.cpp \
    controller.cpp \
    select.cpp

HEADERS  += \
    client.h \
    chat.h \
    controller.h \
    select.h

FORMS    += \
    client.ui \
    chat.ui \
    select.ui
