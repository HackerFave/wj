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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_11;
    QLineEdit *lineEdit_0pian;
    QPushButton *pushButton_write;
    QPushButton *pushButton_clear_angle;
    QPushButton *pushButton_clear_error;
    QSpacerItem *horizontalSpacer_10;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QLineEdit *lineEdit_angle_2;
    QPushButton *pushButton_run_2;
    QPushButton *pushButton_read_encoder_2;
    QPushButton *pushButton_readacc_chuizhi;
    QSpacerItem *horizontalSpacer_6;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_4;
    QLabel *label_angle_2;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_acc_x2;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *lineEdit_angle;
    QPushButton *pushButton_run;
    QPushButton *pushButton_read_encoder;
    QPushButton *pushButton_readacc_shuiping;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLabel *label_angle_1;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_acc_x1;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 95));
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_9 = new QSpacerItem(124, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);


        horizontalLayout_5->addLayout(verticalLayout);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_5->addWidget(label_11);

        lineEdit_0pian = new QLineEdit(groupBox_3);
        lineEdit_0pian->setObjectName(QString::fromUtf8("lineEdit_0pian"));

        horizontalLayout_5->addWidget(lineEdit_0pian);

        pushButton_write = new QPushButton(groupBox_3);
        pushButton_write->setObjectName(QString::fromUtf8("pushButton_write"));

        horizontalLayout_5->addWidget(pushButton_write);

        pushButton_clear_angle = new QPushButton(groupBox_3);
        pushButton_clear_angle->setObjectName(QString::fromUtf8("pushButton_clear_angle"));

        horizontalLayout_5->addWidget(pushButton_clear_angle);

        pushButton_clear_error = new QPushButton(groupBox_3);
        pushButton_clear_error->setObjectName(QString::fromUtf8("pushButton_clear_error"));

        horizontalLayout_5->addWidget(pushButton_clear_error);

        horizontalSpacer_10 = new QSpacerItem(124, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_3 = new QFrame(groupBox_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_angle_2 = new QLineEdit(frame_3);
        lineEdit_angle_2->setObjectName(QString::fromUtf8("lineEdit_angle_2"));

        horizontalLayout_3->addWidget(lineEdit_angle_2);

        pushButton_run_2 = new QPushButton(frame_3);
        pushButton_run_2->setObjectName(QString::fromUtf8("pushButton_run_2"));

        horizontalLayout_3->addWidget(pushButton_run_2);

        pushButton_read_encoder_2 = new QPushButton(frame_3);
        pushButton_read_encoder_2->setObjectName(QString::fromUtf8("pushButton_read_encoder_2"));

        horizontalLayout_3->addWidget(pushButton_read_encoder_2);

        pushButton_readacc_chuizhi = new QPushButton(frame_3);
        pushButton_readacc_chuizhi->setObjectName(QString::fromUtf8("pushButton_readacc_chuizhi"));

        horizontalLayout_3->addWidget(pushButton_readacc_chuizhi);

        horizontalSpacer_6 = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout_2->addWidget(frame_3, 0, 0, 1, 1);

        frame_4 = new QFrame(groupBox_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(0, 36));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(3, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        label_angle_2 = new QLabel(frame_4);
        label_angle_2->setObjectName(QString::fromUtf8("label_angle_2"));
        label_angle_2->setMinimumSize(QSize(100, 0));

        horizontalLayout_4->addWidget(label_angle_2);

        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(100, 0));

        horizontalLayout_4->addWidget(label_7);

        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        label_acc_x2 = new QLabel(frame_4);
        label_acc_x2->setObjectName(QString::fromUtf8("label_acc_x2"));
        label_acc_x2->setMinimumSize(QSize(100, 0));

        horizontalLayout_4->addWidget(label_acc_x2);

        horizontalSpacer_8 = new QSpacerItem(4, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        gridLayout_2->addWidget(frame_4, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(122, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(label_3);

        lineEdit_angle = new QLineEdit(frame);
        lineEdit_angle->setObjectName(QString::fromUtf8("lineEdit_angle"));

        horizontalLayout->addWidget(lineEdit_angle);

        pushButton_run = new QPushButton(frame);
        pushButton_run->setObjectName(QString::fromUtf8("pushButton_run"));

        horizontalLayout->addWidget(pushButton_run);

        pushButton_read_encoder = new QPushButton(frame);
        pushButton_read_encoder->setObjectName(QString::fromUtf8("pushButton_read_encoder"));

        horizontalLayout->addWidget(pushButton_read_encoder);

        pushButton_readacc_shuiping = new QPushButton(frame);
        pushButton_readacc_shuiping->setObjectName(QString::fromUtf8("pushButton_readacc_shuiping"));

        horizontalLayout->addWidget(pushButton_readacc_shuiping);

        horizontalSpacer_2 = new QSpacerItem(121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_3->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 36));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(134, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        label_angle_1 = new QLabel(frame_2);
        label_angle_1->setObjectName(QString::fromUtf8("label_angle_1"));
        label_angle_1->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(label_angle_1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(label_8);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_2->addWidget(label_10);

        label_acc_x1 = new QLabel(frame_2);
        label_acc_x1->setObjectName(QString::fromUtf8("label_acc_x1"));
        label_acc_x1->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(label_acc_x1);

        horizontalSpacer_4 = new QSpacerItem(134, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout_3->addWidget(frame_2, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "X1", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "X2", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\2450\345\201\217\350\247\222\345\272\246", nullptr));
        pushButton_write->setText(QCoreApplication::translate("MainWindow", "write", nullptr));
        pushButton_clear_angle->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\350\247\222\345\272\246\345\221\275\344\273\244", nullptr));
        pushButton_clear_error->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\351\224\231\350\257\257", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\344\277\257\344\273\260\347\224\265\346\234\272", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\255\243\346\225\260\350\241\250\347\244\272\351\241\272\346\227\266\351\222\210\357\274\214\350\264\237\346\225\260\350\241\250\347\244\272\351\200\206\346\227\266\351\222\210", nullptr));
        pushButton_run_2->setText(QCoreApplication::translate("MainWindow", "\350\275\254\345\212\250", nullptr));
        pushButton_read_encoder_2->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\350\247\222\345\272\246", nullptr));
        pushButton_readacc_chuizhi->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\345\212\240\351\200\237\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\236\202\347\233\264\350\247\222\345\272\246:", nullptr));
        label_angle_2->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246:", nullptr));
        label_7->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246:", nullptr));
        label_acc_x2->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\260\264\345\271\263\347\224\265\346\234\272", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\255\243\346\225\260\350\241\250\347\244\272\351\241\272\346\227\266\351\222\210\357\274\214\350\264\237\346\225\260\350\241\250\347\244\272\351\200\206\346\227\266\351\222\210", nullptr));
        pushButton_run->setText(QCoreApplication::translate("MainWindow", "\350\275\254\345\212\250", nullptr));
        pushButton_read_encoder->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\350\247\222\345\272\246", nullptr));
        pushButton_readacc_shuiping->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\345\212\240\351\200\237\345\272\246", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\260\264\345\271\263\350\247\222\345\272\246:", nullptr));
        label_angle_1->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246:", nullptr));
        label_8->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246:", nullptr));
        label_acc_x1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
