/*
//
//	Homework 7
//	
//	Team member 1: Andrew Yang
//	Team member 2: Alexander Borland
//
//	File: client.h
//	Edited: 5/4/2015
*/

#ifndef CLIENT_H
#define CLIENT_H

#include <QSslSocket>
#include <QMainWindow>

namespace Ui {
  class Client;
}

class Client : public QMainWindow
{
  Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    void setSocket(QSslSocket *soc);
  ~Client();

protected slots:
  // Slots to receive signals from UI
  void connectDisconnectButtonPressed();

  // Slots to receive signals from QSslSocket
  void connectedToServer();
  void sslErrors(const QList<QSslError> &errors);
  void receiveMessage();
  void connectionClosed();
  void socketError();

private:
  QSslSocket *socket;
  Ui::Client *ui;


signals:
    void conSet(QString user);
};

#endif // CLIENT_H
