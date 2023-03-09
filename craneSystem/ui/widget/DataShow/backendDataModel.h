#ifndef BACKENDDATAMODEL_H
#define BACKENDDATAMODEL_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QVariant>
#include "../../Interface/IModel.h"

class backendDataModel : public IModel
{
    Q_OBJECT
public:
    enum ModelCmdType
    {
        MC_UpdateNew=0,
        MC_Find,
        MC_CurrentTime,
        MC_FindCount,
        MC_UpPage,//上一页
        MC_DownPage,//下一页
        MC_ShowPage,//下一页
        MC_TurnOnPage
    };
    explicit backendDataModel(QObject *parent = nullptr);
    void setFindData(QList<QMap<QString, QString>> &row);
    void setPage(QVariant page);
    QList<QMap<QString, QString>> _findRowData;
    int _sqlCount;
    QList<QMap<QString, QString>> _currentShowData;
};

#endif // BACKENDDATAMODEL_H
