#ifndef DATASHOWFORM_H
#define DATASHOWFORM_H

#include <QWidget>
#include "methord/qserialwork.h"
#include <QStringList>
#include <stdint.h>
#include <QTimer>
#include <QThread>
#include <QMap>
//#include "serialWorkThreadPool.h"
#include <QThreadPool>
#include "public/publicclass.h"
//#include "testDataThread.h"
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

signals:
    void signalStatus(QString);
private:
    uint16_t ModbusCRC16(QByteArray senddata);
private:
    Ui::dataShowForm *ui;
    QSerialWork* P_Serial;
    QString _status;
//    QMap<int,baseThreadPool*> _threadMap;
//    QThreadPool _pool;
//    testDataThread * P_testDataThread = nullptr;
//    QThread *P_Thread = nullptr;
};

#endif // DATASHOWFORM_H
