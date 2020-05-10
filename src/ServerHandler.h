#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include "TxMsgHandler.h"
#include "TextMessage.h"

#include <QTcpSocket>
#include <QList>
#include <QMap>

class ServerHandler : public TxMsgHandler
{
    typedef void (ServerHandler::*MSGHandler) (QTcpSocket&,TextMessage&);

    struct Node
    {
        QString id;
        QString pwd;
        QString status;
        QString level;
        QTcpSocket* socket;

    public:
        Node() : id(""),pwd(""),status("ok"),level("user"),socket(NULL)
        {

        }
    };

    QList<Node*> m_nodeList;
    QMap<QString,MSGHandler> m_handlerMap;

    QString getOnlineUserId();
    void sendToAllOnlineUser(TextMessage&);

    void CONN_Handler(QTcpSocket&,TextMessage&);
    void DSCN_Handler(QTcpSocket&,TextMessage&);
    void LGIN_Handler(QTcpSocket&,TextMessage&);
    void MSGA_Handler(QTcpSocket&,TextMessage&);
    void MSGP_Handler(QTcpSocket&,TextMessage&);
    void ADMN_Handler(QTcpSocket&,TextMessage&);
public:
    ServerHandler();
    void handle(QTcpSocket& obj,TextMessage& message);
};

#endif // SERVERHANDLER_H
