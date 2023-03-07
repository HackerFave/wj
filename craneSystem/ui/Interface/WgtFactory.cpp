#include "WgtFactory.h"
#include <QDebug>
#include "../widget/TestForm/testWgt.h"
#include "../widget/DataShow/backendDataForm.h"
QMap<int,IFunWidget*> WgtFactory::m_factoryWgt;
void WgtFactory::initWidget()
{

}

IFunWidget * WgtFactory::getFunWidget(ModuleType type)
{
    IFunWidget *pFunWidget = nullptr;
    switch (type) {
    case MD_TestForm:
    {
        qInfo() << "MD_testWgt"<<"";
        pFunWidget = testWgt::GetInstance();
    }
        break;
    case MD_backendDataForm:
    {
        qInfo() << "MD_backendDataForm"<<"";
        pFunWidget = backendDataForm::GetInstance();
    }
        break;
    default:
    {
        qWarning() << "can't find this ModuleType:"<<type;
        pFunWidget = nullptr;
        break;
    }
    }

    return pFunWidget;
}

