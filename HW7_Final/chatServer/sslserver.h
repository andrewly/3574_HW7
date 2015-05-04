#ifndef SSLSERVER_H
#define SSLSERVER_H

#include <QSslError>
#include <QTcpServer>
#include <QSslSocket>
#include <QSslKey>
#include <QList>

// QTcpServer extension to intercept new socket connection and enable SSL
// To be used by iTCH::Server for accepting encrypted connections
class SslServer : public QTcpServer
{
  Q_OBJECT

public:
    SslServer(QObject *parent = 0);
    // Since we have a new version of incomingComing connection, we have
    // to keep track of the SSL sockets created and return them with a
    // a revised version of nextPendingConnection.
    QSslSocket *nextPendingConnection();
    virtual void incomingConnection(qintptr socketDescriptor);
private:
    // a list to keep track of the sockets that we have created
    QList<QSslSocket *> m_secureSocketList;
};

#endif // SSLSERVER_H

