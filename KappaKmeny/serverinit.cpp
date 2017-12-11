#include "serverinit.h"

ServerInit::ServerInit() : QTcpServer::QTcpServer()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../KappaKmeny/master.db");
    db.open();
}

void ServerInit::serverStart()
{
    cout << "Server Start" << endl;
    if(!listen(QHostAddress::Any, 5858))
    {
        cout << "Nepodarilo se spustit naslouchani serveru"<< endl;
    }
    else
    {
        cout << "Server nasloucha na portu : "<<serverPort()<< endl;
        connect(this, &QTcpServer::newConnection, this, &ServerInit::newClient);
    }
}

void ServerInit::newClient()
{
       cout << "NewClient" << endl;
       QTcpSocket *spojeni = this->nextPendingConnection();
       Player* player = new Player(spojeni);
       playerList.append(player);
       connect(player, &Player::disconnected, this, &ServerInit::disconnectClient);

}

void ServerInit::disconnectClient()
{
    cout << "ClientDisconnect" << endl;
}

