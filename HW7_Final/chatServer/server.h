/*
//
//	Homework 7
//	
//	Team member 1: Andrew Yang
//	Team member 2: Alexander Borland
//
//	File: server.h
//	Edited: 5/4/2015
*/

#ifndef SERVER_H
#define SERVER_H

#include <QList>
#include <QMap>
#include <QProcess>
#include <QSslSocket>
#include <QMainWindow>
#include "sslserver.h"

namespace Ui {
  class Server;
}

class Server : public QMainWindow
{
  Q_OBJECT

public:
  explicit Server(QWidget *parent = 0);
  ~Server();

protected slots:
  // Slots to receive signals from UI
  void startStopButtonClicked();
  void keyButtonClicked();
  void certificateButtonClicked();
  void keyFileChanged(const QString &filename);
  void certificateFileChanged(const QString &filename);

  // Slots to receive signals from sockets
  void acceptConnection();
  void handshakeComplete();
  void sslErrors(const QList<QSslError> &errors);
  void receiveMessage();
  void connectionClosed();
  void connectionFailure();

private:
  void checkFileStatus();

private:
  QString key;
  QString certificate;
  SslServer server;
  QList<QSslSocket *> sockets;
  QList<int> users;
  QMap<int,QString> names;
  QMap<QString,int> namesR;
  QList<QSslSocket *> chatSockets; //list of non free Sockets
  QList<int> chatUsers;//list of non free users
  
  QString getIPAddress();
  
  Ui::Server *ui;
};

#endif // SERVER_H
