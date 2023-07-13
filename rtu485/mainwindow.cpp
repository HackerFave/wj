#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plctimerthread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    plcThread = new PlcTimerThread();
    thread =new QThread();
    plcThread->moveToThread(thread);

    plc = new PlcThread;
    qthreadPlc =new QThread();
    plc->moveToThread(qthreadPlc);


    /*********************/
    //    connect(thread,&QThread::started,plcThread,&PlcTimerThread::run);
    connect(plcThread,&PlcTimerThread::workStart,plcThread,&PlcTimerThread::run);
    connect(plcThread,&PlcTimerThread::workFinished,thread,&QThread::quit);
    connect(thread,&QThread::finished,thread,&QThread::deleteLater);

    connect(plcThread,&PlcTimerThread::upDateTime,this,&MainWindow::showTime);

    connect(this,&MainWindow::sendSpinbox,plcThread,&PlcTimerThread::printSpinBox);


    thread->start();
    qDebug()<<"开启线程";
    /*******x线程2******/
    connect(qthreadPlc,&QThread::started,plc,&PlcThread::doWork);
    connect(plc,&PlcThread::startWork,plc,&PlcThread::connectPlc);
    connect(plc,&PlcThread::finishWork,qthreadPlc,&QThread::quit);
    connect(qthreadPlc,&QThread::finished,qthreadPlc,&QThread::deleteLater);

    connect(plc,&PlcThread::statusBar,this,&MainWindow::on_statusBar);
    connect(plc,&PlcThread::change2Con,this,&MainWindow::on_change2Con);
    connect(plc,&PlcThread::change2Discon,this,&MainWindow::on_change2Discon);
    connect(plc,&PlcThread::updateT,this,&MainWindow::on_updateT);
    connect(plc,&PlcThread::updateS,this,&MainWindow::on_updateS);
    connect(this,&MainWindow::writeTor,plc,&PlcThread::on_writeTor);
    qthreadPlc->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showTime(QString time)
{
    ui->lineEdit->setText(time);
}

void MainWindow::on_spinBox_valueChanged()
{
    qDebug()<<"changed";
    emit sendSpinbox(ui->spinBox->value());
}

void MainWindow::on_connectModbus_clicked()
{
    global::ComPortName = ui->serialBox->currentText();
    emit plc->startWork();
    qDebug()<<"click con";
}

void MainWindow::on_searchPort_clicked()
{
    ui->serialBox->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->serialBox->addItem(info.portName());
    }

}

void MainWindow::on_writeT_clicked()
{
    QString str1 = ui->torque->text();

    QByteArray str2 = QByteArray::fromHex (str1.toLatin1().data());
    global::Tor = str2.toHex().data();
    qDebug()<<global::Tor;
    emit writeTor(global::Tor);
}

void MainWindow::on_statusBar(const QString &message)
{
    statusBar()->showMessage(message,5000);

}

void MainWindow::on_change2Discon()
{
    ui->connectModbus->setText("disconnectModbus");
}

void MainWindow::on_change2Con()
{
    ui->connectModbus->setText("connectModbus");

}

void MainWindow::on_updateT(QString t)
{
    ui->readT->setText(t);
}

void MainWindow::on_updateS(QString s)
{
    ui->readS->setText(s);
}



void MainWindow::on_pushButton_start_clicked()
{
    qDebug()<<"主线程ID:"<<QThread::currentThread();
    emit plcThread->workStart();
}

void MainWindow::on_pushButton_mainThread_clicked()
{
    qDebug()<<"主线程ID:"<<QThread::currentThread();  //显示当前线程的数值
}

void MainWindow::on_pushButton_quitThread_clicked()
{
    emit plcThread->workFinished();
    qDebug()<<"退出线程";
}

void MainWindow::on_pushButton_intoThread_clicked()
{
    plcThread = new PlcTimerThread();
    thread =new QThread();
    plcThread->moveToThread(thread);

    //    connect(thread,&QThread::started,plcThread,&PlcTimerThread::run);
    connect(plcThread,&PlcTimerThread::workStart,plcThread,&PlcTimerThread::run);
    connect(this,&MainWindow::destroyed,plcThread,&PlcTimerThread::workFinished);
    connect(plcThread,&PlcTimerThread::workFinished,thread,&QThread::quit);
    connect(thread,&QThread::finished,thread,&QThread::deleteLater);

    connect(plcThread,&PlcTimerThread::upDateTime,this,&MainWindow::showTime);



    thread->start();
    qDebug()<<"开启线程";
}
