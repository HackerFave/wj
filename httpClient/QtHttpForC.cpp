#include "QtHttpForC.h"
#include "ui_QtHttpForC.h"
#include <QButtonGroup>
#include <QTcpSocket>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include "QByteArray"
#include "httpMethord.h"
QtHttpForC::QtHttpForC(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QtHttpForC)
{
    ui->setupUi(this);
    m_Buttongroup = new QButtonGroup(this);
    m_Buttongroup->addButton(ui->radioButton, 1);
    m_Buttongroup->addButton(ui->radioButton_2, 2);
    m_Buttongroup->addButton(ui->radioButton_curl_post, 3);
    m_Buttongroup->addButton(ui->radioButton_curl_get, 4);

    ui->textEdit_addr->setText("127.0.0.1");
    ui->textEdit_port->setText("8080");
    m_Socket = new QTcpSocket();
}

QtHttpForC::~QtHttpForC()
{
    delete ui;
}

void QtHttpForC::on_pushButton_clicked()
{
    m_Socket->abort();
    qDebug() << "Connetting....";
    QNetworkRequest request;
    QString scheme = "http";
    QString serverAddr = ui->textEdit_addr->toPlainText();
    QString port = ui->textEdit_port->toPlainText();
    QString requestHeader = scheme + QString("://") + serverAddr + QString(":") + port;

    qDebug()<<requestHeader<<"";
    if (m_Buttongroup->checkedId() == 1)
    {//post 返回
        //获取对应的参数数据
        QByteArray data;
//        data.append("a=");
//        data.append(ui->textEdit_parm_1->toPlainText().toUtf8());
//        data.append("&b=");
//        data.append(ui->textEdit_parm_2->toPlainText().toUtf8());

        data.append("UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU");
        /************************请求**********************/
        //        std::cout<<"[生成CSR成功]"<<ret<<std::endl;
        //                std::string host = "http://192.168.30.137:8660/api/v1/certificate?";
        //                std::string user = "userId=123456&csr1=";
        //                std::string strURL = host+user+csr;
        //                string strResponse;
        //                CURLcode nRes = httpMethord::HttpGet(strURL, strResponse,300);


        QNetworkAccessManager manager;
        request.setUrl(QUrl(requestHeader));
        request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

        QNetworkReply *reply = manager.post(request, data);
        QEventLoop eventLoop;
        QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
        eventLoop.exec(QEventLoop::ExcludeUserInputEvents);
        //对请求的返回异常进行处理
        QByteArray replyData = reply->readAll();
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << reply->error();
            delete m_Socket;
        }
        ui->textEdit_res->setText(QString(replyData));
//        reply->deleteLater();

    }
    else if( m_Buttongroup->checkedId() == 2)
    { //get 请求
        //        QString fullRequest = requestHeader + QString("/?a=%1&b=%2")
        //                .arg(ui->textEdit_parm_1->toPlainText().toInt())
        //                .arg(ui->textEdit_parm_2->toPlainText().toInt());
        //        request.setUrl(QUrl(fullRequest));
        QByteArray data;
        data.append("aaaaaaaaaaaaaa");
        data.append("bbbbbbbbbbbbbbbbb");
        QString fullRequest = requestHeader +"/?"+data;
        request.setUrl(QUrl(fullRequest));
        QNetworkAccessManager manager;
        QNetworkReply *reply = manager.get(request);
        QEventLoop eventLoop;
        QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
        eventLoop.exec(QEventLoop::ExcludeUserInputEvents);
        //对请求的返回异常进行处理
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << reply->error();
            delete m_Socket;
        }
        QByteArray replyData = reply->readAll();
        ui->textEdit_res->setText(QString(replyData+"*******************"));
        reply->deleteLater();
    }
    else if (m_Buttongroup->checkedId() == 3) {
        std::string strResponse;
        std::string host = "http://127.0.0.1:8080";
        std::string json = "{---------post--------------}";
        CURLcode nRes = httpMethord::HttpPost(host, json,strResponse,300);

    }else {
        std::string strResponse;
        std::string host = "http://127.0.0.1:8080?----------------------";
        std::string json = "{----------get-------------}";
        CURLcode nRes = httpMethord::HttpGet(host, strResponse,300);
    }
}
