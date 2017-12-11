#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QVariantMap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Login x;
    x.exec();
    jmeno = x.getJmeno();
    heslo = x.getHeslo();
    spojeni = new QTcpSocket(this);
    //    Dialog d;
    //    d.exec();
    //connect(spojeni, &QTcpSocket::error, this, &MainWindow::error2);
    connect(spojeni, &QTcpSocket::connected, this, &MainWindow::connectioncreated);
    spojeni->connectToHost(QHostAddress("127.0.0.1"), 3000);

    connect(spojeni, &QTcpSocket::readyRead, this, &MainWindow::gotMessage);
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() //odesílání
{
    QByteArray block;
    QDataStream output(&block, QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_0);
    output << jmeno;
    spojeni->write(block);
}

void MainWindow::gotMessage()
{
    qDebug() << spojeni->readAll();
}

void MainWindow::error2()
{
    qDebug() << spojeni->errorString();
}

void MainWindow::connectioncreated()
{
    QByteArray block;
    QDataStream output(&block, QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_0);
    output << jmeno;
    spojeni->write(block);
    qDebug() << "Connection established";
}

//void MainWindow::toJson() //pomoci QVariantMap
//{
//    QVariantMap jsonMap;
//    jsonMap.insert("notebookid", notebookid);
//    jsonMap.insert("tagid", tagid);
//    jsonMap.insert("userid", userid );
//    jsonMap.insert("subject", subject );
//    jsonMap.insert("comment", comment);

//    {
//        "action": "Login",
//        "data": {
//          "login": "Karel",
//          "password": "Nazdar",
//          }
//      }
//}
