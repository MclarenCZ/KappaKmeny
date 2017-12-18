#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QTcpSocket>
#include <QHostAddress>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Login l;
    l.exec();
    password=l.getPassword();
    login=l.getLogin();
    qDebug() << login << password;
    spojeni = new QTcpSocket(this);
    connect(spojeni, &QTcpSocket::connected, this, &MainWindow::connectioncreated);
    spojeni->connectToHost(QHostAddress("127.0.0.1"), 5858);
//    connect(spojeni, &QTcpSocket::readyRead, this, &MainWindow::gotMessage);

    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectioncreated()
{
    QByteArray block;
    QDataStream stream(&block, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);
    stream << Json();
    spojeni->write(block);


    qDebug() << "conection established";
}

QJsonDocument MainWindow::Json()
{

//    QFile file(filename);
//    if(!file.open(QIODevice::WriteOnly))
//    {
//        qWarning() << "Chyba pri pristupu k souboru: " << filename;
//        return;
//    }
    QJsonDocument doc;
    QJsonObject log;


    log["login"] = login;
    log["password"] = password;
    QJsonArray data;
    QJsonObject datao;
    datao["action"]="login";
    data.append(log);
    datao["data"]=data;

    doc.setObject(datao);
    return doc;
//    file.write(doc.toJson());
//    file.close();
}
