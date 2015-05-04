/*
//
//	Homework 7
//	
//	Team member 1: Andrew Yang
//	Team member 2: Alexander Borland
//
//	File: client.cpp
//	Edited: 5/4/2015
*/

#include <QDateTime>
#include <QMessageBox>
#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Client)
{
  ui->setupUi(this);

  ui->connectDisconnectButton->setEnabled(true);

}

Client::~Client()
{
    if ((*socket).isOpen())
    {
        (*socket).close();
    }
    delete ui;
}

void Client::connectDisconnectButtonPressed()
{
  ui->connectDisconnectButton->setEnabled(false);

  if ((*socket).state() == QAbstractSocket::UnconnectedState)
  {
    // Initiate an SSL connection to the chat server.
    (*socket).abort();
    (*socket).setPeerVerifyMode(QSslSocket::QueryPeer);
    (*socket).connectToHostEncrypted(ui->hostnameLineEdit->text(), ui->portSpinBox->value());
  }
  else
  {
    (*socket).close();
  }
}

void Client::connectedToServer()
{
    ui->connectDisconnectButton->setText("Disconnect");
    ui->connectDisconnectButton->setEnabled(true);
    QString newStr;
    newStr.append("AddUser~");
    newStr.append(ui->textEdit->toPlainText());
    newStr.append("\n");
    socket->write(newStr.toLocal8Bit().constData());
    emit conSet(ui->textEdit->toPlainText());
}

// Process SSL errors
void Client::sslErrors(const QList<QSslError> &errors)
{
  QString errorStrings;
  foreach (QSslError error, errors)
  {
    errorStrings += error.errorString();
    if (error != errors.last())
    {
      errorStrings += '\n';
    }
  }

  // Display error details to user and ask for permission to proceed anyway
  QMessageBox::StandardButton result = QMessageBox::question(this, "SSL Errors",
    QString("The following errors were encountered while negotiating the SSL connection:\n\n%1\n\nProceed anyway?").arg(errorStrings),
    QMessageBox::Yes|QMessageBox::No);
  if (result == QMessageBox::Yes)
  {
    (*socket).ignoreSslErrors();
  }
}

void Client::receiveMessage()
{
}

void Client::connectionClosed()
{
  ui->connectDisconnectButton->setText("Connect");
  ui->connectDisconnectButton->setEnabled(true);
}

void Client::socketError()
{
  if ((*socket).state() != QAbstractSocket::ConnectedState)
  {
    connectionClosed();
  }
  (*socket).close();
}

void Client::setSocket(QSslSocket *soc)
{
    socket = soc;

    connect(socket, SIGNAL(encrypted()), this, SLOT(connectedToServer()));
    connect(socket, SIGNAL(sslErrors(const QList<QSslError> &)), this, SLOT(sslErrors(const QList<QSslError> &)));
    connect(socket, SIGNAL(disconnected()), this, SLOT(connectionClosed()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError()));
}
