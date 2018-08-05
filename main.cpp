#include <QCoreApplication>
#include "myServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    myServer the_serv;

    return a.exec();
}
