#ifndef RMDSETTINGFORM_H
#define RMDSETTINGFORM_H

#include <QWidget>
#include <Windows.h>
#include "public/publicclass.h"
#include "ControlCAN.h"
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

signals:
    void signalDisConnect(int);
private:
    Ui::rmdSettingForm *ui;
};

#endif // RMDSETTINGFORM_H
