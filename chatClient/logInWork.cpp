#include "logInWork.h"

LogInWork::LogInWork()
{
	userName = "";
	server = 0;
	nameCheck = 0;
	
	//connect(Server,SIGNAL(info(QString)),this,SLOT(fromServer(int,int)));
}

LogInWork::~LogInWork()
{
	
}
		
void LogInWork::fromServer(int name, int on)
{
	//if ( on)
		server = 1;
		
	//else 
		//server = 0;
	
	//if  (name)
		nameCheck = 1;
	//else
		//checkName = 0;

}
		
void LogInWork::logInCheck(QString name)
{
	emit sendName
}

void LogInWork::startChat(QString name)
{
	chatwindow c(name);
	show c;
	quit();
}

void LogInWork::displayName(QString name);
{
	QMessageBox messageBox;
	messageBox.critical(0,"Error", name + " is already taken.");
	messageBox.setFixedSize(500,200);
}

void LogInWork::displayServer()
{
	QMessageBox messageBox;
	messageBox.critical(0,"Error","Please turn on the Server.");
	messageBox.setFixedSize(500,200);
}

void LogInWork::logInCheck(Qstring name)
{
	emit checkServer();
	//if server is not on
	if (server == 0)
	{
		displayServer(name);
	}
	//if 
	else if (nameCheck == 0)
	{
		displayName(name);	
	}
	else
	{
		Qstring check = "";
		//if the name is not null, connect
		if( name != check)
		{
			startChat(name);
		}
	}

}