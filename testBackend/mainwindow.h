#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "backendcan.h"
#include "define.h"
#include <mutex>
#include <QProcess>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void  call(/*UINT id, BYTE * data,int*/CAN_OBJ *data);
    static void  callbmq(std::string , int8_t,int32_t,int32_t);
    void initPoint();
    void setValue_LX(int32_t value);
    void setValue_YK(int32_t value);
    void setValue_TT(uint32_t id,int32_t value);
    void setValue_RMD_141(int32_t valueencoder,int32_t valuespeed);
    void setValue_RMD_145(int32_t valueencoder,int32_t valuespeed);
    void setValue_bmq(std::string , int8_t,int32_t,int32_t);
private slots:
    void slotRecv(UINT id, BYTE *data);

    void on_pushButton_A4_clicked();

    void on_pushButton_A1_up_pressed();

    void on_pushButton_A1_up_released();

    void on_pushButton_A1_down_pressed();

    void on_pushButton_A1_down_released();

    void on_pushButton_A2_left_pressed();

    void on_pushButton_A2_left_released();

    void on_pushButton_A2_right_pressed();

    void on_pushButton_A2_right_released();

    void on_pushButton_A3_front_pressed();

    void on_pushButton_A3_front_released();

    void on_pushButton_A3_back_pressed();

    void on_pushButton_A3_back_released();

    void on_pushButton_A4_UP_pressed();

    void on_pushButton_A4_UP_released();

    void on_pushButton_DOWN_pressed();

    void on_pushButton_DOWN_released();


signals:
    void signalDataToForm_rmd_141(UINT id, BYTE *data);//rmd电机数据
    void signalDataToForm_rmd_145(UINT id, BYTE *data);//rmd电机数据
    void signalDataToForm_LX(UINT id, BYTE *data);//rmd电机数据
    void signalDataToForm_YK(UINT id, BYTE *data);//rmd电机数据
    void signalDataToForm_TT(UINT id, BYTE *data);//rmd电机数据
private:
    Ui::MainWindow *ui;
    static MainWindow *P_stac;
    funcCan *_FUN ;
    static std::mutex _mutex;
    QProcess *_process_A2 ;
};
#endif // MAINWINDOW_H
