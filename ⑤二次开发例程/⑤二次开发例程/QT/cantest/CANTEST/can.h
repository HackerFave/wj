#ifndef CAN_H
#define CAN_H
#include <QThread>
#include <iostream>
#include <QDebug>
#include <QLibrary>
#include <QTimer>
#include <QObject>
#include "ui_ctrlobj.h"
#include <QMessageBox>
#include "ECanVci.h"


class Thread : public QThread   //用户自定义的类
{
    Q_OBJECT
public:
    Thread();//构造函数//初始化变量
    void stop();

    void OpenCANThread(byte baud);
    void CloseCANThread();

    void ReceiveCANThread();
    void TransmitCANThread(unsigned int id, unsigned char *ch,bool EXT,bool RTR, unsigned int len);

public:
    typedef DWORD(__stdcall OpenDevice)(DWORD,DWORD,DWORD);
    typedef DWORD(__stdcall ResetCAN)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef DWORD(__stdcall CloseDevice)(DWORD DeviceType,DWORD DeviceInd);
    typedef DWORD(__stdcall InitCAN)(DWORD DeviceType, DWORD DeviceInd, DWORD CANInd, P_INIT_CONFIG pInitConfig);
    typedef DWORD(__stdcall StartCAN)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef ULONG(__stdcall Transmit)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_CAN_OBJ pSend,ULONG Len);

    typedef ULONG(__stdcall Receive)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_CAN_OBJ pReceive,ULONG Len,INT WaitTime/*=-1*/);
    typedef ULONG(__stdcall GetReceiveNum)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef DWORD(__stdcall ClearBuffer)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);
    typedef DWORD(__stdcall ReadErrInfo)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_ERR_INFO pErrInfo);
    typedef DWORD(__stdcall ReadCANStatus)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,P_CAN_STATUS pCANStatus);
    typedef DWORD(__stdcall SetReference)(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,DWORD RefType,PVOID pData);
    typedef DWORD(__stdcall ReadBoardInfo)(DWORD DeviceType,DWORD DeviceInd,P_BOARD_INFO pInfo);

    int devtype=4;//设备类型号//
    int devind=0; //设备索引号
    int res;    //保留参数，通常为0
    int canind=0; //第几路can
    int reftype;//参数类型
    bool musbcanstart; //是否打开设备
//Widget *ui;

protected:
    //QThread类的虚函数//就是子线程处理函数
    void run();//子线程处理函数//不能直接调用该函数//只能通过start间接调用

private:

    volatile bool stopped;

    OpenDevice *pOpenDevice;
    ResetCAN *pResetCAN;
    CloseDevice *pCloseDevice;
    InitCAN *pInitCAN;
    StartCAN *pStartCAN;
    Transmit *pTransmitCAN;
    Receive *pReceive;
    GetReceiveNum *pGetReceiveNum;
    ClearBuffer *pClearBuffer;
    ReadErrInfo *pReadErrInfoCAN;
    ReadCANStatus *pReadCANStatus;
    SetReference *pSetReference;
    ReadBoardInfo *pReadBoardInfo;

signals:
    void my_signal(QString str);//信号函数
};

#endif // CAN_H
