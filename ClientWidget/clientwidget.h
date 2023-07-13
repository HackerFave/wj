//#ifndef CLIENTWIDGET_H
//#define CLIENTWIDGET_H

//#include <QWidget>

//QT_BEGIN_NAMESPACE
//namespace Ui { class ClientWidget; }
//QT_END_NAMESPACE

//class ClientWidget : public QWidget
//{
//    Q_OBJECT

//public:
//    ClientWidget(QWidget *parent = nullptr);
//    ~ClientWidget();

//private:
//    Ui::ClientWidget *ui;
//};
//#endif // CLIENTWIDGET_H


#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include<QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWidget; }
QT_END_NAMESPACE

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void on_buttonconnect_clicked();

    void on_buttonsend_clicked();

    void on_buttonclose_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket *tcpsocket;//声明套接字 客户端只有一个通信套接字
};
#endif // CLIENTWIDGET_H

