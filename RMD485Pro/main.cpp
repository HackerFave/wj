#include <QApplication>
#include "func.h"
#include <QSharedPointer>
#include "datashowform.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    func fun;
    dataShowForm w;
    w.show();
    return a.exec();
}
