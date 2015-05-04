/*
//
//	Homework 7
//	
//	Team member 1: Andrew Yang
//	Team member 2: Alexander Borland
//
//	File: main.cpp
//	Edited: 5/4/2015
*/

#include <QApplication>
#include "controller.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  controller c;
  c.start();

  return a.exec();
}
