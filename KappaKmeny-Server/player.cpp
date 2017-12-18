#include "player.h"

#include <QDataStream>
#include <QJsonDocument>

Player::Player(QTcpSocket *spojeni)
{
    this->spojeni = spojeni;
    connect(spojeni, &QTcpSocket::disconnected, this, &Player::clientDisconnected);
    connect(spojeni, &QTcpSocket::readyRead, this, &Player::playerToServer);
    connect(spojeni, &QTcpSocket::destroyed, this, &Player::playerToServer);
    //connect(spojeni, &QTcpSocket::)
}

void Player::clientDisconnected()
{
    emit(disconnected());

}

void Player::playerToServer()
{
    QDataStream stream;
    stream.setDevice(spojeni);
    stream.setVersion(QDataStream::Qt_5_0);
    stream.startTransaction();
    QString streamdata;
    stream >> streamdata;
    qDebug() << streamdata;
    QJsonDocument doc = QJsonDocument::fromJson(streamdata.toUtf8());
    QJsonObject action = doc.object();
    qDebug() << action["action"].toString();
    QString clientAction = action["action"].toString();
    QJsonObject data = action["data"].toObject();

    // podminky podle akce
    if(clientAction == "Login"){
        qDebug() << data["login"].toString();
    }




    /*
    {
        "action": "Login",
        "data": {
            "login": "Karel",
            "password": "Nazdar"
        }
    }
    */
}

void Player::serverToPlayer()
{
    qDebug() << "Chceme odeslat novou zprávu";
    QByteArray block;
    QDataStream output(&block, QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_0);
    output << "ahoj";
    spojeni->write(output);
}


QString Player::getSessionID() const
{
    return sessionID;
}

void Player::setSessionID(const QString &value)
{
    sessionID = value;
}
