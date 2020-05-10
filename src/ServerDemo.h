#ifndef SERVERDEMO_H
#define SERVERDEMO_H

#include <QObject>
#include <QTcpServer>
#include <QMap>

#include "TxtMsgAssembler.h"
#include "TextMessage.h"
#include "TxMsgHandler.h"

class ServerDemo : public QObject
{
    Q_OBJECT

    QTcpServer m_server;
    QMap<QTcpSocket*,TxtMsgAssembler*> m_map;
    TxMsgHandler* m_handler;

public:
    ServerDemo(QObject* parent = NULL);
    bool start(int port);
    void stop();
    void setHandler(TxMsgHandler* handler);
    ~ServerDemo();

protected slots:
    void onNewConnection();
    void onConnected();
    void onDisconnected();
    void onDataReady();
    void onBytesWritten(qint64 bytes);
};

#endif // SERVERDEMO_H
