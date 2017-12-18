#include "serverinit.h"

ServerInit::ServerInit() : QTcpServer::QTcpServer()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../KappaKmeny/kappakmeny.db");
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
       player->setSessionID("15");
       player->status = "UnLogged";
       playerList.append(player);
       connect(player, &Player::disconnected, this, &ServerInit::disconnectClient);
       printPlayers();
}

void ServerInit::disconnectClient()
{
    Player *player = static_cast<Player *>(QObject::sender());
    playerList.removeOne(player);
    cout << "ClientDisconnect" << endl;
    printPlayers();

}

void ServerInit::printPlayers()
{
    cout << "ListPlayers" << endl;
    for (int i = 0; i < playerList.length(); ++i) {
        qDebug() << playerList[i]->getSessionID() << " status: " << playerList[i]->status;
    }
    cout << "End" << endl;
}

