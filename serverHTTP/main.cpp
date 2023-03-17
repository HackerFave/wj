#include <QCoreApplication>
#include "httpMethord.h"
// Qt lib import
#include <QtCore>
#include <QImage>
#include <QJsonObject>
// JQLibrary import
#include "HttpServer.h"
#include "Net.h"

void startUp(const QPointer< HttpServer::Session > &session){
    const auto &&reply = Net::HTTP::get( "http://127.0.0.1:8001/api/request/startUp" );
    qDebug() << reply.first << reply.second;
     QJsonObject obj;
    if(reply.first){
        obj["code"] =0;
    }else{
        obj["code"] =-2;
        obj["msg"] ="time out";
    }
    session->replyJsonObject(obj);
}
void login(const QPointer< HttpServer::Session > &session){
    const auto &&reply = Net::HTTP::get( "http://127.0.0.1:8002/api/request/login" );
    qDebug() << reply.first << reply.second;
    QJsonObject obj;
   if(reply.first){
       obj["code"] =0;
   }else{
       obj["code"] =-2;
       obj["msg"] ="time out";
   }
   session->replyJsonObject(obj);
}
void startChat(const QPointer< HttpServer::Session > &session){
    QString targetId = session->requestUrlQuery()["targetId"];
    QString url = "http://127.0.0.1:8003/api/request/startChat?";
    url.append("targetId="+targetId);

    const auto &&reply = Net::HTTP::get(url);
    qDebug() << reply.first << reply.second;
    QJsonObject obj;
   if(reply.first){
       obj["code"] =0;
   }else{
       obj["code"] =-2;
       obj["msg"] ="time out";
   }
   session->replyJsonObject(obj);
}
void logoutLinkdood(const QPointer< HttpServer::Session > &session){

    QString token = session->requestUrlQuery()["token"];
    QString server = session->requestUrlQuery()["server"];
    QString url = "http://127.0.0.1:8004/api/request/logoutLinkdood?";
    url.append("token="+token);
    url.append("&server="+server);

    const auto &&reply = Net::HTTP::get(url);
    qDebug() << reply.first << reply.second;
    QJsonObject obj;
   if(reply.first){
       obj["code"] =0;
   }else{
       obj["code"] =-2;
       obj["msg"] ="time out";
   }
   session->replyJsonObject(obj);
}
void exitLinkdood(const QPointer< HttpServer::Session > &session){
    const auto &&reply = Net::HTTP::get( "http://127.0.0.1:8005/api/request/exitLinkdood" );
    qDebug() << reply.first << reply.second;
    QJsonObject obj;
   if(reply.first){
       obj["code"] =0;
   }else{
       obj["code"] =-2;
       obj["msg"] ="time out";
   }
   session->replyJsonObject(obj);
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 设置最大处理线程数
    HttpServer::TcpServerManage tcpServerManage( 10 );
    tcpServerManage.setHttpAcceptedCallback( []( const QPointer< HttpServer::Session > &session )
    {
        // 回调发生在新的线程内，不是主线程，请注意线程安全
        qDebug()/*<<Q_FUNC_INFO<<session->requestUrlPath()<<","<<session->requestBody()<<","*/
               <</*session->requestUrl()*/session->requestBody();
        if(session->requestUrlPath() == "/api/request/startUp"){
            startUp(session);
        }else if(session->requestUrlPath() == "/api/request/login"){
            login(session);
        }else if(session->requestUrlPath() == "/api/request/startChat"){
            startChat(session);
        }else if(session->requestUrlPath() == "/api/request/logoutLinkdood"){
            logoutLinkdood(session);
        }else if(session->requestUrlPath() == "/api/request/exitLinkdood"){
            exitLinkdood(session);
        }else{
            QJsonObject obj;
            obj["code"] = -1;
            obj["msg"] = "invalid url.";
            session->replyJsonObject(obj);
        }

    } );
    qDebug() << "listen:" << tcpServerManage.listen( QHostAddress::Any, 8080);

    return a.exec();
}
