#ifndef BACKENDDATACONTROL_H
#define BACKENDDATACONTROL_H

#include <QObject>
#include "../../Interface/IController.h"
#include "backendDataModel.h"
#include "../../sql/SqlMethod.h"
class backendDataControl : public IController
{
    Q_OBJECT
public:
    explicit backendDataControl(QObject *parent = nullptr);
    ~backendDataControl() override;
    void doInit() override;
    void doUnInit() override;
    bool intoAction() override;
    bool exitAction() override;
    void getFromAny(ModuleDir moduleDir,int cmd,QVariant data ) override;

    void findData(const QString& startTime,const QString& endTime,QList<QMap<QString, QString>> &row);
    void getButton(int numb);
    void setModel(backendDataModel *model);
private:

    backendDataModel *m_pModel;
};

#endif // BACKENDDATACONTROL_H
