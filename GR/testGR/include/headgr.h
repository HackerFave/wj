#ifndef HEADGR_H
#define HEADGR_H

#include "headGR_global.h"
#include "func.h"
#include "publicclass.h"
#include <QObject>
#include <functional>
#include <map>
#include <iostream>
#include <QMap>
#include <QTimer>
typedef  struct Data485{
    uint8_t data[50];
    int len;
    QString check;
} DATA;
enum TYPE_ID{
    encoder_x1 = 0,
    encoder_x2,
    accel_x1,
    accel_x2
};

using FuncCall = std::function<void (TYPE_ID id,int32_t)>;
class HEADGR_EXPORT HeadGR:public QObject
{
    Q_OBJECT
public:
    HeadGR();
    void setOffsetAngle(uint8_t ID,int16_t angle);//设置0偏移角
    void initAccel(uint8_t ID ,int32_t accel);//设置加速度
    void setTurnAngle(uint8_t ID,int32_t angle,uint32_t speed);//设置转动角度
    void regeditCallBack(FuncCall fun);/*注册回调函数*/
    void getEncoder(uint8_t id);
    void getAccel(uint8_t ID);
    void clearError(uint8_t ID);
    void clearAngle(uint8_t ID);
private slots:
    void slotData(QString data);
    void slotInitData();
    void slotReadAngle();
signals:
private:
    func * P_func = nullptr;
    FuncCall _funCall;
    QQueue <DATA> _que;
    QTimer _timerInitData;
    QTimer _timerReadAngle;;
    int32_t _angleX1 = 0;
    int32_t _angleX2 = 0;
};

#endif // HEADGR_H
