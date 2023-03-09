#include "widget.h"
#include <QMutex>
#include <QApplication>
#include <QDateTime>
#include <QFile>
#include <QtDebug>
#include <QTextStream>
#include <QDir>
#include <QSettings>
#include <stdio.h>
#include <iostream>
#include "Windows.h"
#include "HCNetSDK.h"
#include <time.h>
#include "QBreakpadHandler.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include "../sql/SqlMethod.h"
#include <map>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QBreakpadInstance.setDumpPath("crashes");    // 设置生成dump文件路径
    Widget w;
    w.showMaximized();
    return a.exec();
}



