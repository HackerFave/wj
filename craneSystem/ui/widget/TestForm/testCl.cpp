#include "testCl.h"
#include <QDebug>


testCl::testCl(QObject *parent) : IController(parent)
{

}

testCl::~testCl()
{

}

void testCl::doInit()
{
    //    qInfo()<<"CloudWebCL::doInit()";
}

void testCl::doUnInit()
{

}

bool testCl::exitAction()
{
    return true;
}

bool testCl::intoAction()
{

    return true;
}

void testCl::getFromAny(ModuleDir moduleDir,int cmd,QVariant data)
{
    moduleDir.clear();
    TestFormCmdType Cmd = static_cast<TestFormCmdType>(cmd);

    switch (Cmd) {
    case CW_Test1:{
        QString url = data.toString();
        m_pModel->setUrl(url);
        break;
    }
    case CW_Test2:{
        QString mode = data.toString();
        m_pModel->setCurrentMode(mode);
        break;
    }
    default:{break;}
    }

}

void testCl::setModel(testModel *model)
{
    m_pModel = model;
}
