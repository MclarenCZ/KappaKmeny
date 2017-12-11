#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    QString getJmeno();
    QString getHeslo();
    ~Login();



private slots:
    void on_LoginButt_clicked();

private:
    Ui::Login *ui;


};

#endif // LOGIN_H
