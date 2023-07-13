/********************************************************************************
** Form generated from reading UI file 'canDataShowForm.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANDATASHOWFORM_H
#define UI_CANDATASHOWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_canDataShowForm
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_status;
    QLabel *label_7;
    QLabel *label_sendNum;
    QLabel *label_11;
    QLabel *label_recvNum;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_cleanData;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_open;
    QPushButton *pushButton_close;
    QHBoxLayout *horizontalLayout;
    QLabel *label_;
    QComboBox *comboBox_devtype;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_format;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *comboBox_frame_type;
    QCheckBox *checkBox_canrecv;
    QCheckBox *checkBox_cansave;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_frame_id;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *comboBox_Channel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QComboBox *comboBox_work_mode;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QComboBox *comboBox_baudrate;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLineEdit *lineEdit_Period;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_frame_date;
    QPushButton *pushButton_send;
    QCheckBox *checkBox_autoSend;
    QLabel *label;
    QComboBox *comboBox_recvDataType;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView_data;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_enable;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_init;
    QPushButton *pushButton_reversal;
    QPushButton *pushButton_foreward;
    QPushButton *pushButton_stopEnable;
    QPushButton *pushButton_mode;

    void setupUi(QWidget *canDataShowForm)
    {
        if (canDataShowForm->objectName().isEmpty())
            canDataShowForm->setObjectName(QString::fromUtf8("canDataShowForm"));
        canDataShowForm->resize(864, 611);
        gridLayout = new QGridLayout(canDataShowForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(canDataShowForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 51));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_11 = new QHBoxLayout(frame);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_status = new QLabel(frame);
        label_status->setObjectName(QString::fromUtf8("label_status"));

        horizontalLayout_11->addWidget(label_status);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_11->addWidget(label_7);

        label_sendNum = new QLabel(frame);
        label_sendNum->setObjectName(QString::fromUtf8("label_sendNum"));

        horizontalLayout_11->addWidget(label_sendNum);

        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_11->addWidget(label_11);

        label_recvNum = new QLabel(frame);
        label_recvNum->setObjectName(QString::fromUtf8("label_recvNum"));

        horizontalLayout_11->addWidget(label_recvNum);

        horizontalSpacer_2 = new QSpacerItem(650, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        pushButton_cleanData = new QPushButton(frame);
        pushButton_cleanData->setObjectName(QString::fromUtf8("pushButton_cleanData"));

        horizontalLayout_11->addWidget(pushButton_cleanData);


        gridLayout_3->addWidget(frame, 4, 0, 1, 1);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_open = new QPushButton(groupBox);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));

        gridLayout_4->addWidget(pushButton_open, 0, 0, 1, 1);

        pushButton_close = new QPushButton(groupBox);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));

        gridLayout_4->addWidget(pushButton_close, 0, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_ = new QLabel(groupBox);
        label_->setObjectName(QString::fromUtf8("label_"));
        label_->setLayoutDirection(Qt::LeftToRight);
        label_->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_);

        comboBox_devtype = new QComboBox(groupBox);
        comboBox_devtype->addItem(QString());
        comboBox_devtype->addItem(QString());
        comboBox_devtype->addItem(QString());
        comboBox_devtype->setObjectName(QString::fromUtf8("comboBox_devtype"));

        horizontalLayout->addWidget(comboBox_devtype);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout_4->addLayout(horizontalLayout, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        comboBox_format = new QComboBox(groupBox_2);
        comboBox_format->addItem(QString());
        comboBox_format->addItem(QString());
        comboBox_format->setObjectName(QString::fromUtf8("comboBox_format"));
        comboBox_format->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(comboBox_format);


        gridLayout_5->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        comboBox_frame_type = new QComboBox(groupBox_2);
        comboBox_frame_type->addItem(QString());
        comboBox_frame_type->addItem(QString());
        comboBox_frame_type->setObjectName(QString::fromUtf8("comboBox_frame_type"));
        comboBox_frame_type->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(comboBox_frame_type);


        gridLayout_5->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        checkBox_canrecv = new QCheckBox(groupBox_2);
        checkBox_canrecv->setObjectName(QString::fromUtf8("checkBox_canrecv"));

        gridLayout_5->addWidget(checkBox_canrecv, 0, 2, 1, 1);

        checkBox_cansave = new QCheckBox(groupBox_2);
        checkBox_cansave->setObjectName(QString::fromUtf8("checkBox_cansave"));

        gridLayout_5->addWidget(checkBox_cansave, 0, 3, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(90, 0));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_5);

        lineEdit_frame_id = new QLineEdit(groupBox_2);
        lineEdit_frame_id->setObjectName(QString::fromUtf8("lineEdit_frame_id"));

        horizontalLayout_4->addWidget(lineEdit_frame_id);


        gridLayout_5->addLayout(horizontalLayout_4, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 0, 5, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_3);

        comboBox_Channel = new QComboBox(groupBox_2);
        comboBox_Channel->addItem(QString());
        comboBox_Channel->addItem(QString());
        comboBox_Channel->setObjectName(QString::fromUtf8("comboBox_Channel"));
        comboBox_Channel->setMinimumSize(QSize(100, 0));

        horizontalLayout_5->addWidget(comboBox_Channel);


        gridLayout_5->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(60, 0));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_8);

        comboBox_work_mode = new QComboBox(groupBox_2);
        comboBox_work_mode->addItem(QString());
        comboBox_work_mode->addItem(QString());
        comboBox_work_mode->addItem(QString());
        comboBox_work_mode->setObjectName(QString::fromUtf8("comboBox_work_mode"));
        comboBox_work_mode->setMinimumSize(QSize(100, 0));

        horizontalLayout_7->addWidget(comboBox_work_mode);


        gridLayout_5->addLayout(horizontalLayout_7, 1, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(60, 0));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_9);

        comboBox_baudrate = new QComboBox(groupBox_2);
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->setObjectName(QString::fromUtf8("comboBox_baudrate"));
        comboBox_baudrate->setMinimumSize(QSize(100, 0));

        horizontalLayout_8->addWidget(comboBox_baudrate);


        gridLayout_5->addLayout(horizontalLayout_8, 1, 2, 1, 2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(90, 0));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_10);

        lineEdit_Period = new QLineEdit(groupBox_2);
        lineEdit_Period->setObjectName(QString::fromUtf8("lineEdit_Period"));

        horizontalLayout_10->addWidget(lineEdit_Period);


        gridLayout_5->addLayout(horizontalLayout_10, 1, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 1, 5, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_6);

        lineEdit_frame_date = new QLineEdit(groupBox_2);
        lineEdit_frame_date->setObjectName(QString::fromUtf8("lineEdit_frame_date"));

        horizontalLayout_6->addWidget(lineEdit_frame_date);


        horizontalLayout_9->addLayout(horizontalLayout_6);

        pushButton_send = new QPushButton(groupBox_2);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        horizontalLayout_9->addWidget(pushButton_send);


        gridLayout_5->addLayout(horizontalLayout_9, 2, 0, 1, 2);

        checkBox_autoSend = new QCheckBox(groupBox_2);
        checkBox_autoSend->setObjectName(QString::fromUtf8("checkBox_autoSend"));

        gridLayout_5->addWidget(checkBox_autoSend, 2, 2, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 2, 3, 1, 1);

        comboBox_recvDataType = new QComboBox(groupBox_2);
        comboBox_recvDataType->addItem(QString());
        comboBox_recvDataType->addItem(QString());
        comboBox_recvDataType->addItem(QString());
        comboBox_recvDataType->setObjectName(QString::fromUtf8("comboBox_recvDataType"));

        gridLayout_5->addWidget(comboBox_recvDataType, 2, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 2, 5, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        tableView_data = new QTableView(widget);
        tableView_data->setObjectName(QString::fromUtf8("tableView_data"));

        gridLayout_3->addWidget(tableView_data, 3, 0, 1, 1);

        frame_2 = new QFrame(widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 81));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_enable = new QPushButton(frame_2);
        pushButton_enable->setObjectName(QString::fromUtf8("pushButton_enable"));

        gridLayout_2->addWidget(pushButton_enable, 0, 4, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 0, 9, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(139, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 0, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 0, 6, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        pushButton_init = new QPushButton(frame_2);
        pushButton_init->setObjectName(QString::fromUtf8("pushButton_init"));

        gridLayout_2->addWidget(pushButton_init, 0, 1, 1, 1);

        pushButton_reversal = new QPushButton(frame_2);
        pushButton_reversal->setObjectName(QString::fromUtf8("pushButton_reversal"));

        gridLayout_2->addWidget(pushButton_reversal, 0, 8, 1, 1);

        pushButton_foreward = new QPushButton(frame_2);
        pushButton_foreward->setObjectName(QString::fromUtf8("pushButton_foreward"));

        gridLayout_2->addWidget(pushButton_foreward, 0, 7, 1, 1);

        pushButton_stopEnable = new QPushButton(frame_2);
        pushButton_stopEnable->setObjectName(QString::fromUtf8("pushButton_stopEnable"));

        gridLayout_2->addWidget(pushButton_stopEnable, 0, 5, 1, 1);

        pushButton_mode = new QPushButton(frame_2);
        pushButton_mode->setObjectName(QString::fromUtf8("pushButton_mode"));

        gridLayout_2->addWidget(pushButton_mode, 0, 3, 1, 1);


        gridLayout_3->addWidget(frame_2, 2, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(canDataShowForm);

        QMetaObject::connectSlotsByName(canDataShowForm);
    } // setupUi

    void retranslateUi(QWidget *canDataShowForm)
    {
        canDataShowForm->setWindowTitle(QCoreApplication::translate("canDataShowForm", "Form", nullptr));
        label_status->setText(QString());
        label_7->setText(QCoreApplication::translate("canDataShowForm", "\345\217\221\351\200\201\350\256\241\346\225\260\357\274\232", nullptr));
        label_sendNum->setText(QString());
        label_11->setText(QCoreApplication::translate("canDataShowForm", "\346\216\245\346\224\266\350\256\241\346\225\260\357\274\232", nullptr));
        label_recvNum->setText(QString());
        pushButton_cleanData->setText(QCoreApplication::translate("canDataShowForm", "\346\270\205\351\231\244\346\225\260\346\215\256", nullptr));
        groupBox->setTitle(QString());
        pushButton_open->setText(QCoreApplication::translate("canDataShowForm", "\346\211\223\345\274\200\350\256\276\345\244\207", nullptr));
        pushButton_close->setText(QCoreApplication::translate("canDataShowForm", "\345\205\263\351\227\255\350\256\276\345\244\207", nullptr));
        label_->setText(QCoreApplication::translate("canDataShowForm", "\350\256\276\345\244\207\347\261\273\345\236\213", nullptr));
        comboBox_devtype->setItemText(0, QCoreApplication::translate("canDataShowForm", "USB_CAN-2A", nullptr));
        comboBox_devtype->setItemText(1, QCoreApplication::translate("canDataShowForm", "USB_CAN-2C", nullptr));
        comboBox_devtype->setItemText(2, QCoreApplication::translate("canDataShowForm", "CANalyst-II", nullptr));

        groupBox_2->setTitle(QCoreApplication::translate("canDataShowForm", "CAN\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("canDataShowForm", "\345\270\247\346\240\274\345\274\217", nullptr));
        comboBox_format->setItemText(0, QCoreApplication::translate("canDataShowForm", "\346\240\207\345\207\206\345\270\247", nullptr));
        comboBox_format->setItemText(1, QCoreApplication::translate("canDataShowForm", "\346\211\251\345\261\225\345\270\247", nullptr));

        label_4->setText(QCoreApplication::translate("canDataShowForm", "\345\270\247\347\261\273\345\236\213", nullptr));
        comboBox_frame_type->setItemText(0, QCoreApplication::translate("canDataShowForm", "\346\225\260\346\215\256\345\270\247", nullptr));
        comboBox_frame_type->setItemText(1, QCoreApplication::translate("canDataShowForm", "\350\277\234\347\250\213\345\270\247", nullptr));

        checkBox_canrecv->setText(QCoreApplication::translate("canDataShowForm", "\346\211\223\345\274\200can\346\216\245\346\224\266", nullptr));
        checkBox_cansave->setText(QCoreApplication::translate("canDataShowForm", "\345\256\236\346\227\266\345\255\230\345\202\250", nullptr));
        label_5->setText(QCoreApplication::translate("canDataShowForm", "\345\270\247ID\357\274\210HEX\357\274\211", nullptr));
        label_3->setText(QCoreApplication::translate("canDataShowForm", "CAN\351\200\232\351\201\223", nullptr));
        comboBox_Channel->setItemText(0, QCoreApplication::translate("canDataShowForm", "CAN1", nullptr));
        comboBox_Channel->setItemText(1, QCoreApplication::translate("canDataShowForm", "CAN2", nullptr));

        label_8->setText(QCoreApplication::translate("canDataShowForm", "\345\267\245\344\275\234\346\250\241\345\274\217", nullptr));
        comboBox_work_mode->setItemText(0, QCoreApplication::translate("canDataShowForm", "\346\255\243\345\270\270", nullptr));
        comboBox_work_mode->setItemText(1, QCoreApplication::translate("canDataShowForm", "\350\207\252\345\217\221\350\207\252\346\224\266", nullptr));
        comboBox_work_mode->setItemText(2, QCoreApplication::translate("canDataShowForm", "\345\217\252\345\220\254", nullptr));

        label_9->setText(QCoreApplication::translate("canDataShowForm", "\346\263\242\347\211\271\347\216\207", nullptr));
        comboBox_baudrate->setItemText(0, QCoreApplication::translate("canDataShowForm", "10Kbps", nullptr));
        comboBox_baudrate->setItemText(1, QCoreApplication::translate("canDataShowForm", "20Kbps", nullptr));
        comboBox_baudrate->setItemText(2, QCoreApplication::translate("canDataShowForm", "40Kbps", nullptr));
        comboBox_baudrate->setItemText(3, QCoreApplication::translate("canDataShowForm", "50Kbps", nullptr));
        comboBox_baudrate->setItemText(4, QCoreApplication::translate("canDataShowForm", "80Kbps", nullptr));
        comboBox_baudrate->setItemText(5, QCoreApplication::translate("canDataShowForm", "100Kbps", nullptr));
        comboBox_baudrate->setItemText(6, QCoreApplication::translate("canDataShowForm", "125Kbps", nullptr));
        comboBox_baudrate->setItemText(7, QCoreApplication::translate("canDataShowForm", "200Kbps", nullptr));
        comboBox_baudrate->setItemText(8, QCoreApplication::translate("canDataShowForm", "250Kbps", nullptr));
        comboBox_baudrate->setItemText(9, QCoreApplication::translate("canDataShowForm", "400Kbps", nullptr));
        comboBox_baudrate->setItemText(10, QCoreApplication::translate("canDataShowForm", "500Kbps", nullptr));
        comboBox_baudrate->setItemText(11, QCoreApplication::translate("canDataShowForm", "666Kbps", nullptr));
        comboBox_baudrate->setItemText(12, QCoreApplication::translate("canDataShowForm", "800Kbps", nullptr));
        comboBox_baudrate->setItemText(13, QCoreApplication::translate("canDataShowForm", "1000Kbps", nullptr));
        comboBox_baudrate->setItemText(14, QCoreApplication::translate("canDataShowForm", "33.33Kbps", nullptr));
        comboBox_baudrate->setItemText(15, QCoreApplication::translate("canDataShowForm", "66.66Kbps", nullptr));
        comboBox_baudrate->setItemText(16, QCoreApplication::translate("canDataShowForm", "83.33Kbps", nullptr));

        label_10->setText(QCoreApplication::translate("canDataShowForm", "\345\217\221\351\200\201\345\221\250\346\234\237\357\274\210ms\357\274\211", nullptr));
        label_6->setText(QCoreApplication::translate("canDataShowForm", "\346\225\260\346\215\256(HEX)", nullptr));
        pushButton_send->setText(QCoreApplication::translate("canDataShowForm", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        checkBox_autoSend->setText(QCoreApplication::translate("canDataShowForm", "\350\207\252\345\212\250\345\217\221\351\200\201", nullptr));
        label->setText(QCoreApplication::translate("canDataShowForm", "      \346\273\244\346\263\242\346\226\271\345\274\217\357\274\232", nullptr));
        comboBox_recvDataType->setItemText(0, QCoreApplication::translate("canDataShowForm", "\346\216\245\346\224\266\346\211\200\346\234\211\347\261\273\345\236\213", nullptr));
        comboBox_recvDataType->setItemText(1, QCoreApplication::translate("canDataShowForm", "\345\217\252\346\216\245\345\217\227\346\240\207\345\207\206\345\270\247", nullptr));
        comboBox_recvDataType->setItemText(2, QCoreApplication::translate("canDataShowForm", "\345\217\252\346\216\245\345\217\227\346\211\251\345\261\225\345\270\247", nullptr));

        pushButton_enable->setText(QCoreApplication::translate("canDataShowForm", "\344\275\277\350\203\275", nullptr));
        pushButton_init->setText(QCoreApplication::translate("canDataShowForm", "\347\224\265\346\234\272\345\210\235\345\247\213\345\214\226", nullptr));
        pushButton_reversal->setText(QCoreApplication::translate("canDataShowForm", "\345\217\215\350\275\254", nullptr));
        pushButton_foreward->setText(QCoreApplication::translate("canDataShowForm", "\346\255\243\350\275\254", nullptr));
        pushButton_stopEnable->setText(QCoreApplication::translate("canDataShowForm", "\345\201\234\346\255\242\344\275\277\350\203\275", nullptr));
        pushButton_mode->setText(QCoreApplication::translate("canDataShowForm", "\351\200\237\345\272\246\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class canDataShowForm: public Ui_canDataShowForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANDATASHOWFORM_H
