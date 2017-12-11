#include "login.h"
#include "ui_login.h"
#include <QMessageBox>


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

QString Login::getJmeno()
{
    return ui->lineEdit_Jmeno->text();
}

QString Login::getHeslo()
{
    return ui->lineEdit_Heslo->text();


}

Login::~Login()
{
    delete ui;
}






void Login::on_LoginButt_clicked()
{
    if (ui->lineEdit_Jmeno->text().isEmpty()){

            QMessageBox::information(this,"Chyba","Zapomněl jsi vyplnit jméno nebo heslo");
    }else {
    accept();
    }
}
