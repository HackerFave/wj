#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QObject>
#include "../../Interface/IModel.h"
class testModel : public IModel
{
    Q_OBJECT
public:
    explicit testModel(QObject *parent = nullptr);
    enum ModelCmdType
    {
        MC_UpdateAll=0,
        MC_LoadUrl,
        MC_SwitchMap,
        MC_Max
    };

    void setUrl(QString &url);
    void setCurrentMode(QString &data);
    QString m_url;
    QString _mapMode;
};
#endif // TESTMODEL_H
