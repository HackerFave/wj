//#include "clientwidget.h"
//#include "ui_clientwidget.h"

//ClientWidget::ClientWidget(QWidget *parent)
//    : QWidget(parent)
//    , ui(new Ui::ClientWidget)
//{
//    ui->setupUi(this);
//}

//ClientWidget::~ClientWidget()
//{
//    delete ui;
//}

#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpsocket=nullptr;
    setWindowTitle(QStringLiteral("客户端"));

    tcpsocket=new QTcpSocket(this);
    connect(tcpsocket,&QTcpSocket::connected,[=](){
        ui->textEditRead->setText(QStringLiteral("服务器连接成功！"));
    });

    connect(tcpsocket,&QTcpSocket::readyRead,[=](){
       //获取通信套接字的内容
        QString str=tcpsocket->readAll();
        //在显示编辑区域显示
       ui->textEditRead->append(QStringLiteral("服务器端：")+str);//不用settext 这样会覆盖之前的消息
    });

}

ClientWidget::~ClientWidget()
{
    delete ui;
}


void ClientWidget::on_buttonconnect_clicked()
{
    if(nullptr==ui->lineEditIP || nullptr==ui->lineEditPort)
        return ;
    //获取IP地址和端口号
    QString IP=ui->lineEditIP->text();
    quint16 Port=ui->lineEditPort->text().toInt();

    //与服务器连接
    tcpsocket->connectToHost(IP,Port);
}

void ClientWidget::on_buttonsend_clicked()
{
    if(nullptr==tcpsocket)//连接失败则不发送
        return;

    //获取发送的信息
    QString str=ui->textEditWrite->toPlainText();

    //将信息写入到通信套接字
    tcpsocket->write(str.toUtf8().data());

    //将自己的信息显示在聊天窗口
    ui->textEditRead->append(QStringLiteral("客服端：")+str);//不用settext 这样会覆盖之前的消息
}


void ClientWidget::on_buttonclose_clicked()
{
    if(nullptr==tcpsocket)
        return;
    tcpsocket->disconnectFromHost();//断开与服务器的连接
    tcpsocket->close();//关闭通信套接字
}

