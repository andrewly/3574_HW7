/*
//
//	Homework 7
//	
//	Team member 1: Andrew Yang
//	Team member 2: Alexander Borland
//
//	File: chat.cpp
//	Edited: 5/4/2015
*/

#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
}

chat::~chat()
{
    delete ui;
}

void chat::setSocket(QSslSocket *soc)
{
    socket = soc;
    socket->disconnect(SIGNAL(readyRead()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
}

void chat::receiveMessage()
{
    if ((*socket).canReadLine())
    {
        QByteArray message = (*socket).readLine();
        QString strM(message);
        ui->textBrowser->append(strM);
    }
}

void chat::on_pushButton_pressed()
{
    QString message;
    message.append("Message~[");
    message.append(username);
    message.append("]: ");
    message.append(ui->textEdit->toPlainText());
    if (!message.isEmpty())
    {
        message += '\n';
        (*socket).write(message.toLocal8Bit().constData());
        ui->textEdit->clear();
    }
}
