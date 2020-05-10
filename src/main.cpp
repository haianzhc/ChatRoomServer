#include <QCoreApplication>

#include "ServerDemo.h"
#include "ServerHandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerDemo server;
    ServerHandler handler;

    server.setHandler(&handler);
    server.start(8890);

    return a.exec();
}
