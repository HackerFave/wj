


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plctimerthread.h"
#include "plcthread.h"
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QString>
#include <QThread>
#include <QDebug>
#include "global.h"

#include <QModbusDataUnit>
#include <QModbusRtuSerialMaster>
#include <QModbusClient>
#include <QModbusReply>

#include <QSerialPort>
#include <QSerialPortInfo>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QThread *thread;
    PlcTimerThread *plcThread;

    QThread *qthreadPlc;
    PlcThread *plc;

signals:
    void sendSpinbox(int);
    void writeTor(QString);

private slots:
//    void on_pushButton_clicked();
//    void on_pushButton_2_clicked();
//    void on_pushButton_3_clicked();
//    void on_pushButton_4_clicked();
    void showTime(QString);
    void on_spinBox_valueChanged();
    void on_connectModbus_clicked();
    void on_searchPort_clicked();
    void on_writeT_clicked();

    void on_statusBar(const QString&);
    void on_change2Discon();
    void on_change2Con();
    void on_updateT(QString);
    void on_updateS(QString);




    void on_pushButton_start_clicked();
    void on_pushButton_mainThread_clicked();
    void on_pushButton_quitThread_clicked();
    void on_pushButton_intoThread_clicked();
};

#endif // MAINWINDOW_H

