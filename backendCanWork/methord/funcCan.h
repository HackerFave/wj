#ifndef FUNCCAN_H
#define FUNCCAN_H

#include <QObject>
#include "ControlCAN.h"
#include <QThreadPool>
#include <QFile>
#include <QTimer>
#include <QSettings>
#include <QMap>
#include "thread/basethreadpool.h"
#include "thread/canDataRecvThread.h"
#include "thread/canDataSendThread.h"
#include "thread/messageReportThreadPool.h"
const UCHAR Bsp[17][2]={{0x31,0x1C},{0x18,0x1C},{0x87,0xFF},{0x09,0x1C},{0x83,0xFF},
                        {0x04,0x1C},{0x03,0x1C},{0x81,0xFA},{0x01,0x1C},{0x80,0xFA},
                        {0x00,0x1C},{0x80,0xB6},{0x00,0x16},{0x00,0x14},{0x09,0x6F},
                        {0x04,0x6F},{0x03,0x6F}};
class funcCan : public QObject
{
    Q_OBJECT
public:
    explicit funcCan(QObject *parent = nullptr);
    ~funcCan();
private:
    void initCan();
    void closeCan();
    void openCan();
    void initThread();
    void releaseThread();
public slots:
    void slotRecvCanMessage(VCI_CAN_OBJ *data,  DWORD len);//获取can回复报文
//    void slotTimerTest();//定时器正转
signals:

private:
    QMap<int,baseThreadPool*> _threadMap;
    QThreadPool _pool;
    canDataRecvThread * P_canDataRecvThread_CAN1 = nullptr;//接收can报文
    canDataRecvThread * P_canDataRecvThread_CAN2 = nullptr;//接收can报文
    canDataSendThread * P_canDataSendThread = nullptr;//发送can报文
    QThread *P_ThreadRecv_CAN1 = nullptr;
    QThread *P_ThreadRecv_CAN2 = nullptr;
    QThread *P_ThreadSend = nullptr;
    DWORD m_DevType = 4;
    DWORD m_DevIndex = 0;
    DWORD m_CanIndex = 1;
    DWORD m_nDevType;
//    QTimer  _timer ;
};

#endif // FUNCCAN_H
