#ifndef LOGINWORK_H
#define LOGINWORK_H

#include <QString>
#include <QObject>

class logInWork : public QObject
{
	Q_OBJECT;
	public:
		explicit LogInWork();
		~LogInWork();
		
		getServer();
		
		
		void logInCheck(QString name);

		void startChat(QString name);

		void displayName(QString name);

		void displayServer();
		
		void setName(QString name);
		
	signals:
		void checkServer(QString name);
	public slots:
		void fromServer(int name, int on);
	private:
		Qstring userName;
		int server;
		int nameCheck
		
};


#endif