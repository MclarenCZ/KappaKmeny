#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

QString Dialog::address()
{
    return ui->lineEdit->text();
}

int Dialog::port()
{
    return ui->spinBox->value();
}

Dialog::~Dialog()
{
    delete ui;
}
