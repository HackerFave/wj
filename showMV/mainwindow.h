//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H

//#include <QMainWindow>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

//class MainWindow : public QMainWindow
//{
//    Q_OBJECT

//public:
//    MainWindow(QWidget *parent = nullptr);
//    ~MainWindow();

//private:
//    Ui::MainWindow *ui;
//};
//#endif // MAINWINDOW_H


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "commondef.h"
#include "mediathread.h"
#include "ctopenglwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void Init();

private slots:
    void on_btn_play_clicked();

    void on_btn_open_clicked();

    void on_btn_play2_clicked();

    void on_btn_stop_clicked();

    void on_btn_record_clicked();

    void on_btn_snapshot_clicked();

    void on_btn_open_audio_clicked();

    void on_btn_close_audio_clicked();

    void on_btn_stop_record_clicked();

private:
    Ui::MainWindow *ui;
    MediaThread* m_pMediaThread = nullptr;
};

#endif // MAINWINDOW_H

