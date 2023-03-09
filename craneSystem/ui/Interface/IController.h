#ifndef IController_H
#define IController_H

#include <QObject>
#include <QVariant>
#include "System.h"
#include "../Interface/IModel.h"
//#include "map/methord/system.h"

class IController : public QObject
{
    Q_OBJECT
public:
    IController(QObject *parent);
    ~IController();

    virtual void doInit();

    virtual void doUnInit();

    virtual bool intoAction();

    virtual bool exitAction();

    virtual void doActionAfter();

    virtual void getFromAny(ModuleDir moduleDir,int cmd,QVariant data );
    virtual void getFromAny(ModuleDir,QStringList,int,int,QVariant data );

signals:

    void signalPushDataToView(int cmd, QVariant data = INT_INVALID);

    void signalSendToMain(ModuleDir moduleDir,int cmd, QVariant data = INT_INVALID); // 控制命令 ControlCmd
    //moduleDir是要通知到的区域,nameList是要通知到的窗口，两个都要发
    void signalSendToMain(ModuleDir moduleDir,QStringList nameList,int cmd,int subcmd,QVariant data); // 控制命令 ControlCmd，发给modele层

public:

    bool       msgStatus;

};

#endif // IController_H
