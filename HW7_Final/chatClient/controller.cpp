/*
//
//	Homework 7
//	
//	Team member 1: Andrew Yang
//	Team member 2: Alexander Borland
//
//	File: controller.cpp
//	Edited: 5/4/2015
*/

#include "controller.h"
#include <QDebug>

controller::controller()
{
}

void controller::start()
{
    cli.show();
    cli.setSocket(&socket);
    connect(&cli, SIGNAL(conSet(QString)), this, SLOT(selectF(QString)));
}

void controller::selectF(QString user)
{
    username = user;
    sel.show();
    sel.setSocket(&socket);
    connect(&sel, SIGNAL(conSet()), this, SLOT(chatF()));
}

void controller::chatF()
{
    cha.show();
    cha.setUsername(username);
    cha.setSocket(&socket);
}
