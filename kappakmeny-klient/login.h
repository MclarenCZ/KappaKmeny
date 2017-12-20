#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    QString getPassword() const;
    void setPassword(const QString &value);

    QString getLogin() const;
    void setLogin(const QString &value);


private slots:
    void on_pushButton_clicked();
    void try_connect();
    void on_Connected();


private:
    Ui::Login *ui;
    QString login;
    QString password;
    QTcpSocket *spojeni;
};

#endif // LOGIN_H
