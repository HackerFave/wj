#ifndef BASEPRODUCT_H
#define BASEPRODUCT_H

#include <QObject>
class baseProduct : public QObject
{
    Q_OBJECT
public:
    explicit baseProduct(QObject *parent = nullptr);
    //    virtual Q_INVOKABLE void dataDoWork()=0;
    //    virtual Q_INVOKABLE void settingData() = 0;
    //    virtual Q_INVOKABLE QString settigData(QString str1, QString str2) = 0;
    virtual Q_INVOKABLE void initPoint()=0;
signals:
    Q_INVOKABLE void signalChangeState(int,int,int);
    Q_INVOKABLE void signalSubTopicDataChild(const void*,int id,const uint32_t &len);//数据发送信号 sub
    Q_INVOKABLE void signalPostTopicDataChild(const void*,size_t,int );//接受hmi post
    Q_INVOKABLE void signalPostStartThread();//启动监测线程
    Q_INVOKABLE void signalPostAppendData(const void *payload, size_t payload_len,int id);//启动监测线程后推送数据
public slots:
    //    virtual Q_INVOKABLE void slotChangeState(int,int ,int) = 0;
    virtual Q_INVOKABLE void slotPostTopicDataChild(const void*,size_t,int ){};
};

#endif // BASEPRODUCT_H
