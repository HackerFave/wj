/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_init;
    QGroupBox *groupBox;
    QLineEdit *edit_can_id;
    QLabel *label;
    QLineEdit *edit_can_data;
    QLabel *label_2;
    QPushButton *btn_can_send;
    QGroupBox *groupBox_2;
    QPushButton *btn_motor_run;
    QLabel *show_motor_cur_angle;
    QPushButton *btn_motor_readangle;
    QGroupBox *groupBox_4;
    QSlider *slider_angle;
    QLabel *show_motor_angle;
    QGroupBox *groupBox_3;
    QSlider *slider_speed;
    QLabel *show_motor_speed;
    QLabel *show_motor_cur_motorangle;
    QPushButton *btn_motor_run_zero;
    QComboBox *comboBox_serial;
    QPushButton *btn_init_serial;
    QGroupBox *groupBox_5;
    QPushButton *btn_motor_enable;
    QPushButton *btn_motor_disable;
    QPushButton *btn_motor_zero;
    QPushButton *btn_motor_foreward;
    QPushButton *btn_motor_reversal;
    QLabel *label_3;
    QLineEdit *edit_pid_pos_p;
    QLabel *label_4;
    QLineEdit *edit_pid_pos_i;
    QLabel *label_5;
    QLineEdit *edit_pid_speed_i;
    QLabel *label_6;
    QLineEdit *edit_pid_speed_p;
    QLabel *label_7;
    QLineEdit *edit_pid_force_i;
    QLabel *label_8;
    QLineEdit *edit_pid_force_p;
    QPushButton *btn_motor_read_pid;
    QPushButton *btn_motor_write_pid;
    QGroupBox *groupBox_6;
    QRadioButton *radio_motor_a6;
    QRadioButton *radio_motor_a7;
    QRadioButton *radio_motor_a8;
    QRadioButton *radio_motor_a5;
    QPushButton *btn_motor_stop;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(816, 545);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btn_init = new QPushButton(centralWidget);
        btn_init->setObjectName(QString::fromUtf8("btn_init"));
        btn_init->setGeometry(QRect(50, 10, 111, 31));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 60, 721, 81));
        edit_can_id = new QLineEdit(groupBox);
        edit_can_id->setObjectName(QString::fromUtf8("edit_can_id"));
        edit_can_id->setGeometry(QRect(60, 40, 104, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 51, 16));
        edit_can_data = new QLineEdit(groupBox);
        edit_can_data->setObjectName(QString::fromUtf8("edit_can_data"));
        edit_can_data->setGeometry(QRect(250, 40, 301, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 40, 31, 20));
        btn_can_send = new QPushButton(groupBox);
        btn_can_send->setObjectName(QString::fromUtf8("btn_can_send"));
        btn_can_send->setGeometry(QRect(590, 40, 111, 31));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 320, 651, 161));
        btn_motor_run = new QPushButton(groupBox_2);
        btn_motor_run->setObjectName(QString::fromUtf8("btn_motor_run"));
        btn_motor_run->setGeometry(QRect(230, 110, 121, 41));
        show_motor_cur_angle = new QLabel(groupBox_2);
        show_motor_cur_angle->setObjectName(QString::fromUtf8("show_motor_cur_angle"));
        show_motor_cur_angle->setGeometry(QRect(400, 50, 141, 41));
        QFont font;
        font.setPointSize(24);
        show_motor_cur_angle->setFont(font);
        show_motor_cur_angle->setAlignment(Qt::AlignCenter);
        show_motor_cur_angle->setWordWrap(false);
        btn_motor_readangle = new QPushButton(groupBox_2);
        btn_motor_readangle->setObjectName(QString::fromUtf8("btn_motor_readangle"));
        btn_motor_readangle->setGeometry(QRect(550, 50, 71, 81));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(210, 30, 181, 61));
        slider_angle = new QSlider(groupBox_4);
        slider_angle->setObjectName(QString::fromUtf8("slider_angle"));
        slider_angle->setGeometry(QRect(10, 40, 160, 16));
        slider_angle->setMinimum(-20);
        slider_angle->setMaximum(20);
        slider_angle->setOrientation(Qt::Horizontal);
        show_motor_angle = new QLabel(groupBox_4);
        show_motor_angle->setObjectName(QString::fromUtf8("show_motor_angle"));
        show_motor_angle->setGeometry(QRect(70, 20, 31, 16));
        show_motor_angle->setAlignment(Qt::AlignCenter);
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 30, 181, 61));
        slider_speed = new QSlider(groupBox_3);
        slider_speed->setObjectName(QString::fromUtf8("slider_speed"));
        slider_speed->setGeometry(QRect(10, 40, 160, 16));
        slider_speed->setMinimum(0);
        slider_speed->setMaximum(50);
        slider_speed->setValue(10);
        slider_speed->setOrientation(Qt::Horizontal);
        show_motor_speed = new QLabel(groupBox_3);
        show_motor_speed->setObjectName(QString::fromUtf8("show_motor_speed"));
        show_motor_speed->setGeometry(QRect(80, 20, 24, 16));
        show_motor_cur_motorangle = new QLabel(groupBox_2);
        show_motor_cur_motorangle->setObjectName(QString::fromUtf8("show_motor_cur_motorangle"));
        show_motor_cur_motorangle->setGeometry(QRect(400, 100, 141, 41));
        show_motor_cur_motorangle->setFont(font);
        show_motor_cur_motorangle->setAlignment(Qt::AlignCenter);
        show_motor_cur_motorangle->setWordWrap(false);
        btn_motor_run_zero = new QPushButton(groupBox_2);
        btn_motor_run_zero->setObjectName(QString::fromUtf8("btn_motor_run_zero"));
        btn_motor_run_zero->setGeometry(QRect(50, 110, 121, 41));
        comboBox_serial = new QComboBox(centralWidget);
        comboBox_serial->setObjectName(QString::fromUtf8("comboBox_serial"));
        comboBox_serial->setGeometry(QRect(210, 10, 91, 31));
        btn_init_serial = new QPushButton(centralWidget);
        btn_init_serial->setObjectName(QString::fromUtf8("btn_init_serial"));
        btn_init_serial->setGeometry(QRect(310, 10, 111, 31));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(50, 200, 651, 111));
        btn_motor_enable = new QPushButton(groupBox_5);
        btn_motor_enable->setObjectName(QString::fromUtf8("btn_motor_enable"));
        btn_motor_enable->setGeometry(QRect(30, 20, 71, 41));
        btn_motor_disable = new QPushButton(groupBox_5);
        btn_motor_disable->setObjectName(QString::fromUtf8("btn_motor_disable"));
        btn_motor_disable->setGeometry(QRect(30, 60, 71, 41));
        btn_motor_zero = new QPushButton(groupBox_5);
        btn_motor_zero->setObjectName(QString::fromUtf8("btn_motor_zero"));
        btn_motor_zero->setGeometry(QRect(540, 80, 80, 20));
        btn_motor_foreward = new QPushButton(groupBox_5);
        btn_motor_foreward->setObjectName(QString::fromUtf8("btn_motor_foreward"));
        btn_motor_foreward->setGeometry(QRect(540, 20, 80, 20));
        btn_motor_reversal = new QPushButton(groupBox_5);
        btn_motor_reversal->setObjectName(QString::fromUtf8("btn_motor_reversal"));
        btn_motor_reversal->setGeometry(QRect(540, 50, 80, 20));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 20, 61, 20));
        edit_pid_pos_p = new QLineEdit(groupBox_5);
        edit_pid_pos_p->setObjectName(QString::fromUtf8("edit_pid_pos_p"));
        edit_pid_pos_p->setGeometry(QRect(170, 20, 91, 22));
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(280, 20, 61, 20));
        edit_pid_pos_i = new QLineEdit(groupBox_5);
        edit_pid_pos_i->setObjectName(QString::fromUtf8("edit_pid_pos_i"));
        edit_pid_pos_i->setGeometry(QRect(340, 20, 91, 22));
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 50, 61, 20));
        edit_pid_speed_i = new QLineEdit(groupBox_5);
        edit_pid_speed_i->setObjectName(QString::fromUtf8("edit_pid_speed_i"));
        edit_pid_speed_i->setGeometry(QRect(340, 50, 91, 22));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 50, 61, 20));
        edit_pid_speed_p = new QLineEdit(groupBox_5);
        edit_pid_speed_p->setObjectName(QString::fromUtf8("edit_pid_speed_p"));
        edit_pid_speed_p->setGeometry(QRect(170, 50, 91, 22));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(110, 80, 61, 20));
        edit_pid_force_i = new QLineEdit(groupBox_5);
        edit_pid_force_i->setObjectName(QString::fromUtf8("edit_pid_force_i"));
        edit_pid_force_i->setGeometry(QRect(340, 80, 91, 22));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(280, 80, 61, 20));
        edit_pid_force_p = new QLineEdit(groupBox_5);
        edit_pid_force_p->setObjectName(QString::fromUtf8("edit_pid_force_p"));
        edit_pid_force_p->setGeometry(QRect(170, 80, 91, 22));
        btn_motor_read_pid = new QPushButton(groupBox_5);
        btn_motor_read_pid->setObjectName(QString::fromUtf8("btn_motor_read_pid"));
        btn_motor_read_pid->setGeometry(QRect(450, 20, 80, 31));
        btn_motor_write_pid = new QPushButton(groupBox_5);
        btn_motor_write_pid->setObjectName(QString::fromUtf8("btn_motor_write_pid"));
        btn_motor_write_pid->setGeometry(QRect(450, 70, 80, 31));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(50, 150, 721, 51));
        radio_motor_a6 = new QRadioButton(groupBox_6);
        radio_motor_a6->setObjectName(QString::fromUtf8("radio_motor_a6"));
        radio_motor_a6->setGeometry(QRect(280, 20, 37, 18));
        radio_motor_a7 = new QRadioButton(groupBox_6);
        radio_motor_a7->setObjectName(QString::fromUtf8("radio_motor_a7"));
        radio_motor_a7->setGeometry(QRect(440, 20, 37, 18));
        radio_motor_a8 = new QRadioButton(groupBox_6);
        radio_motor_a8->setObjectName(QString::fromUtf8("radio_motor_a8"));
        radio_motor_a8->setGeometry(QRect(580, 20, 37, 18));
        radio_motor_a5 = new QRadioButton(groupBox_6);
        radio_motor_a5->setObjectName(QString::fromUtf8("radio_motor_a5"));
        radio_motor_a5->setEnabled(true);
        radio_motor_a5->setGeometry(QRect(110, 20, 37, 18));
        QFont font1;
        font1.setPointSize(9);
        radio_motor_a5->setFont(font1);
        radio_motor_a5->setChecked(true);
        btn_motor_stop = new QPushButton(centralWidget);
        btn_motor_stop->setObjectName(QString::fromUtf8("btn_motor_stop"));
        btn_motor_stop->setGeometry(QRect(710, 210, 61, 261));
        MainWindow->setCentralWidget(centralWidget);
        groupBox_6->raise();
        btn_init->raise();
        groupBox->raise();
        groupBox_2->raise();
        comboBox_serial->raise();
        btn_init_serial->raise();
        groupBox_5->raise();
        btn_motor_stop->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 816, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "A5~A8\346\216\247\345\210\266", nullptr));
        btn_init->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "CAN\346\223\215\344\275\234", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CAN_ID", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Data", nullptr));
        btn_can_send->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\346\223\215\344\275\234", nullptr));
        btn_motor_run->setText(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214", nullptr));
        show_motor_cur_angle->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn_motor_readangle->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\344\275\215\347\275\256", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\350\247\222\345\272\246/\350\241\214\347\250\213", nullptr));
        show_motor_angle->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246", nullptr));
        show_motor_speed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        show_motor_cur_motorangle->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn_motor_run_zero->setText(QCoreApplication::translate("MainWindow", "\345\275\222\351\233\266", nullptr));
        btn_init_serial->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\351\205\215\347\275\256", nullptr));
        btn_motor_enable->setText(QCoreApplication::translate("MainWindow", "\344\275\277\350\203\275", nullptr));
        btn_motor_disable->setText(QCoreApplication::translate("MainWindow", "\345\216\273\344\275\277\350\203\275", nullptr));
        btn_motor_zero->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\351\233\266\344\275\215", nullptr));
        btn_motor_foreward->setText(QCoreApplication::translate("MainWindow", "\346\255\243\350\275\254", nullptr));
        btn_motor_reversal->setText(QCoreApplication::translate("MainWindow", "\345\217\215\350\275\254", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\347\216\257Kp", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\347\216\257Ki", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\347\216\257Kp", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\347\216\257Ki", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\275\254\347\237\251\347\216\257Kp", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\350\275\254\347\237\251\347\216\257Ki", nullptr));
        btn_motor_read_pid->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226PID", nullptr));
        btn_motor_write_pid->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245PID", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\351\200\211\346\213\251", nullptr));
        radio_motor_a6->setText(QCoreApplication::translate("MainWindow", "A6", nullptr));
        radio_motor_a7->setText(QCoreApplication::translate("MainWindow", "A7", nullptr));
        radio_motor_a8->setText(QCoreApplication::translate("MainWindow", "A8", nullptr));
        radio_motor_a5->setText(QCoreApplication::translate("MainWindow", "A5", nullptr));
        btn_motor_stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
