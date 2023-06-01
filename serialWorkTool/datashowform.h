#ifndef DATASHOWFORM_H
#define DATASHOWFORM_H

#include <QWidget>
#include "methord/qserialwork.h"
#include <QStringList>
#include <stdint.h>
#include <QTimer>
#include <QThread>
#include <QMap>
#include "public/publicclass.h"
#include "serialWorkThreadPool.h"
#include <QThreadPool>
#include <QSharedMemory>
#include <QBuffer>
#include <QProcess>
#include <QtNetwork/QLocalServer>
#include <QtNetwork/QLocalSocket>
#include <QList>
#include "ControlCAN.h"
namespace Ui {
class dataShowForm;
}

struct dataBuf{
    uint8_t head[4];
    uint8_t scalHead;
    uint8_t body[100];
    uint8_t scalBody;
    uint32_t bodyLen;
};
struct productInfo{
    uint8_t driverName[20] ; //驱动名称
    uint8_t motorName[20] ; //电机名称
    uint8_t hardwareVersion ;//驱动硬件版本
    uint8_t firmwareVersion ; //固件版本
};
enum  data_type {
    data_u8 =1,
    data_u16,
    data_u32,
    data_u64,
    data_8,
    data_16,
    data_32,
    data_64

};
class dataShowForm : public QWidget
{
    Q_OBJECT

public:
    explicit dataShowForm(QWidget *parent = nullptr);
    ~dataShowForm();

    inline void setStatus(QString str)
    {
        _status = str;
    }
    inline QString getStatus() const
    {
        return _status;
    }
    void uinttoBytes(data_type type, QString arr);
public slots:
    void slotRecvMachineData(UINT id, BYTE *data);//电机数据
private slots:
    void on_pushButton_connect_clicked();
    void slotState(int err);
    void on_pushButton_send_clicked();
    void slotNewData(QByteArray data);
    //    void slotTimer();
    void on_pushButton_disconnect_clicked();
    void on_pushButton_sum_clicked();

    void on_pushButton_sum_2_clicked();

    void on_pushButton_sum_asc_clicked();

    void on_pushButton_shuaxin_clicked();

    void slot_new_connection();

    void slot_recv_data();//编码器数据

    void slotUpdateBmq();
signals:
    void signalStatus(QString);
    void signalDataTest(QString,QString);
    void signalBmqDataToForm(QString,QString);
    void signalBmqDataToForm_A2(QString,int32_t,int32_t);
    void signalBmqDataToForm_A3(QString,int32_t,int32_t);
    void signalBmqDataToForm_A4(QString,int32_t,int32_t);
    void signalBmqDataToForm_A8(QString,int32_t,int32_t);
    void signalBmqDataToForm_A1(QString,int32_t,int32_t);//零差云控603 编码器
    void signalBmqDataToForm01(QString,int32_t,int32_t);//鑫拓01 编码器
    void signalBmqDataToForm02(QString,int32_t,int32_t);//鑫拓02 编码器

    void signalMachineData_A2(int32_t &data);//麦塔智能 141
    void signalMachineData_A3(int32_t &data);//天太 601
    void signalMachineData_A4(int32_t &data);//麦塔智能145
    void signalMachineData_A8(int32_t &data);//麦塔智能143
    void signalMachineData_A1(int32_t &data);//零差云控603
    void signalMachineData_XT01(int32_t &data);//鑫拓01
    void signalMachineData_XT02(int32_t &data);//鑫拓02
private slots:
    //    void slotReadShareMemory();
    //    void on_pushButton_readMemory_clicked();
    //    void slotTest(QString data);
private:
    uint16_t ModbusCRC16(QByteArray senddata);
    void initServer();

    bool is_first_connect(QLocalSocket *newsocket);  //是否为首次连接

    void initThread();
    void exitProcess();
private:
    Ui::dataShowForm *ui;
    QSerialWork* P_Serial;
    QSerialPort *P_port;
    QString _status;
    //    QSharedMemory _sharememory;
    QProcess *_process_A2 ;
    QProcess *_process_A3 ;
    QProcess *_process_A4 ;
    QProcess *_process_A8 ;
    QLocalServer *m_server = nullptr;

    QList<QLocalSocket*> _local_sockets;

    QThreadPool _poolBMQ;

//    serialWorkThreadPool_BMQ_A2 * _serialWorkThreadPool_BMQ_A2;
//    serialWorkThreadPool_BMQ_A3 * _serialWorkThreadPool_BMQ_A3;
//    serialWorkThreadPool_BMQ_A4* _serialWorkThreadPool_BMQ_A4;
////    serialWorkThreadPool_BMQ_A8 * _serialWorkThreadPool_BMQ_A8;

//    serialWorkThreadPool_BMQ_A1 * _serialWorkThreadPool_BMQ_A1;

////    serialWorkThreadPool_BMQ_XT_1 * _serialWorkThreadPool_BMQ_XT_1;
////    serialWorkThreadPool_BMQ_XT_2 * _serialWorkThreadPool_BMQ_XT_2;


    QTimer _timerBmqRead;
    bool _isA2Start = false;
    bool _isA3Start = false;
    bool _isA4Start = false;
    bool _isA8Start = false;

    QString _A2="";
    QString _A3="";
    QString _A4="";
    QString _A8="";

};

#endif // DATASHOWFORM_H
