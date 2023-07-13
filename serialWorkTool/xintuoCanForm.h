#ifndef XINTUOCANFORM_H
#define XINTUOCANFORM_H

#include <QWidget>
#include "ControlCAN.h"
#include "public/publicclass.h"
#include <QTimer>
namespace Ui {
class xintuoCanForm;
}

class xintuoCanForm : public QWidget
{
    Q_OBJECT

public:
    explicit xintuoCanForm(QWidget *parent = nullptr);
    ~xintuoCanForm();
public slots:
    void slotRecvxintuoData(UINT id, BYTE *data);
    void slotTimer();
    void slotWorkDataBMQ01(QString COM,int32_t duo,int32_t dan);//01 编码器
    void slotWorkDataBMQ02(QString COM,int32_t duo,int32_t dan);//02 编码器
private slots:
    void on_pushButton_0x80_clicked();

    void on_pushButton_0x81_clicked();

    void on_pushButton_0x82_clicked();

    void on_pushButton_0x9C_clicked();

    void on_pushButton_0x9B_clicked();

    void on_pushButton_0x86_clicked();

    void on_pushButton_0x87_clicked();

    void on_pushButton_0x88_clicked();

    void on_pushButton_0x89_clicked();

    void on_pushButton_0x8f_clicked();

    void on_pushButton_0x91_clicked();

    void on_pushButton_0x92_clicked();

    void on_pushButton_0x93_clicked();

    void on_pushButton_0x94_clicked();

    void on_pushButton_0x95_clicked();

    void on_pushButton_0x99_clicked();

    void on_pushButton_test_clicked();

    void on_pushButton_stop_test_clicked();

private:
    Ui::xintuoCanForm *ui;
    QTimer _timerTest;

    uint32_t _value1 = 0;
    uint32_t _value2 = 0;

    int32_t _minValueDan_BMQ_XT_1 = 0;
    int32_t _minValueDan_BMQ_XT_2 = 0;
    int32_t _maxValueDan_BMQ_XT_1 = 0;
    int32_t _maxValueDan_BMQ_XT_2 = 0;
    QString _valuemsg = "";
};

#endif // XINTUOCANFORM_H
