#ifndef LINGCHACANFORM_H
#define LINGCHACANFORM_H

#include <QWidget>
#include "ControlCAN.h"
#include "publicclass.h"
#include <QTimer>
namespace Ui {
class lingChaCanform;
}

class lingChaCanform : public QWidget
{
    Q_OBJECT

public:
    explicit lingChaCanform(QWidget *parent = nullptr);
    ~lingChaCanform();
public slots:
    void slotRecvLingChaData(UINT id, BYTE *data);
private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_disenable_clicked();
//    void on_pushButton_enable_clicked();

    void on_pushButton_sudu_clicked();

    void on_pushButton_xiangdui_clicked();

    void on_pushButton_juedui_clicked();



    void on_pushButton_lianxu_clicked();

    void slotTimer();
    void on_pushButton_ceshi_clicked();

    void on_pushButton_xiangduienable_clicked();

private:
    void  sportsMode_jueduiweizhi();
    void  sportsMode_xiangduiyundong();
    void  sportsMode_lianxuyundong();
    void  sportsMode_sudumoshi();
    void  sportsMode_lijumoshi();

private:
    Ui::lingChaCanform *ui;
    int32_t _valuemA=0;
    QTimer _testTimer;
    int32_t _bmq = 0;
};

#endif // LINGCHACANFORM_H
