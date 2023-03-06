#include "testWgt.h"
#include "ui_testWgt.h"
#include <QScreen>
#include <QVBoxLayout>
#include <QDebug>
#include <QVBoxLayout>
#include <QWebEngineView>
testWgt* testWgt::s_pInstance = nullptr; //初始化静态数据成员
testWgt::testWgt(QWidget *parent) :
    IFunWidget(parent),
    ui(new Ui::testWgt)
{
    ui->setupUi(this);
    m_pCL = new testCl();
    m_pCL->doInit();
    this->setCL(m_pCL);

    m_pModel = new testModel();
    this->setModel(m_pModel);
    m_pCL->setModel(m_pModel);
}

testWgt::~testWgt()
{
    delete ui;
    delete m_pCL;
    delete m_pModel;
}

testWgt *testWgt::GetInstance()
{
    if(s_pInstance == nullptr) {
        s_pInstance = new testWgt();
    }
    return s_pInstance ;
}

void testWgt::resizeEvent(QResizeEvent *event)
{
    QScreen *pScreen = QGuiApplication::primaryScreen();

}

void testWgt::initWidget()
{
    //    qInfo()<<"CloudWebWgt::initWidget";
    m_pCL->intoAction();
    this->updateWidget();
}

bool testWgt::isQuit()
{
    //    qInfo()<<"CloudWebWgt::isQuit";
    m_pCL->exitAction();
    return true;
}

void testWgt::updateWidget()
{
    //    qInfo()<<"CloudWebWgt::updateWidget"<<m_pModel->m_url;
    //    m_pWeb->load(m_pModel->m_url);
    this->update();
}

//void testWgt::keyPressEvent(QKeyEvent *event)
//{
//    if(event->key() == Qt::Key_0){

//        ModuleDir dir;
//        dir.append(MD_CloudWeb);
//        m_pCL->sendToMain(dir,CW_LoadNewUrl,"www.baidu.com");
//       qDebug()<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
//    }
//}

void testWgt::onClDataCome(int cmd, QVariant data)
{
    data.isValid();
    switch (cmd) {
    case 1:
    {
        this->updateWidget();
        break;
    }
    case 2:
    {

        break;
    }

    case 3:
    {

        break;
    }

    default:
        break;
    }
}

void testWgt::onModelUpdate(int cmd)
{
    testModel::ModelCmdType tCmd = static_cast<testModel::ModelCmdType>(cmd);
    switch (tCmd) {
    case testModel::MC_UpdateAll:
    {
        this->updateWidget();
        break;
    }
    case testModel::MC_LoadUrl:
    {


//        ui->lineEdit->setText("我在测试");
//        ui->lineEdit->setStyleSheet("background:red;border-width:0;border-style:outset"); //不

//        qDebug()<< ui->lineEdit<<"我在测试*************"<<m_pModel->m_url;
//        QWebEngineView *view = new QWebEngineView(this);
//        QUrl url = QUrl::fromUserInput("http://baidu.com");
//        view->load(url);
//        ui->gridLayout->addWidget(view);
        break;
    }
    case testModel::MC_SwitchMap:
    {

        break;
    }

    default:
        break;
    }
}

