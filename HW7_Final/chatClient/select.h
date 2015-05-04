#ifndef SELECT_H
#define SELECT_H

#include <QSslSocket>
/*
//
//	Homework 7
//	
//	Team member 1: Andrew Yang
//	Team member 2: Alexander Borland
//
//	File: select.h
//	Edited: 5/4/2015
*/

#include <QMainWindow>

namespace Ui {
class Select;
}

class Select : public QMainWindow
{
    Q_OBJECT

public:
    explicit Select(QWidget *parent = 0);
    void setSocket(QSslSocket *soc);
    ~Select();

private:
    Ui::Select *ui;
    QSslSocket *socket;

protected slots:
    void receiveMessage();

private slots:
    void on_pushButton_pressed();
    void on_pushButton_2_pressed();

signals:
    void conSet();
};

#endif // SELECT_H
