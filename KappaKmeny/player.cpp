#include "player.h"

Player::Player(QTcpSocket *spojeni)
{
    connect(spojeni, &QTcpSocket::disconnected, this, &Player::clientDisconnected);
}

void Player::clientDisconnected()
{
    emit(disconnected());
}
