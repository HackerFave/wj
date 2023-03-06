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


    //qDebug()<<QSqlDatabase::drivers();//打印驱动列表
    //    QSqlDatabase db;
    //    //检测已连接的方式 - 默认连接名
    //    //QSqlDatabase::contains(QSqlDatabase::defaultConnection)
    //    if(QSqlDatabase::contains("qt_sql_default_connection"))
    //        db = QSqlDatabase::database("qt_sql_default_connection");
    //    else
    //        db = QSqlDatabase::addDatabase("QSQLITE");




    //    //检测已连接的方式 - 自定义连接名
    //    /*if(QSqlDatabase::contains("mysql_connection"))
    //            db = QSqlDatabase::database("mysql_connection");
    //        else
    //            db = QSqlDatabase::addDatabase("QSQLITE","mysql_connection");*/
    //    //设置数据库路径，不存在则创建
    //    db.setDatabaseName("tc.db");
    //    //db.setUserName("gongjianbo");  //SQLite不需要用户名和密码
    //    //db.setPassword("qq654344883");


    //    //打开数据库
    //    if(db.open()){
    //        createTable();
    //        qDebug()<<"open success";
    //        //关闭数据库
    ////        db.close();
    //    }

    SqlMethod::sqlmethod_instance()->getsqloperationinstance("test");

    //    sqlOperation *sql = new sqlOperation("0");
    //    QString str = "test";
    //    if (sql->Init("127.0.0.1", "root", "123456", "crane")) {
    //        qDebug()<<("初始化数据库成功!");  // \n表示换行<< point.toStdString().c_str() << ":" << "初始化数据库成功";

    //    }
    //    QMap<QString,QString> id;
    //    id["value"] = "VARCHAR(100)";
    //    id["data1"] = "VARCHAR(100)";
    //    id["data2"] = "VARCHAR(100)";
    //    sql->sql_create_table("mytable",id);
    //    QSqlQuery * ret = nullptr;
    //    std::string table_name = "testtable";

    //    std::map<std::string, std::string> map;
    //    map["id"] ="0";
    //    map["data1"] = "1";
    //    map["data2"] = "2";
    //    map["data3"] = "3";
    //    map["data4"] = "4";
    //    map["data5"] = "5";

    //    sql->Add(table_name, map, &ret);


    //    /*************************sqlite***********************/
    //    QString connectName = "root";
    //    QString DBname = "testdb";
    //    QString userName = "tc";
    //    QString passWord = "123456";
    //    sql->sql_create(connectName,DBname,userName,passWord);

    w.showMaximized();
    return a.exec();
}



