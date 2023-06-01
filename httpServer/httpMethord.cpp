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
    m_tcpServer->listen(QHostAddress::Any, 8080);
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
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(sendMsg()));
}

void httpMethord::slotErrorStringSlot()
{
    qDebug() << m_tcpServer->errorString();
}

void httpMethord::slotSendMsg()
{
    QByteArray data = m_tcpSocket->readAll();
    QString m_requestInfo = data;
    m_SocketInfo += m_requestInfo;
    if (m_requestInfo.indexOf("=")>0)
    {
        qDebug() << m_SocketInfo;

        QStringList list = m_SocketInfo.split(QRegExp("[\r\n]"), QString::SkipEmptyParts);

        if (!list.empty())
        {
            QStringList headlist = QString(list[0]).split(QRegExp("[ ]"));
            QString m_requestMethod = headlist[0];

            qDebug() << m_requestMethod;
            QStringList paramList;
            QString params(headlist[1]);
            if (QString(headlist[1]).size()>1)
            {
                paramList = QString(headlist[1]).split("/");
                params = paramList[1];
            }
            if (m_requestMethod == "GET" && params[0] == '?')
            {
                params = params.mid(1);
                QStringList numsList = params.split('&');
                QVector<int> nums;
                foreach(QString s, numsList) {
                    nums.append(s.split('=')[1].toInt());
                };
                qDebug() << nums<<"XXXXXXXXXXXXXXXXXXXXXXXXX"<<params;
                int sum = SumNums(nums);

                QString contentStr = "<html>"
                                     "<head>"
                                     "<title>"
                                     "Hello"
                                     "</title>"
                                     "</head>"
                                     "<body>"
                                     "<h1>" + QString::number(sum) +
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
                    QStringList numsList = params.split('&');
                    QVector<int> nums;
                    foreach(QString s, numsList) {
                        nums.append(s.split('=')[1].toInt());
                    };
                    qDebug() << nums<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!";
                    int sum = SumNums(nums);
                    QJsonObject res;
                    res.insert("sum", QJsonValue(sum));
                    QJsonDocument documentJson(res);
                    QString strJson(documentJson.toJson(QJsonDocument::Compact));

                    QByteArray dataArray = documentJson.toJson();
                    //send msg
                    QString str = "HTTP/1.1 200 OK\r\n";
                    str.append("Server:nginx\r\n");
                    str.append("Content-Type:application/json;charset=UTF-8\r\n");
                    str.append("Connection:keep-alive\r\n");
                    str.append(QString("Content-Length:%1\r\n\r\n").arg(strJson.size()));
                    str.append(strJson);
                    m_tcpSocket->write(str.toStdString().c_str());
                }
                else
                {
                    params = list[list.size()-1];
                    QStringList numsList = params.split('&');
                    QVector<int> nums;
                    foreach(QString s, numsList) {
                        nums.append(s.split('=')[1].toInt());
                    };
                    qDebug() << nums<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
                    int sum = SumNums(nums);
                    QJsonObject res;
                    res.insert("sum", QJsonValue(sum));
                    QJsonDocument documentJson(res);
                    QString strJson(documentJson.toJson(QJsonDocument::Compact));

                    QByteArray dataArray = documentJson.toJson();
                    //send msg
                    QString str = "HTTP/1.1 200 OK\r\n";
                    str.append("Server:nginx\r\n");
                    str.append("Content-Type:application/json;charset=UTF-8\r\n");
                    str.append("Connection:keep-alive\r\n");
                    str.append(QString("Content-Length:%1\r\n\r\n").arg(strJson.size()));
                    str.append(strJson);
                    m_tcpSocket->write(str.toStdString().c_str());
                }

            }
        }
        m_SocketInfo = "";
    }

}
int httpMethord::SumNums(QVector<int> nums)
{
    int res = 0;
    foreach(int num, nums) {
        res += num;
    };
    return res;
}
