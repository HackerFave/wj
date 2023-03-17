#include "httpMethord.h"
#include <QTcpServer>
#include <QDebug>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include "QAbstractSocket"
#include <QStringList>
httpMethord::httpMethord(QObject *parent) : QObject(parent)
{
    m_tcpServer = new QTcpServer(this);
    if(!m_tcpServer->listen(QHostAddress::Any, PORT))
    {

        qDebug() << "\nWeb服务未启动";
    }
    else
    {
        qDebug() << "\nWeb服务在端口8080等待客户端连接";
    }
    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnectionSlot()));
    connect(m_tcpServer, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(slotErrorStringSlot()));


}


httpMethord::~httpMethord()
{
    m_tcpServer->close();
}

void httpMethord::slotNewConnectionSlot()
{
    qDebug()<<"newConnection input!";
    m_tcpSocket = m_tcpServer->nextPendingConnection();
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotSendMsg()));
}

void httpMethord::slotErrorStringSlot()
{
    qDebug() << m_tcpServer->errorString();
}

void httpMethord::slotSendMsg()
{
    QByteArray data = m_tcpSocket->readAll();
    qDebug() <<QStringLiteral("[接收客户端数据:]")<<data;
    QString m_requestInfo = data;
    m_SocketInfo += m_requestInfo;
    //    qDebug() <<QStringLiteral("[接收客户端数据:]")<< m_requestInfo/*m_SocketInfo*/<<"";


    QMap<QString , QVariant> map;
    map["recv"]="successful";
    QJsonDocument doc = QJsonDocument::fromVariant(QVariant(map));
    QByteArray jba = doc.toJson();
    QString jsonString = QString(jba);

    //send msg
    QString str = "HTTP/1.1 200 OK\r\n";
    str.append("Server:nginx\r\n");
    str.append("Content-Type:application/json;charset=UTF-8\r\n");
    str.append("Connection:keep-alive\r\n");
    str.append(QString("Content-Length:%1\r\n\r\n").arg(jsonString.size()));
    str.append(jsonString);
    m_tcpSocket->write(str.toStdString().c_str());
    return ;

    if (!m_requestInfo.isEmpty())
    {
        QStringList list = m_SocketInfo/*m_requestInfo*/.split(QRegExp("[\r\n]"), Qt::SkipEmptyParts);

        if (list.size()>0)
        {
            QStringList headlist = QString(list[0]).split(QRegExp("[ ]"));

            QString m_requestMethod = headlist[0];//get / post


            qDebug() <<"[headlist:]"<< headlist; //获取get头部
            QStringList paramList;
            QString params(headlist[1]);
            if (QString(headlist[1]).size()>1)
            {
                paramList = QString(headlist[1]).split("/");
                params = paramList[1];
                qDebug() <<"[paramList:]"<< paramList; //获取get头部
            }
            if (m_requestMethod == "GET" && params[0] == '?')
            {
                params = params.mid(1);
                qDebug() <<"[data:]"<<params;
                QMap<QString , QVariant> map;
                map["recv"]="successful";
                QJsonDocument doc = QJsonDocument::fromVariant(QVariant(map));
                QByteArray jba = doc.toJson();
                QString jsonString = QString(jba);

                QString contentStr = "<html>"
                                     "<head>"
                                     "<title>"
                                     "Hello"
                                     "</title>"
                                     "</head>"
                                     "<body>"
                                     "<h1>" + QString("%1").arg(jsonString) +
                        "</h1>"
                        "</body>"
                        "</html>";

                //send msg
                QString str = "HTTP/1.1 200 OK\r\n";
                str.append("Server:nginx\r\n");
                str.append("Content-Type:text/html;charset=UTF-8\r\n");
                str.append("Connection:keep-alive\r\n");
                str.append(QString("Content-Length:%1\r\n\r\n").arg(contentStr.size()));
                str.append(contentStr);
                m_tcpSocket->write(str.toStdString().c_str());
            }

            if (m_requestMethod == "POST")
            {
                if (params[0] == '?')
                {
                    params = params.mid(1);
                    //                    QStringList numsList = params.split('&');
                    qDebug() <<"[data:]"<< params; //获取get头部
                    QMap<QString , QVariant> map;
                    map["recv"]="successful";
                    QJsonDocument doc = QJsonDocument::fromVariant(QVariant(map));
                    QByteArray jba = doc.toJson();
                    QString jsonString = QString(jba);

                    //send msg
                    QString str = "HTTP/1.1 200 OK\r\n";
                    str.append("Server:nginx\r\n");
                    str.append("Content-Type:application/json;charset=UTF-8\r\n");
                    str.append("Connection:keep-alive\r\n");
                    str.append(QString("Content-Length:%1\r\n\r\n").arg(jsonString.size()));
                    str.append(jsonString);
                    m_tcpSocket->write(str.toStdString().c_str());
                }
                else
                {
                    params = list[list.size()-1];
                    qDebug() <<"[data:]"<< params; //获取post头部
                    QMap<QString , QVariant> map;
                    map["recv"]="successful";
                    QJsonDocument doc = QJsonDocument::fromVariant(QVariant(map));
                    QByteArray jba = doc.toJson();
                    QString jsonString = QString(jba);

                    //send msg
                    QString str = "HTTP/1.1 200 OK\r\n";
                    str.append("Server:nginx\r\n");
                    str.append("Content-Type:application/json;charset=UTF-8\r\n");
                    str.append("Connection:keep-alive\r\n");
                    str.append(QString("Content-Length:%1\r\n\r\n").arg(jsonString.size()));
                    str.append(jsonString);
                    m_tcpSocket->write(str.toStdString().c_str());
                }

            }
        }
        m_SocketInfo = "";
    }

}


void httpMethord::slotconnection()
{
    m_tcpSocket = m_tcpServer->nextPendingConnection();

    while (!(m_tcpSocket->waitForReadyRead(100))); //等待从浏览器读取数据

    char webBrowerRXData[1000];
    int sv = m_tcpSocket->read(webBrowerRXData, 1000);
    qDebug() << "正在从浏览器读取数据=" << QString(webBrowerRXData);

    m_tcpSocket->write("HTTP/1.1 200 OK\r\n");       // \r needs to be before   \n
    m_tcpSocket->write("Content-Type: text/html\r\n");
    m_tcpSocket->write("Connection: close\r\n");
    m_tcpSocket->write("Refresh: 1\r\n\r\n");        //refreshes web brower   every second.Request

    m_tcpSocket->write("<!DOCTYPE>"
                  "<html>"
                  "<header>"
                  "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />"
                  "<title>测试Qt HttpServer</title>"
                  "</header>"
                  "<body>已连接秒数：");
    QByteArray str;
    static qint16 count;    //用于在浏览器上显示的统计数字
    str.setNum(count++);
    m_tcpSocket->write(str);
    m_tcpSocket->write("</body>"
                  "</html>");

    m_tcpSocket->flush();
    connect(m_tcpSocket, &QTcpSocket::disconnected, m_tcpSocket, &QTcpSocket::deleteLater);
    m_tcpSocket->disconnectFromHost();

}
