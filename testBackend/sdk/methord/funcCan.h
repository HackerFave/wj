#ifndef FUNCCAN_H
#define FUNCCAN_H

#include <QObject>
#include "define.h"
#include <QThreadPool>
#include <QFile>
#include <QTimer>
#include <QSettings>
#include <QMap>
#include <functional>
#include <mutex>
#include "basethreadpool.h"
#include "canDataRecvThread.h"
#include "canDataSendThread.h"
#include "messageReportThreadPool.h"
#include "backendCan_global.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QSharedMemory>
#include <QBuffer>
#include <QDataStream>
#include <QtNetwork/QLocalServer>
#include <QtNetwork/QLocalSocket>
#include <QProcess>
#include "define.h"

#define QSERIALWORK_ERR_OK               0
#define QSERIALWORK_ERR_OPEN_SUCCESS     1
#define QSERIALWORK_ERR_OPEN_FAILED      2

using namespace std;
/*回调函数原型声明*/
//using Func = std::function<void (UINT, BYTE *,int)>;
#if CANDEV_CX
using Func = std::function<void (VCI_CAN_OBJ *)>;
#endif
#if CANDEV_GC
using Func = std::function<void (CAN_OBJ *)>;
using FuncBmq = std::function<void (std::string, int8_t ,int32_t,int32_t)>;
#endif
const UCHAR Bsp[17][2]={{0x31,0x1C},{0x18,0x1C},{0x87,0xFF},{0x09,0x1C},{0x83,0xFF},
                        {0x04,0x1C},{0x03,0x1C},{0x81,0xFA},{0x01,0x1C},{0x80,0xFA},
                        {0x00,0x1C},{0x80,0xB6},{0x00,0x16},{0x00,0x14},{0x09,0x6F},
                        {0x04,0x6F},{0x03,0x6F}};
class BACKENDCAN_EXPORT funcCan : public QObject
{
    Q_OBJECT
public:
    enum ID{
        LX = 0X643,
        TT = 0X601,
        RMD_A2 = 0X141,
        RMD_A4 = 0X145
    };
    explicit funcCan(QObject *parent = nullptr);
    ~funcCan();
    void control(QString value);//控制底盘
    void regeditCallBack(Func fun);/*注册回调函数*/
    void regeditCallBack(FuncBmq fun);/*注册回调函数*/
    void controlMachine(ID id,int32_t angle);
    void setRmdAcceleration(ID id,int32_t acc);//设置加速度
    void stopRmd(uint16_t id);
    void stopTT();
    void stopLX();

    /**********转向电机**********/
    void turnMove(int32_t value);
private:
    void initCan();
    void initBmq();
    void closeCan();
    void initThread();
    void releaseThread();
    void initServer();
    void exitProcess();
#if CANDEV_CX
    void setBuf(/*UINT, BYTE *,int*/VCI_CAN_OBJ *);
#endif
#if CANDEV_GC
    void setBuf(CAN_OBJ *);
    void setBmqBuf(std::string, int8_t ,int32_t,int32_t);
    void doBuf(CAN_OBJ *);
#endif
public slots:
    void slotRecvCanMessage(void *data,  DWORD len,short can);//获取can回复报文
    void slotResetCan();//重置can盒，长时间运行会掉线
    void slot_new_connection();

    void slot_recv_data();//编码器数据
    void slotUpdateBmq();
signals:
private:
    QMap<int,baseThreadPool*> _threadMap;
    QThreadPool _pool;
    canDataRecvThread * P_canDataRecvThread_CAN1 = nullptr;//接收can报文
    canDataRecvThread * P_canDataRecvThread_CAN2 = nullptr;//接收can报文
    canDataSendThread * P_canDataSendThread = nullptr;//发送can报文
    QThread *P_ThreadRecv_CAN1 = nullptr;
//    QThread *P_ThreadRecv_CAN2 = nullptr;
//    QThread *P_ThreadSend = nullptr;
    DWORD m_nDevType;
    Func _fun;
    FuncBmq _funBmq;
    std::mutex _mutex;

    QSerialPort* _serialPort;

    QByteArray _com = "";
    QProcess *_process;
    QLocalServer *m_server = nullptr;

    QList<QLocalSocket*> _local_sockets;

    QThreadPool _poolBMQ;

    QTimer _timerBmqRead;
//    bool _isA0Start = false;
    bool _isA2Start = false;
    bool _isA3Start = false;
    bool _isA4Start = false;

//    QString _A0="";
    QString _A2="";
    QString _A3="";
    QString _A4="";

//    int32_t _A0maxBmq=0;
//    int32_t _A0minBmq=0;
    int32_t _A1maxBmq=0;
    int32_t _A1minBmq=0;
    int32_t _A2maxBmq=0;
    int32_t _A2minBmq=0;
    int32_t _A3maxBmq=0;
    int32_t _A3minBmq=0;
    int32_t _A4maxBmq=0;
    int32_t _A4minBmq=0;

    UINT _ID;
    BYTE * _candata = nullptr ;
    int _datalength = 0;
//    int32_t _currentA0Bmq = 0;
    int32_t _currentA1Bmq = 0;
    int32_t _currentA3Bmq = 0;
    int32_t _currentA2Bmq = 0;
    int32_t _currentA4Bmq = 0;
    int16_t _valueSpeed601 = 0;
    int16_t _valueSpeed603 = 0;
    int16_t _valueSpeed141 = 0;
    int16_t _valueSpeed145 = 0;
    int16_t _isLimit = 0;


};


#endif // FUNCCAN_H
