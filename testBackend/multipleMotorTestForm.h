#ifndef MULTIPLEMOTORTESTFORM_H
#define MULTIPLEMOTORTESTFORM_H

#include <QWidget>
#include "publicclass.h"
#include "define.h"
namespace Ui {
class multipleMotorTestForm;
}
enum COM_ID{
    A2 = 6,
    A3 = 5,
    A4 = 7,
    A8 = 8
};

class multipleMotorTestForm : public QWidget
{
    Q_OBJECT

public:
    explicit multipleMotorTestForm(QWidget *parent = nullptr);
    ~multipleMotorTestForm();
    void slotDataTest(QString,QString);
    void setValue(QString,int8_t,int32_t,int32_t);
private slots:
    //    void on_pushButton_start_clicked();

    //    void on_pushButton_stop_clicked();

    void on_pushButton_writeConfig_max_clicked();

    void on_pushButton_writeConfig_min_clicked();
signals:
    void signalValue_A2(int32_t duoquanvalue,int32_t danquanvalue);
    void signalValue_A3(int32_t duoquanvalue,int32_t danquanvalue);
    void signalValue_A4(int32_t duoquanvalue,int32_t danquanvalue);
    void signalValue_A8(int32_t duoquanvalue,int32_t danquanvalue);
private:
    Ui::multipleMotorTestForm *ui;
};

#endif // MULTIPLEMOTORTESTFORM_H
