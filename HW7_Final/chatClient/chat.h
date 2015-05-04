/*
//
//	Homework 7
//	
//	Team member 1: Andrew Yang
//	Team member 2: Alexander Borland
//
//	File: chat.h
//	Edited: 5/4/2015
*/

#ifndef CHAT_H
#define CHAT_H

#include <QSslSocket>
#include <QMainWindow>

namespace Ui {
class chat;
}

class chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = 0);
    void setSocket(QSslSocket *soc);
    void setUsername(QString user){ username = user; }
    ~chat();

private:
    Ui::chat *ui;
    QSslSocket *socket;
    QString username;

protected slots:
    void receiveMessage();
private slots:
    void on_pushButton_pressed();
};

#endif // CHAT_H
