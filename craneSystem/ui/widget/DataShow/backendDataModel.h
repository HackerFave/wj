#ifndef BACKENDDATAMODEL_H
#define BACKENDDATAMODEL_H

#include <QObject>
#include <QList>
#include <QMap>
#include "../../Interface/IModel.h"

class backendDataModel : public IModel
{
    Q_OBJECT
public:
    enum ModelCmdType
    {
        MC_UpdateNew=0,
        MC_Find
    };
    explicit backendDataModel(QObject *parent = nullptr);
    //    void setUrl(QString &url);
    //    void setCurrentMode(QString &data);
    void setFindData(QList<QMap<QString, QString>> &row);
    QList<QMap<QString, QString>> _findRowData;
};

#endif // BACKENDDATAMODEL_H
