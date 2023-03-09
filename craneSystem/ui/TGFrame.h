#ifndef TGFrame_H
#define TGFrame_H

#include <QWidget>
#include <QPaintEvent>

class TGFrame : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(TGFrameType frameType READ frameType WRITE setFrameType)

public:

    enum TGFrameType {
        InfoFrame = 1000,
        InfoFrameLeftPage1No1 = 1111,    //行车地图边框
        InfoFrameLeftPage2No1 = 1121,    //行车地图边框
        InfoFrameRightPage1No1 = 1311,   //矿卡数据边框
        InfoFrameRightPage1No2 = 1312,   //异常信息边框
        InfoFrameRightPage2No1 = 1321,   //车辆信息边框
        InfoFrameRightPage2No2 = 1322,   //任务信息边框
        InfoFrameRightPage2No3 = 1323,   //操作信息边框
        InfoFrameRightPage2No4 = 1324,   //系统信息边框
        InfoFrameRightPage2No5 = 1325,   //接管信息边框
        InfoFrameRightPage2No6 = 1326,   //装载指令边框
        InfoFrameRightPage2No7 = 1327,   //右摄像头系统信息边框
        InfoFrameRightPage2No8 = 1328,   //右摄像头下行车地图边框
        InfoFrameRightPage2No9 = 1329,   //左摄像头故障信息边框
        InfoFrameRightPage2No10 = 1330,   //左摄像头车辆数据边框

        VideoFrame = 2000 ,
        VideoFrameLeftPage2No1 = 2121,   //驾驶舱摄像头边框
        VideoFrameLeftPage2No2 = 2122,   //左摄像头边框
        VideoFrameMidPage1No1 = 2211,    //视频未选中边框
        VideoFrameMidPage1No2 = 2212,    //视频选中边框
        VideoFrameMidPage2No1 = 2221,    //画中画摄像头边框在线
        VideoFrameMidPage2No2 = 2231,    //画中画摄像头边框离线
        VideoFrameRightPage2No1 = 2321,  //右摄像头边框

        Shadow = 3000 ,
        ShadowLeftPage2No1 = 3121,       //驾驶舱摄像头阴影
        ShadowLeftPage2No2 = 3122,       //左摄像头阴影
        ShadowMidPage1No1 = 3211,        //枚举摄像头阴影
        ShadowMidPage2No1 = 3221,        //画中画摄像头阴影
        ShadowRightPage2No1 = 3321,      //右摄像头阴影

        Tip = 4000,
        TipUnderline = 4001,
        None = 5000,
    };
    //Q_ENUM(TGFrameType)

    explicit        TGFrame(QWidget *parent = nullptr,TGFrameType type = None);
    void            setFrameType(TGFrameType);
    TGFrameType     frameType();
    void            setTitleString(QString);

protected:

    virtual void paintEvent(QPaintEvent *) override;

private:

    void         drawInfoFrame(QPainter &);
    void         drawFrame(QPainter &);
    void         drawTip(QPainter &);

    QPixmap        m_frameImage;
    TGFrameType    m_frameType;
    QString        m_titleStr;
    bool           m_isShowTitle;

};

#endif // TGFrame_H
