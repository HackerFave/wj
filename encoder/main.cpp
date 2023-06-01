#include <QCoreApplication>
#include "func.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    func f;
    return a.exec();
}
