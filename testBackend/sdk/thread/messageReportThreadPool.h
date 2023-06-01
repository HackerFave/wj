#ifndef MESSAGEREPORTTHREADPOOL_H
#define MESSAGEREPORTTHREADPOOL_H

#include "basethreadpool.h"
#include "publicclass.h"
#include <QSharedMemory>
#include <QBuffer>
#include <QObject>
enum ID{
    ID_1 = 0X01,
    ID_2,
    ID_3,
    ID_4,
    ID_5
};

class messageReportThreadPool_MT_141 : public baseThreadPool
{
    Q_OBJECT
public:
    messageReportThreadPool_MT_141(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    int _id;
    bool _isStart = false;
    int _CanId;
};

class messageReportThreadPool_MT_142 : public baseThreadPool
{
    Q_OBJECT
public:
    messageReportThreadPool_MT_142(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    int _id;
    bool _isStart = false;
    int _CanId;
};
class messageReportThreadPool_MT_143 : public baseThreadPool
{
    Q_OBJECT
public:
    messageReportThreadPool_MT_143(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    int _id;
    bool _isStart = false;
    int _CanId;
};
class messageReportThreadPool_MT_145 : public baseThreadPool
{
    Q_OBJECT
public:
    messageReportThreadPool_MT_145(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    int _id;
    bool _isStart = false;
    int _CanId;
};
class messageReportThreadPool_LX_603 : public baseThreadPool
{
    Q_OBJECT
public:
    messageReportThreadPool_LX_603(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    int _id;
    bool _isStart = false;
    int _CanId;
};
class messageReportThreadPool_XT_01 : public baseThreadPool
{
    Q_OBJECT
public:
    messageReportThreadPool_XT_01(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    int _id;
    bool _isStart = false;
    int _CanId;
};
class messageReportThreadPool_XT_02 : public baseThreadPool
{
    Q_OBJECT
public:
    messageReportThreadPool_XT_02(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    int _id;
    bool _isStart = false;
    int _CanId;
};
//编码器读取线程
class serialWorkThreadPool_BMQ : public baseThreadPool
{
    Q_OBJECT
public:
    serialWorkThreadPool_BMQ(QString &COM);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
    void DataArrived();
    void slotReadShareMemory();
signals:
    void signalComData(QString data);
private:
    bool _isStart = false;
    QSharedMemory _sharememory;
    QString _COM_port;
};
class messageReportThreadPool_TT_602 : public baseThreadPool
{
    Q_OBJECT
public:
    messageReportThreadPool_TT_602(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    int _id;
    bool _isStart = false;
    int _CanId;
};
#endif // SERIALWORKTHREADPOOL_H
