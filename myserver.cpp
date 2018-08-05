#include "myserver.h"


myServer::myServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(server->listen(QHostAddress::Any, 1235))
    {
        qDebug() << "Server began running...\n";
    }
    else
    {
        qDebug() << "Server failed to run\n";
    }


}

void myServer::newConnection()
{
    QTcpSocket* socket = server->nextPendingConnection();

    socket->write("My name is jonas!!!\n\nSend me a message >> ");

    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();

}

