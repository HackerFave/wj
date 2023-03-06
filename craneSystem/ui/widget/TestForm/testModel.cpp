#include "testModel.h"

testModel::testModel(QObject *parent) : IModel(parent)
{

}

void testModel::setUrl(QString &url)
{
    m_url = url;
    emit sendModelUpdate(MC_LoadUrl);
}
void testModel::setCurrentMode(QString &data)
{
    _mapMode = data;
    emit sendModelUpdate(MC_SwitchMap);
}
