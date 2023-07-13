#ifndef MESSAGEREPORTTHREADPOOL_H
#define MESSAGEREPORTTHREADPOOL_H

#include "basethreadpool.h"
#include "publicclass.h"
#include <QSharedMemory>
#include <QBuffer>
#include <QObject>
#include "define.h"
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

class messageReportThreadPool_TT_601 : public baseThreadPool
{
    Q_OBJECT
public:
    messageReportThreadPool_TT_601(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
    void setInitStatus(bool status);
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    int _id;
    bool _isStart = false;
    int _CanId;
    bool _initStatus = false;//电机上电初始化
};
class messageReportThreadPool_YK_602 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    messageReportThreadPool_YK_602(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    //    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
    int _CanId;
};
class MachineEnableThreadPool : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    enum ENABLE{

    };
    MachineEnableThreadPool(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void enableLX();
    void enableTT();
    void enableRmd141();
    void enableRmd145();
    void disenableLX();
    void disenableTT();
    void disenableRmd141();
    void disenableRmd145();
    void setStatusEnable(int32_t,bool);
public slots:
    virtual Q_INVOKABLE void slotWork() override;
private:
    bool _isStart = false;
    int _CanId;
    int _id;
    bool _isLXEnable = false;
    bool _isTTEnable = false;
    bool _isRmd141Enable = false;
    bool _isRmd145Enable = false;
};
#endif // SERIALWORKTHREADPOOL_H
