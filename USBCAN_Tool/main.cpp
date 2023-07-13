#include "start.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    start w;
    w.show();

    return a.exec();
}
