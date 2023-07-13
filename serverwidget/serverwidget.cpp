#include "serverwidget.h"
#include "ui_serverwidget.h"

serverwidget::serverwidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::serverwidget)
{
    ui->setupUi(this);
    tcpserver=nullptr;
    tcpsocket=nullptr;
    //创建监听套接字
    tcpserver=new QTcpServer(this);//指定父对象 回收空间

    //bind+listen
    tcpserver->listen(QHostAddress::Any,8888);//绑定当前网卡所有的ip 绑定端口 也就是设置服务器地址和端口号

    //服务器建立连接
    connect(tcpserver,&QTcpServer::newConnection,[=](){
        //取出连接好的套接字
        tcpsocket=tcpserver->nextPendingConnection();

        //获得通信套接字的控制信息
        QString ip=tcpsocket->peerAddress().toString();//获取连接的 ip地址
        quint16 port=tcpsocket->peerPort();//获取连接的 端口号
        QString temp=QString(QStringLiteral("[%1:%2] 客服端连接成功")).arg(ip).arg(port);
        //显示连接成功
        ui->textEditRead->setText(temp);

        //接收信息  必须放到连接中的槽函数 不然tcpsocket就是一个野指针
        connect(tcpsocket,&QTcpSocket::readyRead,[=](){
            //从通信套接字中取出内容
            QString str=tcpsocket->readAll();
             //在编辑区域显示
            ui->textEditRead->append(QStringLiteral("客户端：")+str);//不用settext 这样会覆盖之前的消息
        });
    });
}

serverwidget::~serverwidget()
{
    delete ui;
}

void serverwidget::on_buttonsend_clicked()
{
    if(tcpsocket==nullptr){
        return ;
    }
    //获取编辑区域的内容
    QString str=ui->textEditWrite->toPlainText();

    //写入通信套接字 协议栈自动发送
    tcpsocket->write(str.toUtf8().data());

    //在编辑区域显示
   ui->textEditRead->append(QStringLiteral("服务器端：")+str);//不用settext 这样会覆盖之前的消息
}

void serverwidget::on_buttonclose_clicked()
{
    //通信套接字主动与服务端断开连接
    tcpsocket->disconnectFromHost();//结束聊天

    //关闭 通信套接字
    tcpsocket->close();

    tcpsocket=nullptr;
}
