#include "WgtFactory.h"
#include <QDebug>
#include "../widget/TestForm/testWgt.h"
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
        qInfo() << "MD_testWgt"<<"________________________________________";
        pFunWidget = testWgt::GetInstance();
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

