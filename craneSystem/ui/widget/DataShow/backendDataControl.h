#ifndef BACKENDDATACONTROL_H
#define BACKENDDATACONTROL_H

#include <QObject>
#include "../../Interface/IController.h"
#include "backendDataModel.h"
#include "../../sql/SqlMethod.h"
#include "../../../dataInterFace/zmqmodule/thread/sqlTruncateThread.h"
#include <QTimer>
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

    bool findData(const QString& startTime,const QString& endTime,QList<QMap<QString, QString>> &row);//查数据
    void getButton(int numb);
    void setModel(backendDataModel *model);
private slots:
private:

    backendDataModel *m_pModel;
    QSharedPointer<QTimer> _timer;
    QThread * _thread = nullptr;
    sqlTruncateThread * P_sqlTruncateThread = nullptr;
};

#endif // BACKENDDATACONTROL_H
