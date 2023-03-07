#include "backendDataModel.h"

backendDataModel::backendDataModel(QObject *parent): IModel(parent)
{

}
void backendDataModel::setFindData(QList<QMap<QString, QString>> &row)
{
    _findRowData = row;
    emit sendModelUpdate(MC_Find);
}
//void backendDataModel::setUrl(QString &url)
//{
//    m_url = url;
////    emit sendModelUpdate(MC_LoadUrl);
//}
//void backendDataModel::setCurrentMode(QString &data)
//{
//    _mapMode = data;
////    emit sendModelUpdate(MC_SwitchMap);
//}
