#include "backendDataModel.h"
#include <QtDebug>
backendDataModel::backendDataModel(QObject *parent): IModel(parent)
{

}
void backendDataModel::setFindData(QList<QMap<QString, QString>> &row)
{
    if(!row.isEmpty()){
        _findRowData = row;
        emit signalSendModelUpdate(MC_Find);
    }
}
void backendDataModel::setPage(QVariant page)
{
    if(page.toMap().size()>1){
        _currentShowData.clear();
        for(int i =(page.toMap()["page"].toUInt()-1)*PAGE_ONE;i<(page.toMap()["page"].toUInt()-1)*PAGE_ONE+page.toMap()["last"].toUInt();i++){
            _currentShowData.push_back(_findRowData.at(i));
        }
        emit signalSendModelUpdate(MC_ShowPage);
    }
    else {
        _currentShowData.clear();
        for(int i =(page.toMap()["page"].toUInt()-1)*PAGE_ONE;i<(page.toMap()["page"].toUInt()-1)*PAGE_ONE+PAGE_ONE;i++){
            _currentShowData.push_back(_findRowData.at(i));
        }
        emit signalSendModelUpdate(MC_ShowPage);
    }

}
