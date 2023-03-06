#include "IController.h"

IController::IController(QObject *parent) :
    QObject(parent)
{

}

IController::~IController()
{

}

void IController::doInit()
{

}

void IController::doUnInit()
{

}

bool IController::intoAction()
{
    return true;
}

bool IController::exitAction()
{
    return true;
}

void IController::doActionAfter()
{

}

void IController::getFromAny(ModuleDir moduleDir,int cmd,QVariant data )
{
    Q_UNUSED(moduleDir)
    Q_UNUSED(cmd)
    Q_UNUSED(data)
}

void IController::getFromAny(ModuleDir moduleDir,QStringList striList,int cmd,int subcmd,QVariant data )
{
    Q_UNUSED(moduleDir)
    Q_UNUSED(striList)
    Q_UNUSED(cmd)
    Q_UNUSED(data)
}
