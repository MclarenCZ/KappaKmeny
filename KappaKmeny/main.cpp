#include <QCoreApplication>
#include <serverinit.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ServerInit serverinstance;
    serverinstance.serverStart();

    return a.exec();
}
