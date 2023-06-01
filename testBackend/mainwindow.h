#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "sdk/backendcan.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void  call(UINT id, BYTE * data);
private slots:
    void slotRecv(UINT id, BYTE *data);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
