/*
//
//	Homework 7
//	
//	Team member 1: Andrew Yang
//	Team member 2: Alexander Borland
//
//	File: server.cpp
//	Edited: 5/4/2015
*/

#include <cassert>
#include <QDateTime>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
#include "server.h"
#include "ui_server.h"

const QString INVALID_FILE_MESSAGE = "Existing and readable key and certificate files must be specified.";

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
  ui->setupUi(this);

  // Check for SSL support.  If SSL support is not available, show a
  // message to the user describing what to do to enable SSL support.
  if (QSslSocket::supportsSsl())
  {
    ui->sslFilesGroupBox->setEnabled(true);
    ui->logTextEdit->setText(INVALID_FILE_MESSAGE);
  }
  else
  {
    QString noSslMsg = QString("%1\n%2")
        .arg("*** Your version of Qt does support SSL ***")
        .arg("You must obtain a version of Qt that has SSL"
             "support enabled.  If you believe that your "
             "version of Qt has SSL support enabeld, you may "
             "need to install the OpenSSL run-time libraries.");

    ui->logTextEdit->setText(noSslMsg);
  }

  connect(&server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
  
  QString ipa = getIPAddress();
  ui->label->setText(ui->label->text() + ipa);
  
}

Server::~Server()
{
  if (server.isListening())
  {
    server.close();
  }

  foreach (QSslSocket *socket, sockets)
  {
    delete socket;
  }
  
  foreach (QSslSocket *socket, sockets)
  {
    delete socket;
  }
  
  delete ui;
}

void Server::startStopButtonClicked()
{
  if (server.isListening())
  {
    server.close();
    ui->startStopButton->setText("Start Server");
    ui->logTextEdit->clear();
  }
  else
  {
    int port = ui->portSpinBox->value();
    if (server.listen(QHostAddress::Any, port))
    {
      ui->startStopButton->setText("Stop Server");
      ui->logTextEdit->setText(QString("Server listenting for connections on %1\n").arg(port));
    }
    else
    {
      ui->logTextEdit->setText(QString("Failed to start server: %1\n").arg(server.errorString()));
    }
  }
}

void Server::keyButtonClicked()
{
  QString filename = QFileDialog::getOpenFileName(this, "Select Key File");
  if (!filename.isNull())
  {
    ui->keyLineEdit->setText(filename);
  }
}

void Server::certificateButtonClicked()
{
  QString filename = QFileDialog::getOpenFileName(this, "Select Certificate File");
  if (!filename.isNull())
  {
    ui->certificateLineEdit->setText(filename);
  }
}

void Server::keyFileChanged(const QString &filename)
{
  key = filename;
  checkFileStatus();
}

void Server::certificateFileChanged(const QString &filename)
{
  certificate = filename;
  checkFileStatus();
}

void Server::checkFileStatus()
{
  QFileInfo keyInfo(key);
  QFileInfo certificateInfo(certificate);
  if (keyInfo.exists() && keyInfo.isReadable() &&
      certificateInfo.exists() && certificateInfo.isReadable())
  {
    ui->startStopButton->setEnabled(true);
    ui->logTextEdit->clear();
  }
  else
  {
    ui->startStopButton->setEnabled(false);
    ui->logTextEdit->setText(INVALID_FILE_MESSAGE);
  }
}

// Accept connection from server and initiate the SSL handshake
void Server::acceptConnection()
{
  QSslSocket *socket = server.nextPendingConnection();
  assert(socket);

  // QSslSocket emits the encrypted() signal after the encrypted connection is established
  connect(socket, SIGNAL(encrypted()), this, SLOT(handshakeComplete()));

  // Report any SSL errors that occur
  connect(socket, SIGNAL(sslErrors(const QList<QSslError> &)), this, SLOT(sslErrors(const QList<QSslError> &)));

  connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(connectionFailure()));

  socket->setPrivateKey(key);
  socket->setLocalCertificate(certificate);

  socket->setPeerVerifyMode(QSslSocket::VerifyNone);
  socket->startServerEncryption();
}

// Receive notification that the SSL handshake has completed successfully
void Server::handshakeComplete()
{
  QSslSocket *socket = dynamic_cast<QSslSocket *>(sender());
  assert(socket);

  connect(socket, SIGNAL(disconnected()), this, SLOT(connectionClosed()));
  connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));

  ui->logTextEdit->append(QString("[%1] Accepted connection from %2:%3")
                          .arg(QDateTime::currentDateTime().toString("hh:mm:ss.zzz ap"))
                          .arg(socket->peerAddress().toString())
                          .arg(socket->peerPort()));

  sockets.push_back(socket);
  users.push_back(socket->peerPort());
}

void Server::sslErrors(const QList<QSslError> &errors)
{
  QSslSocket *socket = dynamic_cast<QSslSocket *>(sender());
  assert(socket);

  QString errorStrings;
  foreach (QSslError error, errors)
  {
    errorStrings += error.errorString();
    if (error != errors.last())
    {
      errorStrings += ';';
    }
  }

  ui->logTextEdit->append(QString("[%1] %2:%3 reported the following SSL errors: %4")
      .arg(QDateTime::currentDateTime().toString("hh:mm:ss.zzz ap"))
                          .arg(socket->peerAddress().toString())
                          .arg(socket->peerPort())
                          .arg(errorStrings));
}

void Server::receiveMessage()
{
  QSslSocket *socket = dynamic_cast<QSslSocket *>(sender());
  assert(socket);

  if (socket->canReadLine())
  {
    QByteArray message = socket->readLine();
    QString sender = QString("%1:%2")
        .arg(socket->peerAddress().toString())
        .arg(socket->peerPort());

    ui->logTextEdit->append(QString("[%1] %2 sent: %3")
        .arg(QDateTime::currentDateTime().toString("hh:mm:ss.zzz ap"))
        .arg(sender)
        .arg(message.constData()));

    sender += " -> ";
    QString sentM(message);
    if(sentM.split("~").at(0).compare("Fetch") == 0)
    {
        QString userList;
        foreach (int name, users)
        {
            userList.append(names.value(name));
            userList.append("~");
        }
        userList.append("\n");
        socket->write(userList.toLocal8Bit().constData());
    }
    if(sentM.split("~").at(0).compare("AddUser") == 0)
    {
        //locate userName
        QStringList list = sentM.split("~");
        QString newVal = list.at(1);
        newVal.chop(1);
        names.insert(socket->peerPort(), newVal);
        namesR.insert(newVal, socket->peerPort());
    }

    if(sentM.split("~").at(0).compare("ConnectTo") == 0)
    {
        //locate target on free list
        QStringList list = sentM.split("~");
        QString otherUser = list.at(1);
        otherUser.chop(1);

        int i = users.indexOf(namesR.value(otherUser));

        if ( i != -1)
        {
            QSslSocket *other = sockets[i];

            chatUsers.append(socket->peerPort());
            chatUsers.append(other->peerPort());
            chatSockets.append(socket);
            chatSockets.append(other);

            users.removeOne(socket->peerPort());
            users.removeOne(other->peerPort());
            sockets.removeOne(socket);
            sockets.removeOne(other);

            QString complete = "Connected to user ";
            complete.append(names.value(other->peerPort()));
            complete.append("\n");
            socket->write(complete.toLocal8Bit().constData());
			
			//send open signal to other
			QString open("Open_Window~\n");
			other->write(open.toLocal8Bit().constData());
			complete = "Connected to user ";
            complete.append(names.value(socket->peerPort()));
            complete.append("\n");
            socket->write(complete.toLocal8Bit().constData());
        }
    }
        QString newM(message);
        if(newM.split("~").at(0).compare("Message") == 0)
        {
            newM.remove(0,8);
            qDebug() << newM;

            //locate user on takenList
            int i = chatUsers.indexOf(socket->peerPort());

            qDebug() << i;
            qDebug() << socket->peerPort();


            QSslSocket *target;
            if ( i != -1)
            {
                if ( (i%2) == 0)
                {
                    target = chatSockets.at(i+1);
                }
                else
                {
                    target = chatSockets.at(i-1);
                }
                qDebug() << target;
                qDebug() << socket;
                target->write(newM.toLocal8Bit().constData());
                socket->write(newM.toLocal8Bit().constData());
            }
        }
  }
}

void Server::connectionClosed()
{
  QSslSocket *socket = dynamic_cast<QSslSocket *>(sender());
  assert(socket);

  ui->logTextEdit->append(QString("[%1] Connection from %2:%3 closed: %4")
                          .arg(QDateTime::currentDateTime().toString("hh:mm:ss.zzz ap"))
                          .arg(socket->peerAddress().toString())
                          .arg(socket->peerPort())
                          .arg(socket->errorString()));
  sockets.removeOne(socket);
  users.removeOne(socket->peerPort());
  socket->disconnect();
  socket->deleteLater();
}

void Server::connectionFailure()
{
  QSslSocket *socket = dynamic_cast<QSslSocket *>(sender());
  assert(socket);

  ui->logTextEdit->append(QString("[%1] Connection from %2:%3 failed: %4")
                          .arg(QDateTime::currentDateTime().toString("hh:mm:ss.zzz ap"))
                          .arg(socket->peerAddress().toString())
                          .arg(socket->peerPort())
                          .arg(socket->errorString()));
  sockets.removeOne(socket);
  users.removeOne(socket->peerPort());
  socket->disconnect();
  socket->deleteLater();
}

QString Server::getIPAddress()
{
	QString prog = "/bin/bash";//shell
	QStringList arguments;
	arguments << "-c" << "ifconfig eth0 | grep ‘inet ‘ | awk ‘{print $2}’ | sed ’s/addr://’";
	QProcess* process = new QProcess(this);
	process->start(prog , arguments);
	process->waitForFinished();
	QString ip = process->readAll();
	//qDebug() << tmp;
	return ip;
}
