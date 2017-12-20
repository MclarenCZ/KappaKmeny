#include "login.h"
#include "ui_login.h"

#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    try_connect();



}

Login::~Login()
{
    delete ui;
}

QString Login::getPassword() const
{
    return password;
}

void Login::setPassword(const QString &value)
{
    password = value;
}

QString Login::getLogin() const
{
    return login;
}

void Login::setLogin(const QString &value)
{
    login = value;
}



void Login::on_pushButton_clicked()
{
    if (ui->loginLine->text().isEmpty() && ui->passwordLine->text().isEmpty()){

            QMessageBox::information(this,"Chyba","Zapomněl jsi vyplnit jméno nebo heslo");
    }else {
     setPassword(ui->passwordLine->text());
     setLogin(ui->loginLine->text());
    accept();
    }
}

void Login::try_connect()
{
    spojeni = new QTcpSocket(this);
    connect(spojeni, &QTcpSocket::hostFound, this, &Login::on_Connected);

    spojeni->connectToHost(QHostAddress("127.0.0.1"), 5858);
}

void Login::on_Connected()
{
    ui->status->setText("Status: Online");
}

