#ifndef VIEWSHOWFORM_H
#define VIEWSHOWFORM_H

#include <QWidget>
#include "methord/qcustomplot.h"
#include "public/publicclass.h"
#include <QTimer>
namespace Ui {
class viewShowForm;
}

class viewShowForm : public QWidget
{
    Q_OBJECT

public:
    explicit viewShowForm(QWidget *parent = nullptr);
    ~viewShowForm();

    double GetX();
    /*******************************/

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);

private:
    float m_t = 0, m_x = 0, m_y = 0;
    int m_k = 10;
    /*******************************/
private slots:
//    void on_checkBox_Rpm_stateChanged(int arg1);

//    void on_checkBox_Volt_stateChanged(int arg1);

//    void on_checkBox_Current_stateChanged(int arg1);
    void on_checkBox_allShow_clicked(bool checked);

    void Init();    //初始化

    void Draw();    //绘制曲线
    void slotDraw();//绘图
private slots:


    //    void on_colorButton_clicked();              //颜色按钮槽函数

    //    void on_slider_sliderMoved(int position);   //滑动条槽函数

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_clicked();

public slots:
    void slotPlotViewUpdate(UINT id, BYTE *data);

private:
    Ui::viewShowForm *ui;
    //----------//
    QMap<QString,QCPGraph*> graphMap;
    int64_t _timeStamp=0;
    QTimer _timer;
    ///////////////////////////////////
    qreal k = 0;              //笛卡尔心形函数参数
    QPen pen;
    QVector<qreal> x,y;
    QVector<qreal> x1,y1;


};

#endif // VIEWSHOWFORM_H
