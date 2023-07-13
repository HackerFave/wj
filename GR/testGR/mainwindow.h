#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "headgr.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void  call(TYPE_ID, int32_t);
private slots:
    void on_pushButton_run_clicked();
//    void on_pushButton_clicked();

    void on_pushButton_read_encoder_clicked();

    void on_pushButton_read_encoder_2_clicked();

    void on_pushButton_run_2_clicked();

    void on_pushButton_readacc_chuizhi_clicked();

    void on_pushButton_readacc_shuiping_clicked();

    void on_pushButton_write_clicked();

    void on_pushButton_clear_angle_clicked();

    void on_pushButton_clear_error_clicked();

private:
    void initPoint();
    void setCurrentAngle(TYPE_ID id,int32_t value);
private:
    Ui::MainWindow *ui;
    HeadGR * P_HeadGR = nullptr;
    static MainWindow *P_stac;
};
#endif // MAINWINDOW_H
