#ifndef DATASHOWFORM_H
#define DATASHOWFORM_H

#include <QWidget>
#include <QStringList>
#include <stdint.h>
#include <QTimer>
#include <QThread>
#include <QMap>
#include <QThreadPool>
#include <QSharedMemory>
#include <QBuffer>
#include <QProcess>
#include <QtNetwork/QLocalServer>
#include <QtNetwork/QLocalSocket>
#include <QList>
#include "func.h"
#include "publicclass.h"
#include <QTimer>
#include <QTime>
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
    static void logOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    static void writeOutPut(const QString &str,QtMsgType type);
protected:
    //    virtual void mousePressEvent(QMouseEvent *event) override;
private slots:
    void on_pushButton_connect_clicked();
    void slotState(int err);
    void on_pushButton_send_clicked();
    void slotNewData(QByteArray data);
    //    void slotTimer();
    void on_pushButton_disconnect_clicked();
    //    void on_pushButton_sum_clicked();

    //    void on_pushButton_sum_2_clicked();

    //    void on_pushButton_sum_asc_clicked();

    void on_pushButton_shuaxin_clicked();

    void slotTimer();
    void slotBmqError();
    void slotBmq(int32_t,int32_t,int32_t);
    void slotTimerNum();
    void slotTimerMove();
signals:

private slots:
    void on_pushButton_write_jiasudu_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_weizhi_clicked();

    void on_pushButton_reboot_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_run_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_closeform_clicked();

    void on_pushButton_reset_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    uint16_t ModbusCRC16(QByteArray senddata);
    void initJasudu();
    void showOutPut(const QString &text);
private:
    Ui::dataShowForm *ui;
    QString _status;
    func * P_func = nullptr;
    QTimer _timer;
    QTime _time;
    //    QTimer _timerNum;
    bool _left = false;
    bool _right = false;
    bool _isInit = false;
    bool _isStop = false;
    int64_t _minbmq = 0;
    int64_t _maxbmq = 0;
    static dataShowForm * p_dataShowForm;
    int _timerC = 0;
    QTimer _timerMove;
    int _nummove = 0;
};

#endif // DATASHOWFORM_H
