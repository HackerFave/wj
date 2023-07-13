#ifndef START_H
#define START_H

#include <QMainWindow>
#include "ControlCAN.h"
#include <QFile>
#include <QTimer>
#include <QLabel>
#include <QStandardItemModel>
#include <QMap>
#include "qcustomplot.h"

const UCHAR Bsp[17][2]={{0x31,0x1C},{0x18,0x1C},{0x87,0xFF},{0x09,0x1C},{0x83,0xFF},
                   {0x04,0x1C},{0x03,0x1C},{0x81,0xFA},{0x01,0x1C},{0x80,0xFA},
                   {0x00,0x1C},{0x80,0xB6},{0x00,0x16},{0x00,0x14},{0x09,0x6F},
                   {0x04,0x6F},{0x03,0x6F}};



namespace Ui {
class start;
}

class start : public QMainWindow
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr);
    ~start();
    QString hex2Str(unsigned char *in, int len);
    float hex2Float(unsigned char *m);
    QString hex2StrFloat(unsigned char *m);
    void Str2CharSplitBlank(QString s,uchar *c,uchar *len);
    void RealTimeUpdateMsg();
    void PlotViewUpdate(UINT id, BYTE *data);//波形更新
    void StartInit();
    QList<QStandardItem*> AddRowRecv(PVCI_CAN_OBJ Recv,QString *rowstr);
    QList<QStandardItem*> AddRowSend(QString sendstr,uchar len,QString *rowstr);
    void SaveData2File(QFile *file,QString msg);
    double GetX();


private slots:
    void on_OpenDev_Btn_clicked();
    void on_CloseDev_Btn_clicked();
    void on_Send_Btn_clicked();
    void on_clear_Btn_clicked();
    void on_RealStore_Chek_clicked(bool checked);
    void on_AutoSend_Chek_clicked(bool checked);

    void on_checkBox_Rpm_clicked(bool checked);
    void on_checkBox_Volt_clicked(bool checked);
    void on_checkBox_Current_clicked(bool checked);

private:
    Ui::start *ui;
    QTimer *mtimer;
    QTimer *AutoSendTimer;
    QLabel *SendCntlab;
    QLabel *RecvCntlab;
    uint SendCnt=0; //发送
    uint RecvCnt=0;
    DWORD m_DevType;
    DWORD m_DevIndex;
    DWORD m_CanIndex;
    DWORD m_nDevType;
    QStandardItemModel *theModel;
    QString filename;
    QFile *file;
    //----------//
    QMap<QString,QCPGraph*> graphMap;
    double timeStamp=0;
};

#endif // START_H
