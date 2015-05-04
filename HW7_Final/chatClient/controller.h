/*
//
//	Homework 7
//	
//	Team member 1: Andrew Yang
//	Team member 2: Alexander Borland
//
//	File: controller.h
//	Edited: 5/4/2015
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QSslSocket>
#include <QString>
#include "client.h"
#include "chat.h"
#include "select.h"

class controller : public QObject
{

    Q_OBJECT

public:
    controller();
    void start();
private:
    QString username;
    QSslSocket socket;
    Client cli;
    Select sel;
    chat cha;
protected slots:
    void selectF(QString user);
    void chatF();

};

#endif // CONTROLLER_H
