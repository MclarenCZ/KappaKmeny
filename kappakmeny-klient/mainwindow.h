#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTcpSocket>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QJsonDocument Json();
public slots:
        void connectioncreated();
        QString loginJson();

private:
    Ui::MainWindow *ui;
    QString login;
    QString password;
    QTcpSocket *spojeni;
};

#endif // MAINWINDOW_H
