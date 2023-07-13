#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include "define.h"
#include <mutex>
#include <QProcess>
#include <queue>
#include <QQueue>
#include <QButtonGroup>
#include <mutex>
#include "backendcan.h"
#include "func.h"
#include "chassis.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    static void  call(/*UINT id, BYTE * data,int*/CAN_OBJ *data);
    static void  callbmq(std::string , int8_t,int32_t,int32_t);
    void initPoint();
    //    void setValue_YK(int32_t value);
    void setValue_bmq(std::string , int8_t,int32_t,int32_t);
    void setValue(int32_t value);
public slots:
    void slotRecvData(UINT id, BYTE *data);
private slots:
    void on_pushButton_zhengzhuan_clicked();

    void on_pushButton_fanzhuan_clicked();

    void on_pushButton_stop_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_radioButton_up_clicked();

    void on_radioButton_back_clicked();


    void on_pushButton_back_clicked();

    void on_pushButton_front_clicked();


signals:

private:
    Ui::Widget *ui;
    static Widget *P_stac;
    funcCan *_FUN ;
    static std::mutex _mutex;
    QProcess *_process_A2 ;

    QQueue<QString> _data485;
    QButtonGroup _groupBtn;
    std::mutex _mutex_A0;
    func *p_func = nullptr;
};
#endif // WIDGET_H




