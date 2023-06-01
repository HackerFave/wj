#ifndef FUNCCAN_H
#define FUNCCAN_H

#include <QObject>
#include "ControlCAN.h"
#include <QThreadPool>
#include <QFile>
#include <QTimer>
#include <QSettings>
#include <QMap>
#include <functional>
#include <mutex>
#include "thread/basethreadpool.h"
#include "thread/canDataRecvThread.h"
#include "thread/canDataSendThread.h"
#include "thread/messageReportThreadPool.h"
#include "backendCan_global.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QSharedMemory>
#include <QBuffer>
#include <QDataStream>
#include <QtNetwork/QLocalServer>
#include <QtNetwork/QLocalSocket>
#include <QProcess>
#define QSERIALWORK_ERR_OK               0
#define QSERIALWORK_ERR_OPEN_SUCCESS     1
#define QSERIALWORK_ERR_OPEN_FAILED      2

using namespace std;
/*回调函数原型声明*/
using Func = std::function<void (UINT, BYTE *)>;
const UCHAR Bsp[17][2]={{0x31,0x1C},{0x18,0x1C},{0x87,0xFF},{0x09,0x1C},{0x83,0xFF},
                        {0x04,0x1C},{0x03,0x1C},{0x81,0xFA},{0x01,0x1C},{0x80,0xFA},
                        {0x00,0x1C},{0x80,0xB6},{0x00,0x16},{0x00,0x14},{0x09,0x6F},
                        {0x04,0x6F},{0x03,0x6F}};
class BACKENDCAN_EXPORT funcCan : public QObject
{
    Q_OBJECT
public:
    explicit funcCan(QObject *parent = nullptr);
    ~funcCan();
    bool writeData(std::string &id,std::string &data);//can报文
    void control(QString value);//控制底盘

    void regeditCallBack(Func fun);/*注册回调函数*/
private:
    void initCan();
    QSerialPort *initSerialPort();
    void initBmq();
    void closeCan();
    void openCan();
    void initThread();
    void releaseThread();
    void initServer();
    void exitProcess();
    void setBuf(UINT, BYTE *,int);
public slots:
    void slotRecvCanMessage(VCI_CAN_OBJ *data,  DWORD len,short can);//获取can回复报文
    void slotDataArrived();//485报文
    void slot_new_connection();

    void slot_recv_data();//编码器数据
    void slotUpdateBmq();
signals:
    void signalDataToForm(UINT id, BYTE *data);
    void signalBmqDataToForm_A2(QString,int32_t,int32_t);
    void signalBmqDataToForm_A3(QString,int32_t,int32_t);
    void signalBmqDataToForm_A4(QString,int32_t,int32_t);
    void signalBmqDataToForm_A8(QString,int32_t,int32_t);
private:
    QMap<int,baseThreadPool*> _threadMap;
    QThreadPool _pool;
    canDataRecvThread * P_canDataRecvThread_CAN1 = nullptr;//接收can报文
    canDataRecvThread * P_canDataRecvThread_CAN2 = nullptr;//接收can报文
    canDataSendThread * P_canDataSendThread = nullptr;//发送can报文
    QThread *P_ThreadRecv_CAN1 = nullptr;
    QThread *P_ThreadRecv_CAN2 = nullptr;
    QThread *P_ThreadSend = nullptr;
    DWORD m_nDevType;
    Func _fun;
    std::mutex _mutex;

    QSerialPort* _serialPort;

    QByteArray _buffer;
    QByteArray _com = "";
    QProcess *_process_A2 ;
    QProcess *_process_A3 ;
    QProcess *_process_A4 ;
    QProcess *_process_A8 ;
    QLocalServer *m_server = nullptr;

    QList<QLocalSocket*> _local_sockets;

    QThreadPool _poolBMQ;

    QTimer _timerBmqRead;
    bool _isA2Start = false;
    bool _isA3Start = false;
    bool _isA4Start = false;
    bool _isA8Start = false;

    QString _A2="";
    QString _A3="";
    QString _A4="";
    QString _A8="";

    UINT _ID;
    BYTE * _candata = nullptr ;
    int _datalength = 0;
};


#endif // FUNCCAN_H
