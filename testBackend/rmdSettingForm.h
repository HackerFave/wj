#ifndef RMDSETTINGFORM_H
#define RMDSETTINGFORM_H

#include <QWidget>
#include <Windows.h>
#include "publicclass.h"
#include "ControlCAN.h"
#include <QTimer>
namespace Ui {
class rmdSettingForm;
}

class rmdSettingForm : public QWidget
{
    Q_OBJECT

public:
    explicit rmdSettingForm(QWidget *parent = nullptr);
    ~rmdSettingForm();
public slots:
    void slotRecvRmdData(UINT id, BYTE *data) ;
    void slotDataTest_A2(QString,int32_t,int32_t);
    //    void slotDataTest_A8(int32_t duo,int32_t dan);
    void slotWorkDataBMQA8(QString COM,int32_t duo,int32_t dan);
private slots:
    void on_pushButton_write_ram_clicked();

    void on_pushButton_write_rom_clicked();
    void on_checkBox_read_stateChanged(int arg1);
    void on_pushButton_write_jiasudu_clicked();

    void on_pushButton_write_0pian_clicked();

    void on_pushButton_clean_err_clicked();

    void on_pushButton_close_dianji_clicked();

    void on_pushButton_stop_dianji_clicked();

    void on_pushButton_start_dianji_clicked();

    void on_pushButton_write_1_clicked();

    void on_pushButton_zhuanjubihuan_clicked();

    void on_pushButton_sudubihuan_clicked();

    void on_pushButton_write_2_clicked();

    void on_pushButton_write_3_shun_clicked();

    void on_pushButton_write_3_ni_clicked();

    void on_pushButton_write_4_shun_clicked();

    void on_pushButton_write_4_ni_clicked();

    void on_pushButton_write_5_clicked();

    void on_pushButton_write_6_clicked();

    void on_pushButton_2_clicked();

    //    void slotUpdateTimer();

    //    void slotUpdateTimer_142();

    void slotUpdateTimer_143();

    void slotUpdateTimer_141();

    //    void slotUpdateTimer_145();

    void on_pushButton_3_clicked();

    //    void on_pushButton_142_clicked();

    void on_pushButton_143_clicked();

    //    void on_pushButton_145_clicked();

    //    void on_pushButton_stoptimer_clicked();

    void on_pushButton_stoptimer_clicked();

    void on_pushButton_141_clicked();

signals:
    void signalDisConnect(int);
private:
    Ui::rmdSettingForm *ui;
    int32_t _minValueDuo_A2 = 0;
    int32_t _minValueDan_A2 = 0;
    int32_t _maxValueDuo_A2 = 0;
    int32_t _maxValueDan_A2 = 0;
    bool _isNeedStopMachine_right_A2 = false;
    bool _isNeedStopMachine_left_A2 = false;

    int32_t _minValueDuo_A8 = 0;
    int32_t _minValueDan_A8 = 0;
    int32_t _maxValueDuo_A8 = 0;
    int32_t _maxValueDan_A8 = 0;
    int _flag = 0;
    //    QTimer _timer;
    //    QTimer _timer_142;
    QTimer _timer_143;
    QTimer _timer_141;
    //    QTimer _timer_145;
    uint64_t _value_142 =0;
    //    int  _flag = 0;
};

#endif // RMDSETTINGFORM_H
