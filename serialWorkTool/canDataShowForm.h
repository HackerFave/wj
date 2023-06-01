#ifndef CANDATASHOWFORM_H
#define CANDATASHOWFORM_H

#include <QWidget>
#include <QMainWindow>
#include "ControlCAN.h"
#include <QFile>
#include <QTimer>
#include <QLabel>
#include <QStandardItemModel>
#include <QMap>
#include "serialWorkThreadPool.h"
#include <QThreadPool>
#include <QSettings>
#include "canDataRecvThread.h"
#include "canDataSendThread.h"
#include <mutex>
#define LIMIT 1

const UCHAR Bsp[17][2]={{0x31,0x1C},{0x18,0x1C},{0x87,0xFF},{0x09,0x1C},{0x83,0xFF},
                        {0x04,0x1C},{0x03,0x1C},{0x81,0xFA},{0x01,0x1C},{0x80,0xFA},
                        {0x00,0x1C},{0x80,0xB6},{0x00,0x16},{0x00,0x14},{0x09,0x6F},
                        {0x04,0x6F},{0x03,0x6F}};

namespace Ui {
class canDataShowForm;
}
class canDataShowForm : public QWidget
{
    Q_OBJECT

public:
    explicit canDataShowForm(QWidget *parent = nullptr);
    ~canDataShowForm();
    void StartInit();
    QList<QStandardItem*> AddRowRecv(PVCI_CAN_OBJ Recv,QString *rowstr,short can);
    QList<QStandardItem*> AddRowSend(QString sendstr,uchar len,QString *rowstr);
    void SaveData2File(QFile *file,QString msg);
    double GetX();
private:
    void initThreadPool();
    void initThreadRS();
    void releaseThread();
    void startThreadPoll();
    void stopThreadPoll();
    void readShareMemary();
    QString getValue() const{
        return _value;
    }
    void setValue(QString value){
        _value = value;
    }
    void test();
private slots:
    void on_pushButton_open_clicked();

    void on_pushButton_send_clicked();

    void on_pushButton_cleanData_clicked();

    void on_pushButton_close_clicked();

    void on_checkBox_autoSend_clicked(bool checked);

    void on_checkBox_canrecv_clicked(bool checked);

    void on_checkBox_cansave_clicked(bool checked);

    void slotRealTimeUpdateMsg(/*UINT id, BYTE *data*/VCI_CAN_OBJ *data,  DWORD len,short can);//接收线程can回复数据

    void slotOpenCan(short);
signals:
    void signalDataToView(UINT id, BYTE *data);//天太电机波形展示
    void signalDataToForm(UINT id, BYTE *data);//rmd电机数据

//    void signalBmqDataToForm(QString,QString);
private:
    Ui::canDataShowForm *ui;
    QTimer *AutoSendTimer;
    uint SendCnt=0; //发送
    uint RecvCnt=0;
    DWORD m_DevType = 4;
    DWORD m_DevIndex =0;
    DWORD m_CanIndex;
    //    DWORD m_nDevType;
    QStandardItemModel *theModel;
    QString filename;
    QFile *file;
    double timeStamp=0;

//    QMap<int,baseThreadPool*> _threadMap;
    QThreadPool _pool;
    canDataRecvThread * P_canDataRecvThread_CAN1 = nullptr;//接收can报文
    canDataRecvThread * P_canDataRecvThread_CAN2 = nullptr;//接收can报文
    canDataSendThread * P_canDataSendThread = nullptr;//发送can报文
    QThread *P_ThreadRecv_CAN1 = nullptr;
    QThread *P_ThreadRecv_CAN2 = nullptr;
    QThread *P_ThreadSend = nullptr;
    QString  _value = 0;
    int _testNum = 0;
    int _lastDirection=0;
    std::mutex _mutex;
//    serialWorkThreadPool_BMQ * _threadPool_A2;
//    serialWorkThreadPool_BMQ * _threadPool_A3;
//    serialWorkThreadPool_BMQ * _threadPool_A4;
//    serialWorkThreadPool_BMQ * _threadPool_A8;

//    serialWorkThreadPool_XT_01 * _serialWorkThreadPool_XT_01;
//    serialWorkThreadPool_XT_02 * _serialWorkThreadPool_XT_02;
    serialWorkThreadPool_LX_603 * _serialWorkThreadPool_LX_603;
    serialWorkThreadPool_TT_601 * _serialWorkThreadPool_TT_601;
    serialWorkThreadPool_MT_141 * _serialWorkThreadPool_MT_141;
//    serialWorkThreadPool_MT_142 * _serialWorkThreadPool_MT_142;
//    serialWorkThreadPool_MT_143 * _serialWorkThreadPool_MT_143;
    serialWorkThreadPool_MT_145 * _serialWorkThreadPool_MT_145;
    serialWorkThreadPool_YK_602 * _serialWorkThreadPool_YK_602;//转向电机
    bool _isRelease = false;
};

#endif // CANDATASHOWFORM_H



