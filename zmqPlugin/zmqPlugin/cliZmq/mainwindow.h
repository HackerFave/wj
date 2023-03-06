#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "node.h"
#include "test_generated.h"
#include "message_generated.h"
#include "zmq_wrapper.h"
#include "zmq_server.h"
#include "zmq_client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void CallBackFun(const char* topic, const void*payload, uint32_t len);
private:
    Ui::MainWindow *ui;
    datax::Node recver;
};
#endif // MAINWINDOW_H
