#ifndef CHATWORK_H
#define CHATWORK_H

#include <QString>
#include <QObject>

class chatWork : public QObject
{
    Q_OBJECT;
public:
    explicit ChatWork(QString name);
    ~ChatWork();
	
	void exitChat();
	
	void sendMessage(QString chat, QString person);

signals:
    void sending(Qstring, QString);
	void exit(void);

public slots:
	void receving(QString, QString);
	void newMemebers(QString);

private:
	int exitSignal;
};

#endif