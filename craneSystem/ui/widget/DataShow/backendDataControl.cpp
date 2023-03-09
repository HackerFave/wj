#include "backendDataControl.h"
#include <QDebug>

backendDataControl::backendDataControl(QObject *parent) : IController(parent)
{
    _timer.reset(new QTimer);
    connect(_timer.data(),&QTimer::timeout,this, [=](){
        ModuleDir dir;
        dir.append(MD_backendDataForm);
        emit signalPushDataToView(CW_CurrentTime,QVariant(0));
        emit signalPushDataToView(CW_FindCount,QVariant(0));
    });
    _timer->start(1000);

    _thread = new QThread;
    P_sqlTruncateThread = new sqlTruncateThread;
    P_sqlTruncateThread->moveToThread(_thread);//
    connect(_thread,SIGNAL(finished()),P_sqlTruncateThread,SLOT(deleteLater()));
    connect(_thread,SIGNAL(started()),P_sqlTruncateThread,SLOT(slotWork()));

    if(!_thread->isRunning()){
        _thread->start();
    }

}

backendDataControl::~backendDataControl()
{
    if(_thread->isRunning())
    {
        P_sqlTruncateThread->stopWork();  //关闭线程槽函数
        _thread->quit();            //退出事件循环
        _thread->wait();            //释放线程槽函数资源
    }
}

void backendDataControl::doInit()
{
    //    qInfo()<<"CloudWebCL::doInit()";
}

void backendDataControl::doUnInit()
{

}

bool backendDataControl::exitAction()
{
    return true;
}

bool backendDataControl::intoAction()
{

    return true;
}

void backendDataControl::getFromAny(ModuleDir moduleDir,int cmd,QVariant data)
{
    moduleDir.clear();
    backendDataFormType Cmd = static_cast<backendDataFormType>(cmd);

    switch (Cmd) {
    case CW_UpdateNew:{

        break;
    }
    case CW_Find:{
        QList<QMap<QString, QString>> row;
        if(!findData(data.toMap()["start"].toString(),data.toMap()["end"].toString(),row)){
            qWarning()<<QStringLiteral("查询数据库失败");
            return;
        }
        m_pModel->setFindData(row);
        break;
    }
    case CW_DownPage:
    {
        if(!data.toMap()["page"].toString().isEmpty()&&data.toMap()["page"].toUInt()>0){
            m_pModel->setPage(data);
        }
        break;
    }
    case CW_UpPage:
    {
        if(!data.toMap()["page"].toString().isEmpty()&&data.toMap()["page"].toUInt()>0){
            m_pModel->setPage(data);
        }
        break;
    }
    case CW_TurnOnPage:
    {
        if(!data.toMap()["page"].toString().isEmpty()&&data.toMap()["page"].toUInt()>0){
            m_pModel->setPage(data);
        }
        break;
    }
    default:{break;}
    }

}

void backendDataControl::setModel(backendDataModel *model)
{
    m_pModel = model;
}
bool backendDataControl::findData(const QString& startTime,const QString& endTime,QList<QMap<QString, QString>> &row)
{
    QString table_name = "testtable";
    QString where = "date";
    QStringList keyList;
    keyList<<"id"<<"data1"<<"data2"<<"data3"<<"data4"<<"data5"<<"date";
    QSqlQuery * ret = nullptr;
    return  SqlMethod::sqlmethod_instance()->getsqloperationinstance("find")
            ->findData(table_name,keyList,where,startTime,endTime,row,&ret);

}
