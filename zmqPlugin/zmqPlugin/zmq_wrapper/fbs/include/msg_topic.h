// this file is a temp version for debugging

#ifndef __TOPIC_H_
#define __TOPIC_H_

// gps_info.fbs
#define TOPIC_TCP_GNSS_GPS_INFO             "tcp/gnss/gps_info"                 //GpsImuInfo
#define TOPIC_TCP_GNSS_RBOX_INFO            "tcp/gnss/rbox_info"                 //GpsImuInfo
#define TOPIC_TCP_GNSS_GPS_STATUS           "tcp/gnss/gps_status"               //GpsStatus
#define TOPIC_HUAWEI_GNSS_BROADCAST_DATA    "tcp/gnss/HuaWeiGnssBroadcastData"  //MsgVector


//voiceServer
#define TOPIC_HMI_SEND_VOICE_PLAY           "tcp/voice/HmiSendVoicePlay"        //MsgVoiceName


// v2xServer
#define TOPIC_CV2X_COll_WARNING             "tcp/v2x/msg_8401"                  //NULL
#define TOPIC_CV2X_SURROUND_VEHICLE         "tcp/v2x/msg_8402"                  //Msg8402
#define TOPIC_CV2X_SURROUND_VEHICLE_PLUS    "tcp/v2x/msg_8402_plus"             //Msg8402_plus ccu使用
#define TOPIC_CV2X_SEND_GNSS_RTK_DATA       "tcp/v2x/send_gnss_rkt_data"        //Message
#define TOPIC_CV2X_SEND_ICU_OBSTACLE_INFO_DATA       "tcp/v2x/icu_obstacle_info_data"        //ICU障碍物信息（rsu）
//这条原来为1.CGU收到之后重新组一个8306给HMI 现在由HMI订阅此消息当作8306
//2.CGU收到以后判断时间发一个8307给HMI和CCU
#define TOPIC_CV2X_AUX_RESP_JOB_SCHED_DATA  "tcp/v2x/aux_resp_job_sched_data"   //Msg8305_V2X
#define TOPIC_CV2X_TRUCK_REQ_JOB_SCHED_DATA "tcp/v2x/truck_req_job_sched_data"  //NULL


//tcpClient
//func_msg.fbs
#define TCP_SEND_TO_CLOUD_REDUNDANCY        "tcp/tcp/cloud2tcp"                 //Message

//auxCan
#define AUXCAN_SEND_BUCKET_ANGLE            "tcp/auxcan/bucketAngle"            //MsgBucketAngle

//cloudServer
#define CLOUD_SEND_TO_TCP_REDUNDANCY        "tcp/cloud/tcp2cloud"               //Message
#define CLOUD_SEND_REQ_WORK_STATUS_ACK      "tcp/cloud/msg_8C01"                //Msg8C01
#define CLOUD_SEND_OPR_STATUS_CHANGE        "tcp/cloud/msg_8F02"                //Msg8F02
#define CLOUD_SEND_MATER_CHANGE             "tcp/cloud/msg_8F04"                //Msg8F04
#define CLOUD_SEND_CHANGE_TEMP_TASK_FILE    "tcp/cloud/msg_8F0D"                //Msg8F04
#define CLOUD_SEND_DOWNLOAD_FILE            "tcp/cloud/msg_8F0A"                //Msg8F0A
#define CLOUD_SEND_REMOTE_CONTROL           "tcp/cloud/msg_8F09"                //Msg8F09
#define CLOUD_SEND_DOCKING_GROUP            "tcp/cloud/msg_8B01"                //Msg8B01
#define CLOUD_SEND_WAITING_IN_LINE          "tcp/cloud/msg_8B03"                //Msg8B03
#define CLOUD_SEND_CLEAR_FAULT              "tcp/cloud_hmi/msg_0F0E"            //Msg0F0E 0F0E这条HMI也会发 hmi||cloud -> ccu
#define CLOUD_SEND_RESP_EXIT                "tcp/cloud/msg_8105"                //Msg8105
#define CLOUD_SEND_RESP_SIGN_IN             "tcp/cloud/msg_8B10"                //Msg8B10
#define CLOUD_SEND_RESP_SIGN_OUT            "tcp/cloud/msg_8B11"                //Msg8B11
#define CLOUD_SEND_PACK_SPACE_CLEAN         "tcp/cloud/msg_83E4"                //Msg83E4
#define CLOUD_SEND_REQ_LOAD_JOB             "tcp/cloud/msg_8307"                //Msg8307
#define CLOUD_SEND_REQ_UNLOAD_JOB           "tcp/cloud/msg_8308"                //Msg8308
#define CLOUD_SEND_UPLOAD_TRIGGER           "tcp/cloud_hmi/msg_0502"            //Msg0502
#define CLOUD_SEND_HMI_UPLOAD_RESULT        "tcp/cloud/msg_0F0B"                //Msg0F0B
#define CLOUD_SEND_CGU_VERSION              "tcp/cloud/cgu_version"             //MsgCguVersion
#define CLOUD_SEND_DEV_NAME                 "tcp/cloud/msg_1040"                //Msg1040
#define CLOUD_SEND_RES_TASK_FILE            "tcp/cloud/msg_8F0C"                //Msg8F0C
#define CLOUD_SEND_TASKFILE_TO_MAPENGINE    "tcp/cloud/msg_taskfileOK"          //Message
#define CLOUD_SEND_BOUNDARY_TO_MAPENGINE    "tcp/cloud/msg_boundaryfileOK"      //Message
#define CLOUD_SEND_RegionalBD_TO_MAPENGINE  "tcp/cloud/msg_RegionalBoundaryfileOK" //Message
#define CLOUD_SEND_RES_MOVEAUTHORITY        "tcp/cloud/msg_8F0F"                //Msg8F0F
#define CLOUD_SEND_RES_REGIONALBOUNDARY     "tcp/cloud/msg_8F10"                //Msg8F10
#define CLOUD_SEND_HMI_WARNING_STATUS       "tcp/cloud/warnstat"                //MsgVechWarnStat
#define CLOUD_SEND_HMI_RES_POINT_ID         "tcp/cloud/msg_8F07"                //Msg8F07
#define CLOUD_SEND_MEET_VEHICLE_INFO        "tcp/cloud/msg_8E01"                //Msg8E01
#define CLOUD_SEND_V2NRSU_STAT              "tcp/cloud/msg_v2xrsu_stat"         //MsgV2nRsuStat
#define CLOUD_SEND_Msg8FEF                  "tcp/cloud/Msg8FEF"                 //Msg8FEF 行车模式
#define CLOUD_SEND_Msg8F2F                  "tcp/cloud/detour"                  //DetourMsg 避障绕行
#define CLOUD_SEND_Msg8E2E                  "tcp/cloud/Msg8E2E"                 //Msg8E2E 物料信息
#define CLOUD_SEND_Msg81BE                  "tcp/cloud/Msg81BE"                 //平台下发灯光控制
#define CLOUD_SEND_Msg8FEC                  "tcp/cloud/Msg8FEC"                 //平台下发作业区状态指令

#define CLOUD_SEND_Msg8302                  "tcp/cloud/Msg8302"                 //Msg8302   平台存疑产量结果应答


// can_info.fbs
#define TOPIC_CAN_WIRE_CONTROL_FAULT        "tcp/can/wire_control_fault"        //WireControlVehicleFault
#define TOPIC_CAN_WIRE_CONTROL_MOVATION     "tcp/can/wire_control_movation"     //WireControlVehicleMovation
#define TOPIC_CAN_WIRE_CONTROL_STATUS       "tcp/can/wire_control_status"       //WireControlVehicleStatus
#define TOPIC_CAN_WIRE_CONTROL_VCU_VER      "tcp/can/wire_control_vcu_ver"      //WireControlVcuVersion
#define TOPIC_CAN_DEV_STATUS                "tcp/can/can_about_dev_status"      //CanAboutDevStatus


// version.fbs
#define TOPIC_VERSION_VCU_REQ               "tcp/version/vcu/req"               //NULL
#define TOPIC_VERSION_VCU                   "tcp/version/vcu"                   //MsgVersion
#define TOPIC_VERSION_ICU_REQ               "tcp/version/icu/req"               //NULL
#define TOPIC_VERSION_ICU                   "tcp/version/icu"                   //MsgVersion
#define TOPIC_VERSION_CCU_REQ               "tcp/version/ccu/req"               //NULL
#define TOPIC_VERSION_CCU                   "tcp/version/ccu"                   //MsgVersion
#define TOPIC_VERSION_HMI_REQ               "tcp/version/hmi/req"               //NULL
#define TOPIC_VERSION_HMI                   "tcp/version/hmi"                   //MsgVersion
#define TOPIC_VERSION_RCGU_REQ              "tcp/version/rcgu/req"              //NULL
#define TOPIC_VERSION_RCGU                  "tcp/version/rcgu"                  //MsgVersion

// ota.fbs
#define TOPIC_OTA_STATE                      "ipc/ota/State"                     //OTA运行状态
#define TOPIC_OTA_STATE_RES                  "ipc/ota/StateRes"                   //OTA运行状态响应
#define TOPIC_OTA_INSTALL_STATE		         "tcp/ota/InstallState"              //OTA发布安装状态
#define TOPIC_OTA_REQ_HOST_VERSION           "ipc/ota/ReqHostVersion"            //OTA请求版本号
#define TOPIC_HOST_VERSION                   "ipc/host/version"                   //业务发布版本号

// control.fbs
#define TOPIC_CONTROL_IMPLEMENT             "tcp/control/control_implement"     //ControlOutputForImplement
#define TOPIC_CONTROL_DECISION              "tcp/control/control_decision"      //ControlOutputForDecision


//decision.fbs
#define TOPIC_DECISION_OUTPUT               "tcp/decision/output"               //Output
#define TOPIC_DECISION_VEHICLE_INFO         "tcp/decision/vehicle_info"         //RoadTaskVehicleInfo
#define TOPIC_DECISION_STARTUP_CMD          "tcp/decision/msg_1030"             //Msg1030
#define TOPIC_DECISION_SHUTDOWN_CMD         "tcp/decision/msg_1050"             //Msg1050
#define TOPIC_DECISION_MSG2062              "tcp/decision/msg_2062"             //Msg2062
#define TOPIC_DECISION_MANUAL_DRV_REQ       "tcp/decision/msg_0404"             //Msg0404
#define TOPIC_DECISION_TASK_EVENT           "tcp/decision/msg_0500"             //Msg0500
#define TOPIC_DECISION_MSG0501              "tcp/decision/msg_0501"             //Msg0501
#define TOPIC_DECISION_FAULT_STATUS         "tcp/decision/msg_8F0E"             //Msg8F0E ccu -> HMI&&cloud
#define TOPIC_DECISION_TEST_RESULT          "tcp/decision/msg_8F1C"             //Msg8F1C
#define TOPIC_DECISION_MSG0E02              "tcp/decision/msg_0E02"             //V2HMIMsg0E02
#define TOPIC_DECISION_ROADPLAN_POINTS      "tcp/decision/roadplan_points"      //RoadPlanPoint
#define TOPIC_DECISION_NEARBY_PATH          "tcp/decision/nearby_path_info"     //OutNearbyPoint
// cgu_protocol.fbs
#define TOPIC_DECISION_MSG0503              "tcp/decision/msg_0503"             //Msg0503


// prediction.fbs
#define TOPIC_PREDICTION_SENSE_RESULT           "tcp/prediction/sense_result"       // SenseResultInfo msg_0402
#define TOPIC_PREDICTION_VEHICLE_TRAJECTORY     "tcp/prediction/vehicle_trajectory"
#define TOPIC_PREDICTION_OBSTACLE_INFO          "tcp/prediction/obstacle_info"

//diagnosis.fbs
#define TOPIC_DIAGNOSIS_FAULT_CODE          "tcp/diagnosis/fault_code"          //WarningOutput
#define TOPIC_DIAGNOSIS_MSG0E01             "tcp/diagnosis/msg_0E01"            //V2HMIMsg0E01


// icu_info.fbs
#define TOPIC_ICU_BOUNDARY_FRONT            "tcp/icu/boundary_info/front"       //MsgIcuBoundary
#define TOPIC_ICU_BOUNDARY_REAR             "tcp/icu/boundary_info/rear"        //MsgIcuBackwardBoundary
#define TOPIC_ICU_OBSTACLE_FRONT            "tcp/icu/obstacle_info/front"       //MsgIcuObstacle
#define TOPIC_ICU_OBSTACLE_REAR             "tcp/icu/obstacle_info/rear"        //MsgIcuObstacle
#define TOPIC_ICU_OBSTACLE_FRONT_TEST       "ipc/icu/obstacle_info/front"       //MsgIcuObstacle
#define TOPIC_ICU_OBSTACLE_REAR_TEST        "ipc/icu/obstacle_info/rear"        //MsgIcuObstacle
#define TOPIC_ICU_SENSOR_STATUS             "tcp/icu/sensor_status"             //sendHeartBeats
#define TOPIC_ICU_OBSTACLERCU_FRONT         "tcp/icu/obstaclercu_info/front" // MsgIcuObstacle

//　sensor_data.fbs
#define TOPIC_FRAME_NUM                      "ipc/icu/frame_num"                //FrameNumT wly
#define TOPIC_BACK_HEART_BEATS               "ipc/icu/back_heart_beats"         //MsgBackHeartBeats
#define TOPIC_FRONT_SENSOR_DATA              "ipc/icu/front_sensor_data"        //MsgFrontSensorData
#define TOPIC_BACK_SENSOR_DATA               "ipc/icu/back_sensor_data"         //MsgBackSensorData
#define TOPIC_FRONT_SENSOR_DATA_RECORD       "tcp/icu/front_sensor_data"        //MsgFrontSensorData
#define TOPIC_BACK_SENSOR_DATA_RECORD        "tcp/icu/back_sensor_data"         //MsgBackSensorData

//at.fbs
#define TOPIC_AT_CSQ                        "tcp/at/csq"                        //ATMsg
#define TOPIC_AT_CSQ_TBOX                   "tcp/at/csq_tbox"                   //ATMsg
#define TOPIC_REQ_IMEI                      "tcp/at/reqimei"                    //Message
#define TOPIC_RESP_IMEI                     "tcp/at/respimei"                   //Message
#define TOPIC_REQ_IMEI_TBOX                 "tcp/at/reqimeitbox"                //Message
#define TOPIC_RESP_IMEI_TBOX                "tcp/at/respimeitbox"               //Message
#define TOPIC_REQ_AUTH                      "tcp/at/reqauth"                    //Message
#define TOPIC_RESP_AUTH                     "tcp/at/respauth"                   //FuncTcpAuth
#define TOPIC_REQ_AUTH_TBOX                 "tcp/at/reqauthtbox"                //Message
#define TOPIC_RESP_AUTH_TBOX                "tcp/at/respauthtbox"               //FuncTcpAuth


//hmi
#define TOPIC_HMI_MSG0F1C                   "tcp/hmi/Msg0F1C"                   //Msg0F1C HMI触发测试任务Msg0F1C
#define TOPIC_HMI_MSG8403                   "tcp/hmi/Msg8403"                   //Msg8403 HMI发送给网关设置矿卡空满载状态Msg8403
#define TOPIC_HMI_MSG8F0B                   "tcp/hmi/Msg8F0B"                   //Msg8F0B Hmi生成文件后，需要车上传平台，通过该命令将文件上传网关Msg8F0B
#define TOPIC_HMI_MSG0F01                   "tcp/hmi/Msg0F01"                   //Msg0F01 HMI发送网关营运状态变更请求命令 Msg0F01
#define TOPIC_HMI_MSG0F10                   "tcp/hmi/Msg0F10"                   //Msg0F10 HMI触发登录
#define TOPIC_HMI_MSG0F11                   "tcp/hmi/Msg0F11"                   //Msg0F11 HMI触发登出


//新增hmi
#define TOPIC_HMI_MsgTx_0104                "tcp/hmi/MsgTx_0104"                //MsgTx_0104 说明：服务器参数查询，消息体为空 适配：所有车辆
#define TOPIC_HMI_MsgTx_0F03                "tcp/hmi/MsgTx_0F03"                //MsgTx_0F03 说明：物料变更申请  适配：辅助车辆-电铲
#define TOPIC_HMI_MsgTx_0F09                "tcp/hmi/MsgTx_0F09"                //MsgTx_0F09 说明：行车报警 适配：矿卡/宽体车
#define TOPIC_HMI_MsgTx_8305                "tcp/hmi/MsgTx_8305"                //MsgTx_8305 说明：作业场调度控制命令上报 适配：辅助车辆-电铲
#define TOPIC_HMI_MsgTx_8B02                "tcp/hmi/MsgTx_8B02"                //MsgTx_8B02 说明：发送digger就位命令 适配：辅助车辆-推土机digger
#define TOPIC_HMI_MsgTx_8E03                "tcp/hmi/MsgTx_8E03"                //MsgTx_8E03 说明：发送停靠位分组清理状态命令 适配：辅助车辆-推土机digger
#define TOPIC_HMI_MsgTx_8E04                "tcp/hmi/MsgTx_8E04"                //MsgTx_8E04 说明：发送停靠位分组状态操作命令 适配：辅助车辆-推土机digger
#define TOPIC_HMI_MsgTx_8B07                "tcp/hmi/MsgTx_8B07"                //MsgTx_8B07 说明：装载区停靠位位置上报 适配：辅助车辆-电铲
#define TOPIC_HMI_MsgTx_8B08                "tcp/hmi/MsgTx_8B08"                //MsgTx_8B08 说明：装载区停靠位状态操作指令上报 适配：辅助车辆-电铲
#define TOPIC_HMI_MsgTx_83E5                "tcp/hmi/MsgTx_83E5"                //MsgTx_8BE5 说明：装载区通知电铲二次指点 适配：辅助车辆-电铲
#define TOPIC_HMI_MsgTx_8C02                "tcp/hmi/MsgTx_8C02"                //MsgTx_8C02 说明：装载区通知电铲矿卡驶入驶离 适配：辅助车辆-电铲
#define TOPIC_HMI_MsgTx_0002                "tcp/hmi/MsgTx_0002"                //Msg8105 HMI发出的心跳 5s一包 CGU订阅判断连接状态
#define TOPIC_HMI_MsgTx_0F0F                "tcp/hmi/MsgTx_0F0F"                //MsgTx_0F0F 说明：HMI发送主控采集地图标志  0X01:开始采集 0X02:结束采集 MsgTx_0F0F
//add hmi topic to rcd
#define TOPIC_HMI_TO_RCD                    "tcp/hmi/MsgToRcd"                  //NULL
#define TOPIC_HMI_HINTMSG_TO_RCD            "tcp/hmi/HintMsgToRcd"              //HintMessageFromHMI           HMI提示信息转发给RCD
#define TOPIC_HMI_SEND_Msg8E0E                  "tcp/hmi/Msg8E0E"                 //HMI查询物料编码

#define TOPIC_HMI_Msg8301               "tcp/hmi/Msg8301"                  //Msg8301   电铲向平台发送存疑产量查询
#define TOPIC_HMI_Msg8303               "tcp/hmi/Msg8303"                  //Msg8303   电铲确认产量有效应答

//rcd
#define TOPIC_RCD_REQ_REMOTE_CONTROL        "tcp/rcd/req_remote_control"        //Msg2060
#define TOPIC_RCD_REPORT_RABBITMQ_STATUS    "tcp/rcd/report/rabbitmq_status"    //MsgRabbitMQStatus
#define TOPIC_RCD_PUSH_CONTROL_REQ          "tcp/rcd/push_control_req"
#define TOPIC_RCD_PUSH_CONTROL_RESP         "tcp/rcd/push_control_resp"
#define TOPIC_RCD_TAKEOVER_TASK_CMD         "tcp/rcd/takeover_task_cmd"
#define TOPIC_RCD_SEND_ESTOP_CMD            "tcp/rcd/send_estop_cmd"            //MsgRcdSendEStop

//map_info.fbs
#define TOPIC_MAP_ROADINFO_INIT             "tcp/map/roadinfo/init"             //MapRoadListInfo
#define TOPIC_MAP_LANEINFO_INIT             "tcp/map/laneinfo/init"             //MapLaneListInfo
#define TOPIC_MAP_BOUNDARYINFO_INIT         "tcp/map/boundaryinfo/init"         //MapBoundaryListInfo
#define TOPIC_MAP_ROADCENTERLANEINFO_INIT   "tcp/map/roadcenterlaneinfo/init"   //MapRoadCenterListInfo
#define TOPIC_MAP_ROADISOLATIONINFO_INIT 	"tcp/map/roadisolationinfo/init"   	//MapRoadIsolationListInfo


#define TOPIC_MAP_ROADINFO_UPDATE           "tcp/map/roadinfo/update"           //NULL
#define TOPIC_MAP_LANEINFO_UPDATE           "tcp/map/laneinfo/update"           //NULL
#define TOPIC_MAP_BOUNDARYINFO_UPDATE       "tcp/map/boundaryinfo/update"       //NULL
#define TOPIC_MAP_ROADCENTERLANEINFO_UPDATE "tcp/map/roadcenterlaneinfo/update" //NULL
#define TOPIC_MAP_ROADISOLATIONINFO_UPDATE 	"tcp/map/roadisolationinfo/update"  //NULL


#define TOPIC_MAP_ROADINFO_RESPONSE         "tcp/map/roadinfo/response"         //MapRoadListInfo
#define TOPIC_MAP_LANEINFO_RESPONSE         "tcp/map/laneinfo/response"         //MapLaneListInfo
#define TOPIC_MAP_BOUNDARYINFO_RESPONSE     "tcp/map/boundaryinfo/response"     //MapBoundaryListInfo
#define TOPIC_MAP_ROADCENTERLANEINFO_RESPONSE "tcp/map/roadcenterlaneinfo/response" //MapRoadCenterListInfo
#define TOPIC_MAP_ROADISOLATIONINFO_RESPONSE "tcp/map/roadisolationinfo/response"   //MapRoadIsolationListInfo


#define TOPIC_MAP_TASK          			"tcp/map/task"                      //MapTaskInfo

#define TOPIC_MAP_OBSTACLE_APPLY 	"tcp/map/obstacle/apply" 			// MapObstacleApply
#define TOPIC_MAP_OBSTACLE 					"tcp/map/obstacle" 					// MapObstacle

#define TOPIC_MAP_ROADINFO_APPLY            "tcp/map/roadinfo/apply"            //MapApply
#define TOPIC_MAP_LANEINFO_APPLY            "tcp/map/laneinfo/apply"            //MapApply
#define TOPIC_MAP_BOUNDARYINFO_APPLY        "tcp/map/boundaryinfo/apply"        //MapApply
#define TOPIC_MAP_ROADCENTERLANEINFO_APPLY  "tcp/map/roadcenterlaneinfo/apply"  //MapApply
#define TOPIC_MAP_ROADISOLATIONINFO_APPLY 	"tcp/map/roadisolationinfo/apply"   //MapApply

#define TOPIC_DOCKMAP_APPLY                 "tcp/dockmap/apply"                 //DockMapApply
#define TOPIC_DOCKMAP_INIT                  "tcp/dockmap/init"                  //DockMapInit
#define TOPIC_DOCKMAP_RESPONSE              "tcp/dockmap/response"              //DockMapResponse

//redudance
#define TOPIC_HEARTBEAT_TO_CCU    "tcp/rbox/heartbeattoccu" // HeartBeatToCCU

/******************************* req-rep *******************************/

//AT topic for req-rep
#define TOPIC_AT_REQ_REP_MSG                    "at_req_rep_msg"
#define TOPIC_AT_REQ_REP_MSG_TBOX               "at_req_rep_msg_tbox"
//call function name define
#define FUNC_AT_GET_IMEI                        "getImei"
#define FUNC_AT_GET_ICCID                       "getIccid"
#define FUNC_AT_SEND_ATCMD                      "SendAtCmd"
#define FUNC_AT_SEND_ATCMD_WITH_EXPECT          "SendAtCmdWithExpect"

//v2x topic for req-rep
#define TOPIC_V2X_REQ_REP_MSG                   "v2x_req_rep_msg"
#define TOPIC_V2X_REQ_REP_MSG_TBOX              "v2x_req_rep_msg_tbox"
//call function name define
#define FUNC_V2X_SEND_RTK_DATA                  "V2xSendRTKData"
#define FUNC_V2X_SEND_RSU_CLOUD_DATA            "V2xSendRsuCloudData_v2x"
#define FUNC_V2X_LINK_STATUS                    "LinkStatus"

//cloud topic for req-rep
#define TOPIC_CLOUD_REQ_REP_MSG                 "cloud_req_rep_msg"
#define TOPIC_CLOUD_REQ_REP_MSG_TBOX            "cloud_req_rep_msg_tbox"
#define TOPIC_TCP_REQ_REP_MSG                   "tcp_req_rep_msg"
#define TOPIC_TCP_REQ_REP_MSG_TBOX              "tcp_req_rep_msg_tbox"
//call function name define
#define FUNC_TCP_SEND_V2X_MSG                   "CloudSendV2xMsg"//这个没有做实现 应该没用了 dds改成post吧
#define FUNC_TCP_GET_AUTH                       "GetTcpAuthStat"//FuncMsg -> FuncTcpAuth
#define FUNC_CLOUD_GET_LOCAL_NAME               "GetLocalName"
//#define FUNC_CLOUD_SEND_V2X_MSG                 "CloudSendV2xMsg"
#define FUNC_CLOUD_GET_ALL_DEV_NAME             "GetAllDevName"//FuncMsg -> FuncCloudGetAllDevName
#define FUNC_CLOUD_GET_CGU_VERSION              "GetCGUVersion"//FuncMsg -> MsgCguVersion

//rsu topic for req-rep
#define TOPIC_RSU_REQ_REP_MSG                   "rsu_req_rep_msg"
#define FUNC_RSU_CLOUD_SEND_RSU_V2X_DATA        "CloudSendRsuV2xData"
#define FUNC_RSU_V2X_SEND_RSU_CLOUD_DATA        "V2xSendRsuCloudData_rsu"
#define FUNC_RSU_LINK_STATUS                    "LinkStatus"

//bar topic for req-rep
#define TOPIC_BARREQUEST_SEND_TO_CLOUD          "ipc/bar/request_to_cloud"
#define TOPIC_BARSTATE_SEND_TO_CLOUD            "ipc/bar/state_to_cloud"
#define TOPIC_BARRESPONSE_FROM_CLOUD            "ipc/bar/response_from_cloud"
#define TOPIC_BAT_SEND_TO_CLOUD                 "ipc/bar/bat_to_cloud"

//gnssRtk topic req-rep
#define TOPIC_GNSSRTK_REQ_REP_MSG               "gnssrtk_req_rep_msg"
#define FUNC_GNSSRTK_LINK_STATUS                "LinkStatus"

//huawei topic req-rep
#define TOPIC_HUAWEI_REQ_REP_MSG                "huawei_req_rep_msg"
#define TOPIC_HUAWEI_REQ_REP_MSG_TBOX           "huawei_req_rep_msg_tbox"
#define FUNC_HW_SEND_MSG_TO_HUAWEI              "SendV2XMsgToHuawei"

/******************************* req-rep end *******************************/

#endif  // __TOPIC_H_
