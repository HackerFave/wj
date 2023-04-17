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
//    uint8_t s[4] = {0x10,0x22,0x04,0x11};
//    float t ;
//    memmove(&t,s,4);
//    float ss=*(float*)(s);

//    float test = 1.98;
//    uint8_t test1[4] = {};
//    memmove(test1 , &test,sizeof(float));
//    qDebug()<<t<<ss<<test1<<"IIIIIIIIIII";
//    for(int i =0 ;i<4;i++){
//        qDebug()<<QString::number(test1[i],16)<<"KKKKKKKKKKKKKKKKK";
//    }
//    uint8_t test2[4] = {0xa4,0x70,0xfd,0x3f};

//    float test3 = *(float*)(test2);
//     qDebug()<<test3;
    return a.exec();
}



