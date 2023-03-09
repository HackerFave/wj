#include "testModel.h"

testModel::testModel(QObject *parent) : IModel(parent)
{

}

void testModel::setUrl(QString &url)
{
    m_url = url;
    emit signalSendModelUpdate(MC_LoadUrl);
}
void testModel::setCurrentMode(QString &data)
{
    _mapMode = data;
    emit signalSendModelUpdate(MC_SwitchMap);
}
