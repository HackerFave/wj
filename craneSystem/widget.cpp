#include "widget.h"
#include "ui_widget.h"
#include "base/webEngie.h"
#include <QtDebug>
#include <QMutex>
#include <mutex>
#include <QFile>
#include <QWindow>
#include <QLabel>
#include "define_zmqmodule.h"
#include "HCNetSDK.h"
#include "DecodeCardSdk.h"
#include "DataType.h"
#include "plaympeg4.h"

outputForm * Widget::_outputForm = nullptr ;

static QMutex mutex_q ;

Widget::Widget(QWidget *parent)
    : baseForm(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qInstallMessageHandler(logOutput);
    this->setWindowTitle("起重系统");

    initUi();
    _topicRecver.Subscribe(enumToOtherString(Topic_ID::TOPIC_TCP_MESSAGE_TEST_TOPIC_ENUM),
                           CallbackFunc);

    /***********数据回馈轮寻机制  **********/
    _Pthread = new workThread;
    _q_thread = new QThread;
    _Pthread->moveToThread(_q_thread);
    connect(_q_thread,SIGNAL(finished()),_Pthread,SLOT(deleteLater()));
    connect(_q_thread,SIGNAL(started()),_Pthread,SLOT(slotPostWork()));
    //    /***********启动IPC进程间通信  **********/
    _IPC_thread = new IPC_Thread;
    _q_IPC_thread = new QThread;
    _IPC_thread->moveToThread(_q_IPC_thread);//启动进程间通信IPC
    connect(_q_IPC_thread,SIGNAL(finished()),_IPC_thread,SLOT(deleteLater()));
    connect(_q_IPC_thread,SIGNAL(started()),_IPC_thread,SLOT(slotPostWork()));

    if(!_q_IPC_thread->isRunning()){//绑定IPC_PRO
        _q_IPC_thread->start();
    }

    initChildForm();
}

Widget::~Widget()
{
    _topicRecver.UnSubscribe(enumToOtherString(Topic_ID::TOPIC_TCP_MESSAGE_TEST_TOPIC_ENUM));
    if(_q_thread->isRunning())
    {
        _Pthread->stopWork();  //关闭线程槽函数
        _q_thread->quit();            //退出事件循环
        _q_thread->wait();            //释放线程槽函数资源
    }
    if(_q_IPC_thread->isRunning())
    {
        _IPC_thread->stopWork();  //关闭线程槽函数
        _q_IPC_thread->quit();            //退出事件循环
        _q_IPC_thread->wait();            //释放线程槽函数资源
    }
    delete ui;
}
void Widget::initUi()
{

    P_cameraDisplayForm = new cameraDisplayForm;
    ui->gridLayout_camera->addWidget(P_cameraDisplayForm);
    _menuBar = new QMenuBar;

    ui->horizontalLayout_menu->addWidget(_menuBar);
    _menuBar->setFixedHeight(30);
    _menuBar->setStyleSheet("QMenuBar{background-color:#c5c5c5;}"
                            "QMenuBar::selected{background-color:transparent;}"
                            "QMenuBar::item{font-size:12px;font-family:Microsoft YaHei;color:rgba(255,255,255,1);}");

    _menuTest1= new QMenu("测试1");

    _menuTest1->addAction(new QAction("1",this));
    _menuTest1->addSeparator();
    _menuTest1->addAction(new QAction("2",this));
    _menuTest1->addAction(new QAction("3",this));
    _menuTest2= new QMenu("测试2");
    _menuTest3= new QMenu("测试3");



    _menuBar->addMenu(_menuTest1);
    //    _menuBar->addSeparator();
    _menuBar->addMenu(_menuTest2);
    //    _menuBar->addSeparator();
    _menuBar->addMenu(_menuTest3);


    _outputForm = new outputForm;


    _actionOutputLog = new QAction("output");
    _outputForm = new outputForm;
    ui->gridLayout__output->addWidget(_outputForm);
    ui->gridLayout_4->addWidget(WgtFactory::getFunWidget(MD_TestForm));
    //    _menuTest1->addAction(_actionOutputLog);
    //    connect(_actionOutputLog,SIGNAL(triggered(bool)),this,SLOT(slotActionOutput(bool)));


}

void Widget::initChildForm()
{
    connect(this,SIGNAL(signalKeyEvent(ModuleDir,int ,QVariant)),this,SLOT(slotGetFromAny(ModuleDir,int,QVariant)));

    connect(WgtFactory::getFunWidget(MD_TestForm)->getCL(), SIGNAL(sendToMain(ModuleDir,int,QVariant)),
            this, SLOT(slotGetFromAny(ModuleDir,int,QVariant)));


}
void Widget::slotSubTopicData(const void*pyload,int id,const uint32_t &data)
{
    //    printf("topic: %s\n", topic);
    auto msg = flatbuffers::GetRoot<Message>(pyload);
    printf("timestamp: %lld\n", msg->timestamp());
    qDebug()<<"timestamp:"<<msg->timestamp();
    printf("name: %s\n", msg->node_name()->c_str());
    qDebug()<<"name:"<<msg->node_name()->c_str();
    auto content = flatbuffers::GetRoot<MsgTest>(msg->data()->Data());
    qDebug()<<"content result:"<< content->result();
}

void Widget::logOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{


    //    def update_log(self, text):
    //    """将日志输出到 text widget"""
    //    if not self.isVisible():
    //        return
    //    if "ERROR" in text: # 错误日志加粗
    //        text = f"<font color='red'><b>{text}</font><br>"
    //    elif "INFO" in text:
    //        text = f"<font color='green'>{text}</font><br>"
    //    elif "WARNING" in text:
    //        text = f"<font color='cyan'>{text}</font><br>"
    //    elif "DEBUG" in text:
    //        text = f"<font color='blue'>{text}</font><br>"
    //    else:
    //        text = f"{text}<br>"
    //    self.log_browser.setWordWrapMode(QTextOption.WordWrap)
    //    self.log_browser.moveCursor(QTextCursor.End)
    //    self.log_browser.insertHtml(text)
    //    self.log_browser.ensureCursorVisible()


    QString text;
    mutex_q.lock();

    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");//
        break;

    case QtWarningMsg:
        text = QString("Warning:");//警告
        break;

    case QtCriticalMsg:
        text = QString("Critical:"); //严重错误
        break;
    case QtInfoMsg:
        text = QString("info:");//提示信息
        break;
    case QtFatalMsg:
        text = QString("Fatal:");//致命错误
        break;
    }

    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);

    QString message = QString("{%1 %2 %3 %4}").arg(text).arg(context_info).arg(msg).arg(current_date);
    writeOutPut(message,type);


    QFile file("test.log");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex_q.unlock();
}
void Widget::writeOutPut(const QString &text,QtMsgType type)
{

    switch(type)
    {
    case QtDebugMsg:
        _outputForm->showOutPut(QString("<font color='green'><b>%1</font><br>").arg(text));
        break;
    case QtWarningMsg:
        _outputForm->showOutPut(QString("<font color='yellow'><b>%1</font><br>").arg(text));
        break;
    case QtCriticalMsg:
        _outputForm->showOutPut(QString("<font color='red'><b>%1</font><br>").arg(text));
        break;
    case QtInfoMsg:
        _outputForm->showOutPut(QString("<font color='green'><b>%1</font><br>").arg(text));
        break;
    case QtFatalMsg:
        _outputForm->showOutPut(QString("<font color='red'><b>%1</font><br>").arg(text));
        break;
    }


}

void Widget::CallbackFunc(const char* topic1, const void*payload, uint32_t len)//数据接受函数、、
{
    int id = enumFromString(std::string(topic1));

    qInfo()<<":"<<id<<":"<<topic1;
    if(id == TOPIC_TCP_MESSAGE_TEST_TOPIC_ENUM){
        auto msg = flatbuffers::GetRoot<Message>(payload);
        if(msg->data()&&msg->data()->Data()){
            //            uint8_t *data  = new uint8_t[1024];
            //            memcpy(data, msg->data()->Data(), len);
            //            P_dataSub->emitSignal(data,id,len);
            static int s = 0;
            qInfo()<<id<<"****************************"<<msg->data()->size()<<":"<<len<<":"<<s++;
        }

    }

}
void Widget::slotGetFromAny(ModuleDir moduleDir,int cmd,QVariant data)
{
    ModuleType Dir;
    Dir = static_cast<ModuleType>(moduleDir.first());
    IFunWidget *pFunWidget=WgtFactory::getFunWidget(Dir);
    if(pFunWidget == nullptr)
        return;
    qDebug()<<"recv cmd:" << cmd << " to:" <<pFunWidget->objectName();

    pFunWidget->getCL()->getFromAny(moduleDir,cmd,data);

}