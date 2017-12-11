#ifndef SERVERINIT_H
#define SERVERINIT_H

#include <QDebug>
#include <iostream>
#include <QTcpSocket>
#include <QTcpServer>
#include <QSqlQuery>
#include <player.h>


using namespace std;
 


class ServerInit : public QTcpServer
{
public:
    ServerInit();
public slots:
    void serverStart();
    void newClient();
    void disconnectClient();
private:
    QSqlDatabase db;
    QList<Player*> playerList;

};

#endif // SERVERINIT_H
