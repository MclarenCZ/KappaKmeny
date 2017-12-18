#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class Player : public QObject
{
    Q_OBJECT
public:
    Player(QTcpSocket *spojeni);
    QString getSessionID() const;
    void setSessionID(const QString &value);

    QTcpSocket *spojeni;
    QString status;
private slots:
    void clientDisconnected();
    void playerToServer();
    void serverToPlayer();
private:
    QString sessionID;

signals:
    void disconnected();
};

#endif // PLAYER_H
