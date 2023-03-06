#ifndef WGTFACTORY_H
#define WGTFACTORY_H

#include "IFunWidget.h"

class WgtFactory
{
public:
    static void     initWidget();
    static IFunWidget* getFunWidget(ModuleType type);
private:
    static QMap<int,IFunWidget*> m_factoryWgt;
};

#endif // WGTFACTORY_H
