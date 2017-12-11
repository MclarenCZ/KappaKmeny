#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QTcpSocket>

class Player : public QObject
{
    Q_OBJECT
public:
    Player(QTcpSocket *spojeni);
private slots:
    void clientDisconnected();
signals:
    void disconnected();
};

#endif // PLAYER_H
