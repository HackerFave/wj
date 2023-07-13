//#include "mainwindow.h"
//#include "ui_mainwindow.h"

//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include "ctaudioplayer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init()
{
    ui->radioButton_TCP->setChecked(false);
    ui->radioButton_UDP->setChecked(true);
}

void MainWindow::on_btn_play_clicked()
{
    QString sUrl = ui->lineEdit_Url->text();
    if(sUrl.isEmpty())
    {
        QMessageBox::critical(this, "myFFmpeg", "错误:实时流url不能为空.");
        return;
    }

    if(nullptr == m_pMediaThread)
    {
        MY_DEBUG << "new MediaThread";
        m_pMediaThread = new MediaThread;
    }
    else
    {
        if(m_pMediaThread->isRunning())
        {
            QMessageBox::critical(this, "myFFmpeg", "错误:请先点击停止按钮关闭视频.");
            return;
        }
    }

    connect(m_pMediaThread, SIGNAL(sig_emitImage(const QImage&)),
            ui->openGLWidget, SLOT(slot_showImage(const QImage&)));

    bool bMediaInit = false;
    if(ui->radioButton_TCP->isChecked())
    {
        bMediaInit = m_pMediaThread->Init(sUrl, PROTOCOL_TCP);
    }
    else
    {
        bMediaInit = m_pMediaThread->Init(sUrl, PROTOCOL_UDP);
    }

    if(bMediaInit)
    {
        m_pMediaThread->startThread();
    }
}

void MainWindow::on_btn_open_clicked()
{
    QString sFileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择视频文件"));
    if(sFileName.isEmpty())
    {
        QMessageBox::critical(this, "myFFmpeg", "错误:文件不能为空.");
        return;
    }

    ui->lineEdit_File->setText(sFileName);

}

void MainWindow::on_btn_play2_clicked()
{
    QString sFileName = ui->lineEdit_File->text();
    if(sFileName.isEmpty())
    {
        QMessageBox::critical(this, "myFFmpeg", "错误:文件不能为空.");
        return;
    }

    if(nullptr == m_pMediaThread)
    {
        m_pMediaThread = new MediaThread;
    }
    else
    {
        if(m_pMediaThread->isRunning())
        {
            QMessageBox::critical(this, "myFFmpeg", "错误:请先点击停止按钮关闭视频.");
            return;
        }
    }

    connect(m_pMediaThread, SIGNAL(sig_emitImage(const QImage&)),
            ui->openGLWidget, SLOT(slot_showImage(const QImage&)));

    if(m_pMediaThread->Init(sFileName))
    {
        m_pMediaThread->startThread();
    }
}

void MainWindow::on_btn_stop_clicked()
{
    if(m_pMediaThread)
    {
        qDebug() << "on_btn_stop_clicked 000";
        disconnect(m_pMediaThread, SIGNAL(sig_emitImage(const QImage&)),
                ui->openGLWidget, SLOT(slot_showImage(const QImage&)));

        m_pMediaThread->stopThread();

        qDebug() << "on_btn_stop_clicked 111";
        m_pMediaThread->quit();
        m_pMediaThread->wait();

        qDebug() << "on_btn_stop_clicked 222";
        m_pMediaThread->DeInit();

        qDebug() << "on_btn_stop_clicked 333";
    }

}

void MainWindow::on_btn_record_clicked()
{
    if(m_pMediaThread)
        m_pMediaThread->startRecord();
}

void MainWindow::on_btn_snapshot_clicked()
{
    if(m_pMediaThread)
        m_pMediaThread->Snapshot();
}

void MainWindow::on_btn_open_audio_clicked()
{
    ctAudioPlayer::getInstance().isPlay(true);
}

void MainWindow::on_btn_close_audio_clicked()
{
    ctAudioPlayer::getInstance().isPlay(false);
}

void MainWindow::on_btn_stop_record_clicked()
{
    if(m_pMediaThread)
        m_pMediaThread->stopRecord();
}

