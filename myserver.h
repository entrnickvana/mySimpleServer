#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

#include <QObject>

class myServer : public QObject
{
    Q_OBJECT
public:
    explicit myServer(QObject *parent = nullptr);

signals:

public slots:
    void newConnection();


private:
    QTcpServer* server;
};

#endif // MYSERVER_H
