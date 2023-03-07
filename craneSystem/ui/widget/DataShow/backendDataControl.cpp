#include "backendDataControl.h"
#include <QDebug>
backendDataControl::backendDataControl(QObject *parent) : IController(parent)
{

}

backendDataControl::~backendDataControl()
{

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
        findData(data.toMap()["start"].toString(),data.toMap()["end"].toString(),row);
        m_pModel->setFindData(row);
        break;
    }
    default:{break;}
    }

}

void backendDataControl::setModel(backendDataModel *model)
{
    m_pModel = model;
}
void backendDataControl::findData(const QString& startTime,const QString& endTime,QList<QMap<QString, QString>> &row)
{
    QString table_name = "testtable";
    QString where = "date";
    QStringList keyList;
    keyList<<"id"<<"data1"<<"data2"<<"data3"<<"data4"<<"data5"<<"date";
    QSqlQuery * ret = nullptr;
    SqlMethod::sqlmethod_instance()->getsqloperationinstance("find")->findData(table_name,keyList,where,startTime,endTime,row,&ret);
}
