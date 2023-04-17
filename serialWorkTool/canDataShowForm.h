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
#include "testDataThread.h"
#include "canDataSendThread.h"
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
    QList<QStandardItem*> AddRowRecv(PVCI_CAN_OBJ Recv,QString *rowstr);
    QList<QStandardItem*> AddRowSend(QString sendstr,uchar len,QString *rowstr);
    void SaveData2File(QFile *file,QString msg);
    double GetX();
private:
    void initThread();
    void releaseThread();

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

    void on_pushButton_init_clicked();

    void on_pushButton_foreward_clicked();

    void on_pushButton_reversal_clicked();

    void on_pushButton_enable_clicked();

    void on_pushButton_stopEnable_clicked();

    void slotTimerTest();//定时器正转
    void slotTimerTest1();//定时器反转
    void slotTimerTest2();
    void on_pushButton_setyuandian_clicked();

    void on_pushButton_enable_weizhimoshi_clicked();

    void on_pushButton_zhuandong_clicked();

    void slotRealTimeUpdateMsg(/*UINT id, BYTE *data*/VCI_CAN_OBJ *data,  DWORD len);//接收线程can回复数据
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_test_clicked();

    void on_pushButton_STOP_clicked();

    void on_pushButton_4_clicked();
signals:
    void signalDataToView(UINT id, BYTE *data);//天太电机波形展示
    void signalDataToRmdForm(UINT id, BYTE *data);//rmd电机数据
    void signalRecvId(QString num);
    void signalSendCanBuf(void *,int length);
private:
    Ui::canDataShowForm *ui;
    //    QTimer *mtimer;
    QTimer *AutoSendTimer;
    uint SendCnt=0; //发送
    uint RecvCnt=0;
    DWORD m_DevType;
    DWORD m_DevIndex;
    DWORD m_CanIndex;
    DWORD m_nDevType;
    QStandardItemModel *theModel;
    QString filename;
    QFile *file;
    double timeStamp=0;

    QMap<int,baseThreadPool*> _threadMap;
    QThreadPool _pool;
    testDataThread * P_testDataThread = nullptr;//接收can报文
    canDataSendThread * P_canDataSendThread = nullptr;//发送can报文
    QThread *P_ThreadRecv = nullptr;
    QThread *P_ThreadSend = nullptr;
    QString  _value = 0;
    QTimer * _timer = nullptr;
    QTimer * _timer1 = nullptr;
    QTimer * _timer2 = nullptr;
    int _testNum = 0;
    int _lastDirection=0;
};

#endif // CANDATASHOWFORM_H



