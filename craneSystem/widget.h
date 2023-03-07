#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QEvent>
#include <QKeyEvent>
#include "ui/baseForm.h"
#include "message/outputForm.h"
#include "ui/cameraDisplayForm.h"
#include "../dataInterFace/zmqmodule/thread/workThread.h"
#include "../dataInterFace/zmqmodule/thread/IPC_Thread.h"
#include "../dataInterFace/zmqmodule/product/dataSub.h"
#include "../ui/Interface/WgtFactory.h"
#include "../ui/widget/TestForm/testWgt.h"
#include "../sql/SqlMethod.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public baseForm
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void initUi();
    void initChildForm();
    static void logOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    static void writeOutPut(const QString &str,QtMsgType type);
    // 设置回调函数的函数
    static void CallbackFunc(const char* topic, const void*payload, uint32_t len);//数据接受函数、、

private slots:
    //    void slotActionOutput(bool);
    void slotSubTopicData(const void*,int ,const uint32_t &);
    void slotGetFromAny(ModuleDir moduleDir,int cmd,QVariant data);
private:
    Ui::Widget *ui;
    QMenuBar * _menuBar= nullptr;
    QMenu * _menuTest1=nullptr;
    QMenu * _menuTest2=nullptr;
    QMenu * _menuTest3=nullptr;
    static outputForm * _outputForm ;
    QAction *_actionOutputLog = nullptr;
    datax::Node _topicRecver;

    baseThread *_Pthread = nullptr;
    QThread * _q_thread = nullptr;
    baseThread *_IPC_thread = nullptr;
    QThread * _q_IPC_thread = nullptr;
    cameraDisplayForm *P_cameraDisplayForm = nullptr;
};
#endif // WIDGET_H
