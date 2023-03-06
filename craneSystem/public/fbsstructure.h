#ifndef FBSSTRUCT_H
#define FBSSTRUCT_H
#include <QString>
#include <QObject>
#include <QMetaType>
#include <QDataStream>

#pragma pack(1)
//调度任务
struct dispatchTaskST
{
    unsigned short taskId; //调度任务编号
    QString targetName; //调度目标
    QString fileUrl;  //路径文件下载地址
    QString fileMd5;  //文件MD5

    friend QDataStream &operator<<(QDataStream &out, const dispatchTaskST &st)
    {
        out<<st.taskId<<st.targetName<<st.fileUrl<<st.fileMd5;
        return out;
    }
    friend QDataStream &operator>>(QDataStream &in, dispatchTaskST &st)
    {
        in>>st.taskId>>st.targetName>>st.fileUrl>>st.fileMd5;
        return in;
    }
};
Q_DECLARE_METATYPE(dispatchTaskST)

// --> BEGIN modify by ZJZ, 2022/3/8
// 弹窗内容
struct popContent{
    int firstPriority;
    int secondPriority;
    int delay;
    int cmd;
    QString content;
    QString btnText;
};
Q_DECLARE_METATYPE(struct popContent)

enum TipsPopupLBtnCmd {
    TipsPopupLBtnCmd_None,          // do nothing
    TipsPopupLBtnCmd_DevLink,       // “座舱控制单元掉线！即将结束任务，请复位座舱。”
    TipsPopupLBtnCmd_Timeout,       // “等待连接超时，请检查网络状态后重新进入”
    TipsPopupLBtnCmd_GiveupMonitor, // “确认结束监控？”
};
// <-- END

//平台下发接管任务申请到驾驶舱
struct cabinTakeoverTaskApplyST{
    unsigned short taskId; //接管任务编号
    QString truckImei;  //矿卡imei
    QString truckName; //矿卡名称
    QString truckIp; //矿卡ip
    QString secretKey;//密钥
    int takeoverPurpose; //接管目的
    dispatchTaskST dispatchTask;//原派遣任务
    void clear(){
        taskId=0;
        truckImei.clear();
        truckName.clear();
        truckIp.clear();
        secretKey.clear();
        takeoverPurpose=0;
        dispatchTask.taskId=0;
        dispatchTask.targetName.clear();
        dispatchTask.fileMd5.clear();
        dispatchTask.fileUrl.clear();
    }


    friend QDataStream &operator<<(QDataStream &out, const cabinTakeoverTaskApplyST &st)
    {
        out<<st.taskId<<st.truckImei<<st.truckName<<st.truckIp<<st.secretKey<<st.takeoverPurpose<<st.dispatchTask;
        return out;
    }
    friend QDataStream &operator>>(QDataStream &in, cabinTakeoverTaskApplyST &st)
    {
        in>>st.taskId>>st.truckImei>>st.truckName>>st.truckIp>>st.secretKey>>st.takeoverPurpose>>st.dispatchTask;
        return in;
    }
};
Q_DECLARE_METATYPE(cabinTakeoverTaskApplyST)

struct vehicleDataST{
    float throttlePedal;      //实际踩踏板百分比 0~100%
    float brakePedal;         //电制动踏板位置百分比 0~100

    // --> BEGIN added by ZJZ, 2022/5/10
    // 液压制动
    float hydraulicBrake;     //机械制动踏板反馈百分比 0~100
    // <-- END

    float steeringWheelAngle;    //方向盘当前转角 -540~540
    float engineSpeed;      //1rpm 发动机转速
    float speed;       //km/h 车速

    // --> BEGIN added by ZJZ, 2022/4/2
    float batteryVoltage;           // 电池电压 0-50V
    float fuelLevel;                // 油量 0-100%
    float engineOilPressure;        // 发动机油压 0~1000kP
    float engineCoolantTemperature; // 发动机冷却液温度 -40~210°C
    // <-- END

    int8_t gear;   //挡位 -1:R 0:N 1:D
    uint8_t mode; // 车辆驾驶模式 0x00手动/0x01自动
    uint8_t handBrake; //手制动电磁阀 0x01: open 0x00: close
    uint8_t bucketCtrl; //举升 0x00/0x01/0x02/0x03/0x04 下止点/上止点/下降/上升/保持
    uint8_t tirePressureWarning; //胎压故障告警 0 no error, >0 error

    /* 0x01: enable 0x00: disable */
    uint8_t exhaustBrake; //排气制动
    uint8_t emergencyFlash; //紧急双闪 00关/01开
    uint8_t left;  //左转灯
    uint8_t right; //右转灯
    uint8_t lowBeam;    //近光灯
    uint8_t highBeam;   //远光灯
    uint8_t rotateAlarm; //旋转报警灯
    uint8_t airHorns;          //气喇叭
    uint8_t frontFogLamp;     //前雾灯
    uint8_t frontWorkLamp;    //前工作灯
    uint8_t sideLamp;     //侧照灯
    uint8_t positoinLamp; //位置灯


    friend QDataStream &operator<<(QDataStream &out, const vehicleDataST &st)
    {
        QByteArray tmp((const char*)&st,sizeof(st));
        out<<tmp;
        return out;
    }
    friend QDataStream &operator>>(QDataStream &in, vehicleDataST &st)
    {
        QByteArray tmp;
        in>>tmp;
        memcpy(&st,tmp.data(),tmp.size());
        return in;
    }
};
Q_DECLARE_METATYPE(vehicleDataST)

struct TrackLineCalibrationST{
    bool valid;
    int  counter;
//    是否开启了后置摄像头镜像true/false
    bool mirrorBackCameraFlag;
//    车轮最大转角-35~35度
    double wheelMaxAngle;
//    方向盘最大转角-720 ~ 720度
    double steerMaxAngle;
//    前摄像头垂直可视角度(度)
    double FovFrontCamera;
//    后摄像头垂直可视角度(度)
    double FovBackCamera;
//    前摄像头中心线同水平面的夹角(度)
    double inclinationAngleFrontCamera;
//    后摄像头中心线同水平面的夹角(度)
    double inclinationAngleBackCamera;
//    前摄像头距离地面距离
    double heightFrontCamera;
//    后摄像头距离地面距离
    double heightBackCamera;
//    屏幕分辨率横向方向
    double screenWidth;
//    屏幕分辨率纵向方向
    double screenHeight;
//    前摄像头相对于车头中心横向偏移（镜头视角，左负，右正）
    double offsetFrontCamera;
//    后摄像头相对于车头中心横向偏移（镜头视角，左负，右正）
    double offsetBackCamera;
//    车头摄像头到车前轮中心的距离
    double distanceFrontCamera2Axles;
//    车尾摄像头到车后轮中心的距离
    double distanceBackCamera2Axles;
//    车前后轮的轴距
    double distanceAxles;
//    前车轮轴长
    double distanceFrontAxles;
//    后车轮轴长
    double distanceBackAxles;

//    friend QDataStream &operator<<(QDataStream &out, const TrackLineCalibrationST &st)
//    {
//        QByteArray tmp((const char*)&st,sizeof(st));
//        out<<tmp;
//        return out;
//    }
//    friend QDataStream &operator>>(QDataStream &in, TrackLineCalibrationST &st)
//    {
//        QByteArray tmp;
//        in>>tmp;
//        memcpy(&st,tmp.data(),tmp.size());
//        return in;
//    }
};
Q_DECLARE_METATYPE(TrackLineCalibrationST)
// 车辆运营状态上报
struct ReportRoadTaskInfoST {
    uint8_t loadStatus;
    uint8_t workStatus;

    // --> BEGIN deleted by ZJZ, 2022/3/24
//    uint8_t operType;
    // <-- END

    friend QDataStream &operator<<(QDataStream &out, const ReportRoadTaskInfoST &st)
    {
        QByteArray tmp((const char*)&st,sizeof(st));
        out<<tmp;
        return out;
    }
    friend QDataStream &operator>>(QDataStream &in, ReportRoadTaskInfoST &st)
    {
        QByteArray tmp;
        in>>tmp;
        memcpy(&st,tmp.data(),tmp.size());
        return in;
    }
};
// 0x01:空载　0x02:满载 0x03:半载
//0x07：重新停靠, 仅当workStatus为0x04时，有效
/*
0x00:无任务,即任务编号为0时
0x01:道路行驶
0x02:道路预告(开始和电铲或卸点交互) 根据loadStatus判断为装载还是卸载预告
0x03:排队等待
0x04:驶入停靠(获得了V2V驶入许可)
0x05:停靠完成
0x06:装载中
0x07:装载完成
0x08:卸载中
0x09:卸载完成
0x0c:举斗前行
0x0d:装载区驶入完成

// --> BEGIN added by ZJZ, 2022/3/24
0x0e:重新停靠
// <-- END
*/
Q_DECLARE_METATYPE(ReportRoadTaskInfoST)

struct SelfCheckStatusST{
    bool isParking;
    bool isNoPedal;
    bool isCenterSteeringWheel;
    bool isButtonReset;
    friend QDataStream &operator<<(QDataStream &out, const SelfCheckStatusST &st)
    {
        QByteArray tmp((const char*)&st,sizeof(st));
        out<<tmp;
        return out;
    }
    friend QDataStream &operator>>(QDataStream &in, SelfCheckStatusST &st)
    {
        QByteArray tmp;
        in>>tmp;
        memcpy(&st,tmp.data(),tmp.size());
        return in;
    }
};
Q_DECLARE_METATYPE(SelfCheckStatusST)
struct GPSInfoST
{
   uint64_t gps_msec;//UTC时间
   uint32_t gps_rtk_status;//差分状态
   double gps_lat;//纬度
   double gps_lng;//经度
   float gps_heading;//航向角
   float gps_ve;//东向速度
   float gps_vn;//北向速度
   float gps_speed;//合速度
   float height;//海拔
   float acc_y;//纵向加速度
   float acc_x;//横向加速度
   float imu_yaw_z;//横摆角速度
   uint32_t gps_satellite_front;//前天线卫星数
   uint32_t gps_satellite_rear;//后天线卫星数
   float gps_yaw;//偏航
   float gps_roll;//翻滚
   float gps_pitch;//俯仰
   uint16_t gps_diff_flag;//丢差分情况
   float gnss_horizontal_speed;//bestvela输出的水平速度
   uint64_t gps_ntime;//gps数据发布以来以系统时间基准的时间戳
};//GPS消息
Q_DECLARE_METATYPE(GPSInfoST)

#pragma pack()
#endif // FBSSTRUCT_H
