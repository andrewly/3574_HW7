/*
//
//	Homework 7
//	
//	Team member 1: Andrew Yang
//	Team member 2: Alexander Borland
//
//	File: select.cpp
//	Edited: 5/4/2015
*/

#include "select.h"
#include "ui_select.h"
#include <QDebug>

Select::Select(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Select)
{
    ui->setupUi(this);
}

Select::~Select()
{
    delete ui;
}

void Select::setSocket(QSslSocket *soc)
{
    socket = soc;
    socket->disconnect(SIGNAL(readyRead()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
}

void Select::receiveMessage()
{
    if ((*socket).canReadLine())
    {
        QByteArray message = (*socket).readLine();
        QString strM(message);
		
		//checks to see if message was the open command
		if(strM.split("~").at(0).compare("Open_Window") == 0)
		{
			emit conSet();
		}
		//else, run the normal function
		else
		{
			QStringList strList = strM.split("~");
			foreach(QString str, strList)
			{
				ui->listWidget->addItem(str);
			}
		}
    }
}

void Select::on_pushButton_pressed()
{
    ui->listWidget->clear();
    QString Query("Fetch~\n");
    socket->write(Query.toLocal8Bit().constData());
}

void Select::on_pushButton_2_pressed()
{
    QString Query("ConnectTo~");
    if(ui->listWidget->currentItem() != NULL)
    {
        Query.append(ui->listWidget->currentItem()->text());
        Query.append("\n");
        qDebug() << Query;
        socket->write(Query.toLocal8Bit().constData());
        emit conSet();
    }
}
