#include "backendDataForm.h"
#include "ui_backendDataForm.h"
backendDataForm* backendDataForm::s_pInstance = nullptr; //初始化静态数据成员
static int _currentPage = 0;
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

    //    QDateTime currentTime = QDateTime::currentDateTime();       //获取当前系统时间
    //    QString current_Time = currentTime.toString("yyyy/MM/dd hh:mm");     //设置时间格式
    //    QString beforeDayTime = currentTime.addDays(-1).toString("yyyy/MM/dd hh:mm");  //获取前一天时间

    //    QString beforeDayTime = currentTime.addDays(+4).toString("yyyy/MM/dd hh:mm");//将-1更改为+4，获得的时间为
    ui->dateTimeEdit_end->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_start->setDateTime(QDateTime::currentDateTime().addDays(-3));
    ui->dateTimeEdit_end->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
    ui->dateTimeEdit_start->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
    ui->dateTimeEdit_start->setCalendarPopup(true);  // 日历弹出
    ui->dateTimeEdit_end->setCalendarPopup(true);  // 日历弹出
    ui->lineEdit_page->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    P_tableView = new tableView(this);
    ui->verticalLayout->addWidget(P_tableView);
//    ui->verticalLayout->addStretch();
}

backendDataForm::~backendDataForm()
{

    delete ui;
    delete m_pCL;
    delete m_pModel;
}
void backendDataForm::slotPushButton_find()
{
    ModuleDir dir;
    dir.append(MD_backendDataForm);
    QVariantMap data;
    data["start"]= ui->dateTimeEdit_start->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    data["end"] = ui->dateTimeEdit_end->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    emit m_pCL->signalSendToMain(dir,CW_Find,data);
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
    m_pCL->intoAction();
    this->updateWidget();
}

bool backendDataForm::isQuit()
{
    m_pCL->exitAction();
    return true;
}

void backendDataForm::updateWidget()
{
    this->update();
}

void backendDataForm::slotOnClDataCome(int cmd, QVariant data)
{
    data.isValid();
    backendDataModel::ModelCmdType tCmd = static_cast<backendDataModel::ModelCmdType>(cmd);
    switch (tCmd) {
    case backendDataModel::MC_FindCount:
    {
        std::string table_name = "testtable";
        std::map<std::string, std::string> where;
        QSqlQuery * ret = nullptr;
        ui->label_count->setText(QString("[ %1 ]")
                                 .arg(SqlMethod::sqlmethod_instance()->getsqloperationinstance("find")
                                      ->getcountsize(table_name,where,&ret)));
        break;
    }
    case backendDataModel::MC_CurrentTime:
    {
        //        ui->dateTimeEdit_start->setDateTime(QDateTime::currentDateTime().addDays(-3));
        //        ui->dateTimeEdit_end->setDateTime(QDateTime::currentDateTime());
        ui->label_time->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

        break;
    }
    default:
        break;
    }
}

void backendDataForm::slotOnModelUpdate(int cmd)
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
        ModuleDir dir;
        dir.append(MD_backendDataForm);
        QVariantMap data;
        data["page"] = "1";
        if(getPage(m_pModel->_findRowData.size())==1){
            data["last"] = getRemainder(m_pModel->_findRowData.size());
        }
        emit m_pCL->signalSendToMain(dir,CW_UpPage,data);
        _currentPage = 1;
        ui->label_page->setText(QString("%1 / 1 ")
                                .arg(getPage(m_pModel->_findRowData.size())));
        ui->lineEdit_page->setText("1");
        break;
    }
    case backendDataModel::MC_ShowPage:
    {
        QStringList keyList;
        keyList<<"id"<<"data1"<<"data2"<<"data3"<<"data4"<<"data5"<<"date";
        if(m_pModel->_currentShowData.size()>0){
            P_tableView->tableViewClear();
            for(int i=0;i<m_pModel->_currentShowData.size();i++){
                P_tableView->addRowItem(m_pModel->_currentShowData.at(i),keyList);
            }
        }
        break;
    }
        //    case backendDataModel::MC_TurnOnPage:
        //    {
        //        QStringList keyList;
        //        keyList<<"id"<<"data1"<<"data2"<<"data3"<<"data4"<<"data5"<<"date";
        //        if(m_pModel->_currentShowData.size()>0){
        //            P_tableView->tableViewClear();
        //            for(int i=0;i<m_pModel->_currentShowData.size();i++){
        //                P_tableView->addRowItem(m_pModel->_currentShowData.at(i),keyList);
        //            }
        //        }
        //        break;
        //    }
    default:
        break;
    }
}



void backendDataForm::on_pushButton_up_page_clicked()
{
    if(_currentPage<=1){
        return;
    }
    _currentPage--;
    ui->label_page->setText(QString("%1 / %2 ")
                            .arg(getPage(m_pModel->_findRowData.size()))
                            .arg(_currentPage));
    ui->lineEdit_page->setText(QString("%1").arg(_currentPage));

    ModuleDir dir;
    dir.append(MD_backendDataForm);
    QVariantMap data;
    data["page"] = _currentPage;
    emit m_pCL->signalSendToMain(dir,CW_UpPage,data);
}

void backendDataForm::on_pushButton_down_page_clicked()
{
    if(_currentPage>=getPage(m_pModel->_findRowData.size())){
        return;
    }
    _currentPage++;
    ui->label_page->setText(QString("%1 / %2 ")
                            .arg(getPage(m_pModel->_findRowData.size()))
                            .arg(_currentPage));
    ui->lineEdit_page->setText(QString("%1").arg(_currentPage));
    ModuleDir dir;
    dir.append(MD_backendDataForm);
    QVariantMap data;
    if(getPage(m_pModel->_findRowData.size())==_currentPage){
        data["last"] = getRemainder(m_pModel->_findRowData.size());
    }
    data["page"] = _currentPage;
    qWarning()<<_currentPage<<"KKKKKKKKKKKKKKKKKKKKKKKK";
    emit m_pCL->signalSendToMain(dir,CW_DownPage,data);
}

void backendDataForm::on_pushButton_on_page_clicked()
{
    QVariantMap data;
    if(ui->lineEdit_page->text().simplified().toUInt()>getPage(m_pModel->_findRowData.size())){
        return;
    }
    else if(getPage(m_pModel->_findRowData.size())==ui->lineEdit_page->text().simplified().toUInt()){
        data["last"] = getRemainder(m_pModel->_findRowData.size());
    }
    _currentPage = ui->lineEdit_page->text().simplified().toInt();
    ui->label_page->setText(QString("%1 / %2 ")
                            .arg(getPage(m_pModel->_findRowData.size()))
                            .arg(_currentPage));
    ModuleDir dir;
    dir.append(MD_backendDataForm);
    data["page"] = _currentPage;
    emit m_pCL->signalSendToMain(dir,CW_TurnOnPage,data);
}
