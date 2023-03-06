#include "System.h"
#include <QApplication>
#include <QTime>
#include <QSharedMemory>
#include "WgtFactory.h"
#include <QDebug>
#include "../../public/fbsstructure.h"
#define KEY_SHARED_MEMORY  "RcdSysShareData"

System *System::m_pInstance = nullptr;

System::System() /*: m_processType(PT_All),m_pSharedMemory(nullptr)*/
{
    qRegisterMetaType<ModuleDir>("ModuleDir");
    qRegisterMetaTypeStreamOperators<dispatchTaskST>("dispatchTaskST");
    qRegisterMetaTypeStreamOperators<cabinTakeoverTaskApplyST>("cabinTakeoverTaskApplyST");
    qRegisterMetaTypeStreamOperators<vehicleDataST>("vehicleDataST");
    qRegisterMetaTypeStreamOperators<SelfCheckStatusST>("SelfCheckStatusST");
    qRegisterMetaTypeStreamOperators<ReportRoadTaskInfoST>("ReportRoadTaskInfoST");


    memset(&m_sysShareData,0,sizeof(m_sysShareData));
    m_pSharedMemory = new QSharedMemory();
    m_taskId = 0;

    m_currentMsg = MD_None;

}

System::~System()
{
    m_pSharedMemory->detach();
    delete m_pSharedMemory;
}

System *System::getInstance()
{
    if(m_pInstance == nullptr){
        m_pInstance = new System();
    }
    return m_pInstance;
}

void System::createSharedMemory()
{
    m_pSharedMemory->setKey(KEY_SHARED_MEMORY);
//    if(m_processType == PT_MidProc){
//        if(m_pSharedMemory->isAttached()){
//            m_pSharedMemory->detach();
//        }
        if(!m_pSharedMemory->create(sizeof(SharedDatas))){
            qWarning() << "Unable to create SharedMemory:" << m_pSharedMemory->errorString();
        }
//    }
}

void System::readSharedMemory()
{
    if(!m_pSharedMemory->isAttached()){
        if(!m_pSharedMemory->attach(QSharedMemory::ReadOnly)){
            qWarning() << "Read attach error:"<< m_pSharedMemory->errorString();
            return;
        }
    }
    m_pSharedMemory->lock();
    memcpy(&m_sysShareData,m_pSharedMemory->constData(),sizeof(SharedDatas));
    m_pSharedMemory->unlock();

    //    if(m_processType != PT_MidProc){
    //        m_pSharedMemory->detach();
    //    }
}

void System::writeSharedMemory()
{
    if(!m_pSharedMemory->isAttached()){
        if(!m_pSharedMemory->attach(QSharedMemory::ReadWrite)){
            qWarning() << "Write attach error:" <<m_pSharedMemory->errorString();
            return;
        }
    }
    m_pSharedMemory->lock();
    memcpy(m_pSharedMemory->data(),&m_sysShareData,sizeof(SharedDatas));
    m_pSharedMemory->unlock();

    //    if(m_processType != PT_MidProc){
    //        m_pSharedMemory->detach();
    //    }
}




unsigned short System::getCurrentTaskId()
{
    return  m_taskId;
}

void System::setCurrentTaskId(unsigned short &taskId)
{
    m_taskId = taskId;
}

void System::setVehicleStatus(int type)
{
    currentVehicleStatus = type;
}

int System::getVehicleStatus()
{
    return currentVehicleStatus;
}



void System::setShowEmergency(bool state)
{
    emergencyState = state;
}

bool System::getShowEmergency()
{
    return emergencyState;
}
System::SharedDatas* System::getSharedDatas()
{
    return &m_sysShareData;
}

ModuleType System::getCurrentMsg()
{
    return m_currentMsg;
}


