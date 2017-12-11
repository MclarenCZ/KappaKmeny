#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTcpSocket>
#include <login.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString jmeno;
    QString heslo;


private slots:
    void on_pushButton_clicked();
    void gotMessage();
    void error2();
    void connectioncreated();
    //void toJson();

private:
    Ui::MainWindow *ui;
    QTcpSocket *spojeni;

};

#endif // MAINWINDOW_H
