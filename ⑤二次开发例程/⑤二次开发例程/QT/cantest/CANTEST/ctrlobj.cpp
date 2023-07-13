#include "ctrlobj.h"
#include "ui_ctrlobj.h"
#include <QThread>
#define LibECanVci "ECanVci"
byte mbaud;
byte mRTR;
byte mEXT;
long msend=0;
ctrlobj::ctrlobj(QWidget *parent) :QWidget(parent),ui(new Ui::ctrlobj)
{

    ui->setupUi(this);
    MyCANControlThread = new Thread; //定义类对象// MyCANControlThread//就是分配内存空间
    connect(MyCANControlThread,SIGNAL(my_signal(QString)),this,SLOT(deal_my_string(QString)));
}

ctrlobj::~ctrlobj()
{
    if(mconnect==true)
    {
        MyCANControlThread->CloseCANThread();
        MyCANControlThread->stop();//停止子线程
    }
    delete ui;
}
int ctrlobj::hex_str_to_int(unsigned char *ch)
{
    //qDebug("%c%c",ch[0],ch[1]);
    if(ch[0]>='0'&&ch[0]<='9')
    {
        if(ch[1]>='0'&&ch[1]<='9')
            return (((ch[0]-'0')*16)+(ch[1]-'0'));
        if(ch[1]>='a'&&ch[1]<='f')
            return (((ch[0]-'0')*16)+(ch[1]-'a'+10));
        if(ch[1]>='A'&&ch[1]<='F')
            return (((ch[0]-'0')*16)+(ch[1]-'A'+10));
    }
    else if(ch[0]>='a'&&ch[0]<='f')
    {
        if(ch[1]>='0'&&ch[1]<='9')
            return (((ch[0]-'a'+10)*16)+(ch[1]-'0'));
        if(ch[1]>='a'&&ch[1]<='f')
            return (((ch[0]-'a'+10)*16)+(ch[1]-'a'+10));
        if(ch[1]>='A'&&ch[1]<='F')
            return (((ch[0]-'a'+10)*16)+(ch[1]-'A'+10));
    }
    else if(ch[0]>='A'&&ch[0]<='F')
    {
        if(ch[1]>='0'&&ch[1]<='9')
            return (((ch[0]-'A'+10)*16)+(ch[1]-'0'));
        if(ch[1]>='a'&&ch[1]<='f')
            return (((ch[0]-'A'+10)*16)+(ch[1]-'a'+10));
        if(ch[1]>='A'&&ch[1]<='F')
            return (((ch[0]-'A'+10)*16)+(ch[1]-'A'+10));
    }
}

unsigned int ctrlobj::hex_str_to_uint(char*ch_id)
{
    int sum = 0,num=1;
    for(int i=0; i<8; i++,num=1)
    {
        if('0'==ch_id[i])
            continue;

        for(int j=i;j < 7;j++)
            num = num*16;

        if (ch_id[i]>='0'&&ch_id[i]<='9')
        {
            int n = ch_id[i]-'0';
            sum = sum + n*num;
        }
        else if(ch_id[i]>='a'&&ch_id[i]<='f')
            sum += ((int)(ch_id[i]-'a'+10))*num;
        else if(ch_id[i]>='A'&&ch_id[i]<='F')
            sum += ((int)(ch_id[i]-'A'+10))*num;
    }

    return sum;
}


void ctrlobj::on_bt_Connected_clicked()
{

    if (mconnect==false)
    {
        msend=0;
        mbaud =(byte)ui->CB_Baud->currentIndex( );
        MyCANControlThread->OpenCANThread(mbaud);
        MyCANControlThread->start();//启动子线程//间接调用了run()函数//即接收数据
        if(false==IsOpenFlag)//启动设备失败
        {
          QMessageBox msgBox;
          msgBox.setText("打开设备失败!");
        }
        else//启动设备成功
        {
         ui->bt_Connected->setText("断开");//
         mconnect=true;
        }
    }
    else
    {
        MyCANControlThread->CloseCANThread();
        MyCANControlThread->stop();//停止子线程
        ui->bt_Connected->setText("连接");//
        mconnect=false;
    }
}

void ctrlobj::on_BT_Send_clicked()
{

    QString transmit_str = "发送";//定义字符串数据
    transmit_str.append(QString::number(msend,16));
    transmit_str.append("帧ID:");
    transmit_str.append(ui->T_ID->text());//追加字符串//字符串来源于ID号框中
    transmit_str.append("    数据：");//再追加字符串
    transmit_str.append(ui->T_DATA->text());//再追加字符串//字符串来源于数据框中
    ui->textEdit->append(transmit_str);//在显示框中全部显示出来//
   //
    QString str_id = ui->T_ID->text();//获取ID号框中的内容
    QByteArray ba = str_id.toLatin1();//转换成字符串
    char* ch_id = ba.data();//返回指向存储在字节数组中的数据的指针//返回1个指针
    unsigned int id = 0;
    id = hex_str_to_uint(ch_id);
    mRTR=(byte)ui->CB_RTR->currentIndex( );
    mEXT=(byte)ui->CB_EXT->currentIndex( );
    QString str_data = ui->T_DATA->text();//获取数据框中的数据
    unsigned char data_from_text[8];
    unsigned len;
    len=(str_data.length()+1)/3;
    for(int i = 0; i < 8; i++)
    {
        //对于char类型数据，我们获取其十进制表示形式较容易一些，故直接将字符形式转换为整型即可！
        data_from_text[i] = hex_str_to_int((unsigned char *)str_data.section(' ',i,i).trimmed().toStdString().c_str());
    }
    //
    MyCANControlThread->TransmitCANThread(id,(unsigned char *)data_from_text,mEXT,mRTR,len);
}
void ctrlobj::deal_my_string(QString str)//槽函数//子线程(run()函数)结束后由子线程的信号函数(my_signal(QString))触发该函数
{
    ui->textEdit->append(str);//将接收到的内容进行显示
}
