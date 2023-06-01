#include <QCoreApplication>
#include "QtHttpForS.h"
#include "httpMethord.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    httpMethord w;
    return a.exec();
}
