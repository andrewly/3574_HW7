#include "chatWorks.h"

ChatWork::ChatWork(QString name)
{
    userName = name;
	
	//connect(Server,SIGNAL(messages(QString, QString)),this,SLOT(receving(QString, QString)));
	//connect(Server,SIGNAL(messages(QString, QString)),this,SLOT(newMembers(QString)));
}

WorkObject::~WorkObject()
{

}

void WorkObject::sendMessage(QString chat, QString person)
{
    //sends a signal for the message
	qDebug() << "Doing Work in thread: " << QObject::thread();
    emit sending(chat, person);
}

void WorkObject::newMemebers(QString member)
{
	//adds the new member to the list of targets.
	userChat.addItem(member);
}

void WorkObject::exitChat();
{
	//sends the exit signal to remove from list.
	emit exit();
}



