#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLibrary>
#include <QDebug>

//C:\Qt\Qt5.14.2\5.14.2\msvc2017_64\bin\windeployqt.exe
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    recver.Subscribe("tcp/message/test_topic", CallBackFun);

}

MainWindow::~MainWindow()
{
    recver.UnSubscribe("tcp/message/test_topic");
    delete ui;
}

void MainWindow::CallBackFun(const char* topic, const void*payload, uint32_t len)
{
    printf("topic: %s\n", topic);
    auto msg = flatbuffers::GetRoot<Message>(payload);
    printf("timestamp: %lld\n", msg->timestamp());
    printf("name: %s\n", msg->node_name()->c_str());

    auto content = flatbuffers::GetRoot<MsgTest>(msg->data()->Data());
    printf("content result: %d\n", content->result());


    //     for(int i=0; i<content->array()->size(); i++)
    //     {
    //         printf("array id: %d\n", content->array()->Get(i)->id());
    //     }
}
