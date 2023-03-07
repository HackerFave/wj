#include "backendDataForm.h"
#include "ui_backendDataForm.h"
backendDataForm* backendDataForm::s_pInstance = nullptr; //初始化静态数据成员
backendDataForm::backendDataForm(QWidget *parent) :
    IFunWidget(parent),
    ui(new Ui::backendDataForm)
{
    ui->setupUi(this);
    m_pCL = new backendDataControl();
    m_pCL->doInit();
    this->setCL(m_pCL);

    m_pModel = new backendDataModel();
    this->setModel(m_pModel);
    m_pCL->setModel(m_pModel);

    connect(ui->pushButton_find,SIGNAL(clicked()),this,SLOT(slotPushButton_find()));
    ui->dateTimeEdit_end->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_start->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_end->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
    ui->dateTimeEdit_start->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
    ui->dateTimeEdit_start->setCalendarPopup(true);  // 日历弹出
    ui->dateTimeEdit_end->setCalendarPopup(true);  // 日历弹出
    P_tableView = new tableView(this);
    ui->gridLayout->addWidget(P_tableView);
    qDebug()<<ui->dateTimeEdit_start->dateTime().toString("yyyy-MM-dd hh:mm:ss")<<"*************************";
}

backendDataForm::~backendDataForm()
{

    delete ui;
    delete m_pCL;
    delete m_pModel;
}
void backendDataForm::slotPushButton_find()
{
    //    SqlMethod::sqlmethod_instance()->getsqloperationinstance("test")->findDataRecord();
    //    QMap<QString,QString> map;
    //    QStringList keyList;
    //    keyList<<"id"<<"data1"<<"data2"<<"data3"<<"data4"<<"data5";
    //    static int i = 0;

    //    map["id"] = QString::number(i++);
    //    map["data1"] ="1";
    //    map["data2"] ="1";
    //    map["data3"] ="1";
    //    map["data4"] ="1";
    //    map["data5"] ="1";

    //    P_tableView->addRowItem(map,keyList);
    ModuleDir dir;
    dir.append(MD_backendDataForm);
    QVariantMap data;
    data["start"]= ui->dateTimeEdit_start->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    data["end"] = ui->dateTimeEdit_end->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    emit m_pCL->sendToMain(dir,CW_Find,data);
}
backendDataForm *backendDataForm::GetInstance()
{
    if(s_pInstance == nullptr) {
        s_pInstance = new backendDataForm();
    }
    return s_pInstance ;
}

void backendDataForm::resizeEvent(QResizeEvent *event)
{
    QScreen *pScreen = QGuiApplication::primaryScreen();

}

void backendDataForm::initWidget()
{
    //    qInfo()<<"CloudWebWgt::initWidget";
    m_pCL->intoAction();
    this->updateWidget();
}

bool backendDataForm::isQuit()
{
    //    qInfo()<<"CloudWebWgt::isQuit";
    m_pCL->exitAction();
    return true;
}

void backendDataForm::updateWidget()
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

void backendDataForm::onClDataCome(int cmd, QVariant data)
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

void backendDataForm::onModelUpdate(int cmd)
{
    backendDataModel::ModelCmdType tCmd = static_cast<backendDataModel::ModelCmdType>(cmd);
    switch (tCmd) {
    case backendDataModel::MC_UpdateNew:
    {
        this->updateWidget();
        break;
    }
    case backendDataModel::MC_Find:
    {
        QStringList keyList;
        keyList<<"id"<<"data1"<<"data2"<<"data3"<<"data4"<<"data5"<<"date";
        if(m_pModel->_findRowData.size()>0){
            qDebug()<<m_pModel->_findRowData.at(0)<<"JJJJJJJJJJJJJJJJJJJJJJJJJJJ";

            P_tableView->addRowItem(m_pModel->_findRowData.at(0),keyList);
        }
        break;
    }
        //    case backendDataModel::MC_SwitchMap:
        //    {

        //        break;
        //    }

    default:
        break;
    }
}

