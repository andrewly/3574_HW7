#ifndef SERVERWORKS_H
#define SERVERWORKS_H

#include <QString>
#include <QObject>
#include <QDebug>


class ServerWorks : public QObject
{
	Q_OBJECT;
pbulic:
	explicit ServerWorks();
	~ServerWorks();
	
	int checkClient(QString name);
	
	
signals:
	void serverOn(int on, int goodName);
	void messegeSend(QString message, QString target);
	void addMessage(QString message, QString target);	
	
public slots:
	void gotMessage(QString message, QString sender, QString target);
	void getClient(QString name);
	void exitClient(QString name);
private:
	Qstring members[20];
	int numbMembers;
	
	
	
};

#end if