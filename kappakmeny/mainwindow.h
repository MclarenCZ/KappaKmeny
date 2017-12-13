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

    void Json(const QString &filename);
public slots:
        void connectioncreated();

private:
    Ui::MainWindow *ui;
    QString login;
    QString password;
    QTcpSocket *spojeni;
};

#endif // MAINWINDOW_H
