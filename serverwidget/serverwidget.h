#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include<QTcpServer>//监听套接字
#include<QTcpSocket>//通信套接字
QT_BEGIN_NAMESPACE
namespace Ui { class serverwidget; }
QT_END_NAMESPACE

class serverwidget : public QWidget
{
    Q_OBJECT

public:
    serverwidget(QWidget *parent = nullptr);
    ~serverwidget();
private slots:
    void on_buttonsend_clicked();

    void on_buttonclose_clicked();

private:
    Ui::serverwidget *ui;
    QTcpServer *tcpserver;
    QTcpSocket *tcpsocket;
};
#endif // SERVERWIDGET_H

//#ifndef SERVERWIDGET_H
//#define SERVERWIDGET_H

//#include <QWidget>
//#include<QTcpServer>//监听套接字
//#include<QTcpSocket>//通信套接字
//QT_BEGIN_NAMESPACE
//namespace Ui { class serverWidget; }
//QT_END_NAMESPACE

//class serverWidget : public QWidget
//{
//    Q_OBJECT

//public:
//    serverWidget(QWidget *parent = nullptr);
//    ~serverWidget();

//private slots:
//    void on_buttonsend_clicked();

//    void on_buttonclose_clicked();

//private:
//    Ui::serverWidget *ui;
//    //声明两种套接字
//    QTcpServer *tcpserver;
//    QTcpSocket *tcpsocket;
//};
//#endif // SERVERWIDGET_H
