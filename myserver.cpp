#include "myserver.h"
#include <iostream>
#include <string>


myServer::myServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(server->listen(QHostAddress::Any, 1111))
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

    socket->write("------------------------------\r\nWELCOME TO THE G9 INTERFACE\r\n------------------------------\n ");

    socket->waitForBytesWritten(3000);

    socket->flush();

    socket->write("------------------------------\r\nENTER YOU USER NAME\r\n------------------------------\n ");

    socket->waitForBytesWritten(3000);

    socket->flush();


    // collect data
    int num_bytes;
    QByteArray* arr = nullptr;

    do
    {
        socket->waitForReadyRead(-1);

        num_bytes = (int)socket->bytesAvailable();

        qDebug() << "Num bytes available: " << num_bytes;

        arr = new QByteArray(socket->readAll(), 1024);

        qDebug() << "Sent data from client:  "<< arr->data();

    }while(arr->toStdString() != "end");


    socket->close();

}

