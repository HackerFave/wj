#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QMetaType>
#include <QDateTime>
#include <QMap>
#include <QWidget>
#include <QtDebug>
#include <set>

//#define RCD_VERSION "V06.80.09.02.01.08"


#ifndef INT_INVALID
#define INT_INVALID (-1) //无效值
#endif

#ifndef STR_INVALID
#define STR_INVALID ("") //无效值
#endif

typedef QList<uint> ModuleDir;
Q_DECLARE_METATYPE(ModuleDir);



enum ModuleType
{
    MD_None=-1,//隐藏窗口
    MD_MainProcessor=0,       //主处理模块

    MD_MainMonitor,           //主监控界面

    MD_CloudWeb,              //web界面
    MD_CloudWebSmall,         //web小界面
    MD_TestForm               //测试界面

};
// 监控主界面命令
enum MainMonitorWgtCmdType
{
    MM_UpdateAll=0,         //更新界面
    MM_VehicleData,         //当前接入车辆设备信息
    MM_ThrottleBrakeWheel,  //当前接入车辆设备信息
    MM_Speed,               //当前接入车辆设备速度
    MM_Gear,                //当前接入车辆设备档位
    MM_VehicleStatus,       //当前接入车辆设备状态
    MM_UpdateLoginStatus,   //更新登陆状态
    MM_UpdateUI,       //更新ui
    MM_CloseTip,       //关闭提示
    MM_ShowEmergency,       //show emergency tip
    MM_TSET,
    MM_UpdateOnlineState      //更新车辆在线状态

};

enum CloudWebWgtCmdType
{
    CW_LoadNewUrl=0,
    CW_SwitchMapUrl,

    CW_Max
};


enum TestFormCmdType
{
    CW_Test1=0,
    CW_Test2,

    CW_Other
};
#define IMEI_LENGTH 15

class QSharedMemory;

// 系统功能类
class System
{

public:
    ~System();

    typedef struct
    {
        uint8_t                  sysStatus;
        char                     vehicleImei[IMEI_LENGTH + 1];
        char                     none[4096 - (IMEI_LENGTH + 2)];
    } SharedDatas;

    static System           *getInstance();
    void             delayMsecTime(int msecTime,int delayModel = 0);
    bool             messageFilter(ModuleType module);
    bool             messageFilter(ModuleType module,QString &imei);
    void             setCurrentVehicle(QString &imei);
//    std::atomic<LayoutType> showLayoutMode;

    unsigned short   getCurrentTaskId();
    void             setCurrentTaskId(unsigned short &taskId);
    void             setShowEmergency(bool state);
    bool             getShowEmergency();//show or not show emergency window
    void             setVehicleStatus(int type);
    int              getVehicleStatus();
    SharedDatas*     getSharedDatas();
    ModuleType       getCurrentMsg();


    bool getShowFlag(){
        return showTipFlag;
    }
    void setShowFlag(bool flag){
        showTipFlag=flag;
    }

    int                      currentTakeoverPurpose=-1;


private:
    System();
    void                     createSharedMemory();
    void                     readSharedMemory();
    void                     writeSharedMemory();

    static System            *m_pInstance;
    SharedDatas              m_sysShareData;
    QSharedMemory            *m_pSharedMemory;
    unsigned short           m_taskId;
    ModuleType               m_currentMsg;
    bool                     showTipFlag=false;
    bool                     emergencyState=false;
    int                      currentVehicleStatus;

public:
    std::set<QString> onlineVehicle;
    uint warningSpeed=100;
    uint reduceSpeed=100;
    bool forwardLeft_forwardRight_Big=false;//左前和右前摄像头是否处于放大状态
};

#if defined(pSharedDatas)
#undef pSharedDatas
#endif
#define pSharedDatas System::getSharedDatas()

#endif // SYSTEM_H
