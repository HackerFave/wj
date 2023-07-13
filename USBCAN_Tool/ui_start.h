/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_start
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *OpenDev_Btn;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *CloseDev_Btn;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_4;
    QComboBox *FrameFormt_ComB;
    QComboBox *CanIndex_ComB;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_7;
    QComboBox *FrameType_ComB;
    QLineEdit *FrameId_LineE;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_10;
    QFrame *line;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_10;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_9;
    QComboBox *WorkMode_ComB;
    QComboBox *BaudRate_ComB;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *SendPeriod_LineE;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *AutoSend_Chek;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_11;
    QCheckBox *CanRecv_Chek;
    QCheckBox *RealStore_Chek;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTableView *RecvText;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *SendData_Text;
    QPushButton *Send_Btn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QComboBox *filterMod;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *clear_Btn;
    QWidget *tab_3;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_7;
    QCustomPlot *plot1;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *checkBox_Rpm;
    QCheckBox *checkBox_Volt;
    QCheckBox *checkBox_Current;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_Current;
    QLabel *label_Volt;
    QLabel *label_Rpm;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QSlider *horizontalSlider_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_15;
    QSlider *horizontalSlider_3;
    QSpacerItem *horizontalSpacer_10;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_10;
    QLabel *label_14;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_9;
    QLabel *label_9;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *start)
    {
        if (start->objectName().isEmpty())
            start->setObjectName(QString::fromUtf8("start"));
        start->resize(1099, 653);
        centralWidget = new QWidget(start);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        OpenDev_Btn = new QPushButton(groupBox);
        OpenDev_Btn->setObjectName(QString::fromUtf8("OpenDev_Btn"));

        horizontalLayout->addWidget(OpenDev_Btn);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiCondensed"));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(197, 197, 197);"));

        horizontalLayout->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CloseDev_Btn = new QPushButton(groupBox);
        CloseDev_Btn->setObjectName(QString::fromUtf8("CloseDev_Btn"));

        horizontalLayout->addWidget(CloseDev_Btn);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        FrameFormt_ComB = new QComboBox(groupBox_3);
        FrameFormt_ComB->addItem(QString());
        FrameFormt_ComB->addItem(QString());
        FrameFormt_ComB->setObjectName(QString::fromUtf8("FrameFormt_ComB"));

        verticalLayout_4->addWidget(FrameFormt_ComB);

        CanIndex_ComB = new QComboBox(groupBox_3);
        CanIndex_ComB->addItem(QString());
        CanIndex_ComB->addItem(QString());
        CanIndex_ComB->setObjectName(QString::fromUtf8("CanIndex_ComB"));

        verticalLayout_4->addWidget(CanIndex_ComB);


        horizontalLayout_3->addLayout(verticalLayout_4);


        horizontalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_5->addWidget(label_2);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        FrameType_ComB = new QComboBox(groupBox_3);
        FrameType_ComB->addItem(QString());
        FrameType_ComB->addItem(QString());
        FrameType_ComB->setObjectName(QString::fromUtf8("FrameType_ComB"));
        FrameType_ComB->setMaximumSize(QSize(200, 16777215));

        verticalLayout_7->addWidget(FrameType_ComB);

        FrameId_LineE = new QLineEdit(groupBox_3);
        FrameId_LineE->setObjectName(QString::fromUtf8("FrameId_LineE"));
        FrameId_LineE->setMaximumSize(QSize(200, 16777215));

        verticalLayout_7->addWidget(FrameId_LineE);


        horizontalLayout_2->addLayout(verticalLayout_7);


        horizontalLayout_9->addLayout(horizontalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        gridLayout_4->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        line = new QFrame(groupBox_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_10->addWidget(line);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_8->addWidget(label_10);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_8->addWidget(label_11);


        horizontalLayout_10->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        WorkMode_ComB = new QComboBox(groupBox_3);
        WorkMode_ComB->addItem(QString());
        WorkMode_ComB->addItem(QString());
        WorkMode_ComB->addItem(QString());
        WorkMode_ComB->setObjectName(QString::fromUtf8("WorkMode_ComB"));
        WorkMode_ComB->setMinimumSize(QSize(100, 0));

        verticalLayout_9->addWidget(WorkMode_ComB);

        BaudRate_ComB = new QComboBox(groupBox_3);
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->addItem(QString());
        BaudRate_ComB->setObjectName(QString::fromUtf8("BaudRate_ComB"));
        BaudRate_ComB->setMinimumSize(QSize(100, 0));

        verticalLayout_9->addWidget(BaudRate_ComB);


        horizontalLayout_10->addLayout(verticalLayout_9);


        gridLayout_4->addLayout(horizontalLayout_10, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        SendPeriod_LineE = new QLineEdit(groupBox_3);
        SendPeriod_LineE->setObjectName(QString::fromUtf8("SendPeriod_LineE"));
        SendPeriod_LineE->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(SendPeriod_LineE);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        AutoSend_Chek = new QCheckBox(groupBox_3);
        AutoSend_Chek->setObjectName(QString::fromUtf8("AutoSend_Chek"));

        horizontalLayout_6->addWidget(AutoSend_Chek);


        verticalLayout_6->addLayout(horizontalLayout_6);


        gridLayout_4->addLayout(verticalLayout_6, 0, 3, 1, 1);

        line_2 = new QFrame(groupBox_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 5, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        CanRecv_Chek = new QCheckBox(groupBox_3);
        CanRecv_Chek->setObjectName(QString::fromUtf8("CanRecv_Chek"));

        verticalLayout_11->addWidget(CanRecv_Chek);

        RealStore_Chek = new QCheckBox(groupBox_3);
        RealStore_Chek->setObjectName(QString::fromUtf8("RealStore_Chek"));

        verticalLayout_11->addWidget(RealStore_Chek);


        gridLayout_4->addLayout(verticalLayout_11, 0, 6, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 186, 186);"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        RecvText = new QTableView(groupBox_2);
        RecvText->setObjectName(QString::fromUtf8("RecvText"));

        gridLayout_3->addWidget(RecvText, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_11 = new QHBoxLayout(groupBox_4);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        SendData_Text = new QLineEdit(groupBox_4);
        SendData_Text->setObjectName(QString::fromUtf8("SendData_Text"));
        SendData_Text->setMinimumSize(QSize(200, 0));

        horizontalLayout_4->addWidget(SendData_Text);

        Send_Btn = new QPushButton(groupBox_4);
        Send_Btn->setObjectName(QString::fromUtf8("Send_Btn"));

        horizontalLayout_4->addWidget(Send_Btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        filterMod = new QComboBox(groupBox_4);
        filterMod->addItem(QString());
        filterMod->addItem(QString());
        filterMod->addItem(QString());
        filterMod->setObjectName(QString::fromUtf8("filterMod"));
        filterMod->setMinimumSize(QSize(100, 0));

        horizontalLayout_4->addWidget(filterMod);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        horizontalLayout_11->addLayout(horizontalLayout_4);

        clear_Btn = new QPushButton(groupBox_4);
        clear_Btn->setObjectName(QString::fromUtf8("clear_Btn"));

        horizontalLayout_11->addWidget(clear_Btn);


        verticalLayout->addWidget(groupBox_4);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 6);
        verticalLayout->setStretch(2, 1);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_6 = new QGridLayout(tab_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_7 = new QGridLayout(groupBox_7);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        plot1 = new QCustomPlot(groupBox_7);
        plot1->setObjectName(QString::fromUtf8("plot1"));

        gridLayout_7->addWidget(plot1, 0, 0, 1, 1);


        verticalLayout_10->addWidget(groupBox_7);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        checkBox_Rpm = new QCheckBox(tab_3);
        checkBox_Rpm->setObjectName(QString::fromUtf8("checkBox_Rpm"));

        horizontalLayout_13->addWidget(checkBox_Rpm);

        checkBox_Volt = new QCheckBox(tab_3);
        checkBox_Volt->setObjectName(QString::fromUtf8("checkBox_Volt"));

        horizontalLayout_13->addWidget(checkBox_Volt);

        checkBox_Current = new QCheckBox(tab_3);
        checkBox_Current->setObjectName(QString::fromUtf8("checkBox_Current"));

        horizontalLayout_13->addWidget(checkBox_Current);


        verticalLayout_10->addLayout(horizontalLayout_13);

        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_8 = new QGridLayout(groupBox_8);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_Current = new QLabel(groupBox_8);
        label_Current->setObjectName(QString::fromUtf8("label_Current"));

        verticalLayout_12->addWidget(label_Current);

        label_Volt = new QLabel(groupBox_8);
        label_Volt->setObjectName(QString::fromUtf8("label_Volt"));

        verticalLayout_12->addWidget(label_Volt);

        label_Rpm = new QLabel(groupBox_8);
        label_Rpm->setObjectName(QString::fromUtf8("label_Rpm"));

        verticalLayout_12->addWidget(label_Rpm);


        horizontalLayout_14->addLayout(verticalLayout_12);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_9);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_12 = new QLabel(groupBox_8);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_7->addWidget(label_12);

        horizontalSlider = new QSlider(groupBox_8);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider);


        verticalLayout_13->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_13 = new QLabel(groupBox_8);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_8->addWidget(label_13);

        horizontalSlider_2 = new QSlider(groupBox_8);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(horizontalSlider_2);


        verticalLayout_13->addLayout(horizontalLayout_8);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_12->addWidget(label_15);

        horizontalSlider_3 = new QSlider(groupBox_8);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(horizontalSlider_3);


        verticalLayout_13->addLayout(horizontalLayout_12);


        horizontalLayout_14->addLayout(verticalLayout_13);


        gridLayout_8->addLayout(horizontalLayout_14, 0, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_10, 0, 1, 1, 1);


        verticalLayout_10->addWidget(groupBox_8);

        verticalLayout_10->setStretch(0, 2);
        verticalLayout_10->setStretch(2, 1);

        gridLayout_6->addLayout(verticalLayout_10, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_11 = new QGridLayout(groupBox_5);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_10 = new QGridLayout(groupBox_6);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(1000, 16777215));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/4.png")));

        gridLayout_10->addWidget(label_14, 0, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_6, 0, 0, 1, 1);

        groupBox_10 = new QGroupBox(groupBox_5);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        gridLayout_9 = new QGridLayout(groupBox_10);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_9 = new QLabel(groupBox_10);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/can.png")));

        gridLayout_9->addWidget(label_9, 0, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_10, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_5, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        start->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(start);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1099, 23));
        start->setMenuBar(menuBar);
        mainToolBar = new QToolBar(start);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        start->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(start);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        start->setStatusBar(statusBar);
        QWidget::setTabOrder(tabWidget, OpenDev_Btn);
        QWidget::setTabOrder(OpenDev_Btn, CloseDev_Btn);
        QWidget::setTabOrder(CloseDev_Btn, FrameFormt_ComB);
        QWidget::setTabOrder(FrameFormt_ComB, FrameType_ComB);
        QWidget::setTabOrder(FrameType_ComB, FrameId_LineE);
        QWidget::setTabOrder(FrameId_LineE, CanIndex_ComB);

        retranslateUi(start);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(start);
    } // setupUi

    void retranslateUi(QMainWindow *start)
    {
        start->setWindowTitle(QCoreApplication::translate("start", "start", nullptr));
        groupBox->setTitle(QString());
        OpenDev_Btn->setText(QCoreApplication::translate("start", " \346\211\223\345\274\200\350\256\276\345\244\207", nullptr));
        label_5->setText(QCoreApplication::translate("start", "USBCAN-2A  USBCAN-2C  CANalyst-II", nullptr));
        CloseDev_Btn->setText(QCoreApplication::translate("start", " \345\205\263\351\227\255\350\256\276\345\244\207", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("start", " CAN \350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("start", "  \345\270\247\346\240\274\345\274\217\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("start", " CAN\351\200\232\351\201\223\357\274\232", nullptr));
        FrameFormt_ComB->setItemText(0, QCoreApplication::translate("start", "Standar", nullptr));
        FrameFormt_ComB->setItemText(1, QCoreApplication::translate("start", "Extended", nullptr));

        CanIndex_ComB->setItemText(0, QCoreApplication::translate("start", "CAN1", nullptr));
        CanIndex_ComB->setItemText(1, QCoreApplication::translate("start", "CAN2", nullptr));

        label_2->setText(QCoreApplication::translate("start", "   \345\270\247\347\261\273\345\236\213\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("start", "\345\270\247ID(hex)\357\274\232", nullptr));
        FrameType_ComB->setItemText(0, QCoreApplication::translate("start", "Data", nullptr));
        FrameType_ComB->setItemText(1, QCoreApplication::translate("start", "Remote", nullptr));

        label_10->setText(QCoreApplication::translate("start", " \345\267\245\344\275\234\346\250\241\345\274\217\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("start", "   \346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        WorkMode_ComB->setItemText(0, QCoreApplication::translate("start", "\346\255\243\345\270\270\346\250\241\345\274\217", nullptr));
        WorkMode_ComB->setItemText(1, QCoreApplication::translate("start", "\345\217\252\345\220\254\346\250\241\345\274\217", nullptr));
        WorkMode_ComB->setItemText(2, QCoreApplication::translate("start", "\350\207\252\345\217\221\350\207\252\346\224\266", nullptr));

        BaudRate_ComB->setItemText(0, QCoreApplication::translate("start", "10Kbps", nullptr));
        BaudRate_ComB->setItemText(1, QCoreApplication::translate("start", "20Kbps", nullptr));
        BaudRate_ComB->setItemText(2, QCoreApplication::translate("start", "40Kbps", nullptr));
        BaudRate_ComB->setItemText(3, QCoreApplication::translate("start", "50Kbps", nullptr));
        BaudRate_ComB->setItemText(4, QCoreApplication::translate("start", "80Kbps", nullptr));
        BaudRate_ComB->setItemText(5, QCoreApplication::translate("start", "100Kbps", nullptr));
        BaudRate_ComB->setItemText(6, QCoreApplication::translate("start", "125Kbps", nullptr));
        BaudRate_ComB->setItemText(7, QCoreApplication::translate("start", "200Kbps", nullptr));
        BaudRate_ComB->setItemText(8, QCoreApplication::translate("start", "250Kbps", nullptr));
        BaudRate_ComB->setItemText(9, QCoreApplication::translate("start", "400Kbps", nullptr));
        BaudRate_ComB->setItemText(10, QCoreApplication::translate("start", "500Kbps", nullptr));
        BaudRate_ComB->setItemText(11, QCoreApplication::translate("start", "666Kbps", nullptr));
        BaudRate_ComB->setItemText(12, QCoreApplication::translate("start", "800Kbps", nullptr));
        BaudRate_ComB->setItemText(13, QCoreApplication::translate("start", "1000Kbps", nullptr));
        BaudRate_ComB->setItemText(14, QCoreApplication::translate("start", "33.33Kbps", nullptr));
        BaudRate_ComB->setItemText(15, QCoreApplication::translate("start", "66.66Kbps", nullptr));
        BaudRate_ComB->setItemText(16, QCoreApplication::translate("start", "83.33Kbps", nullptr));

        label_7->setText(QCoreApplication::translate("start", "\345\217\221\351\200\201\345\221\250\346\234\237(ms)\357\274\232", nullptr));
        AutoSend_Chek->setText(QCoreApplication::translate("start", " \350\207\252\345\212\250\345\217\221\351\200\201", nullptr));
        CanRecv_Chek->setText(QCoreApplication::translate("start", "CAN \346\216\245\346\224\266", nullptr));
        RealStore_Chek->setText(QCoreApplication::translate("start", "\345\256\236\346\227\266\345\255\230\345\202\250", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("start", " \346\225\260\346\215\256\346\230\276\347\244\272", nullptr));
        groupBox_4->setTitle(QString());
        label_8->setText(QCoreApplication::translate("start", "    \346\225\260\346\215\256\357\274\210hex)\357\274\232", nullptr));
        Send_Btn->setText(QCoreApplication::translate("start", " \345\217\221\351\200\201", nullptr));
        label_6->setText(QCoreApplication::translate("start", "\346\273\244\346\263\242\346\226\271\345\274\217\357\274\232", nullptr));
        filterMod->setItemText(0, QCoreApplication::translate("start", "\346\216\245\346\224\266\346\211\200\346\234\211\347\261\273\345\236\213", nullptr));
        filterMod->setItemText(1, QCoreApplication::translate("start", "\345\217\252\346\216\245\346\224\266\346\240\207\345\207\206\345\270\247", nullptr));
        filterMod->setItemText(2, QCoreApplication::translate("start", "\345\217\252\346\216\245\346\224\266\346\211\251\345\261\225\345\270\247", nullptr));

        clear_Btn->setText(QCoreApplication::translate("start", " \346\270\205\347\251\272\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("start", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("start", "\346\263\242\345\275\242", nullptr));
        checkBox_Rpm->setText(QCoreApplication::translate("start", "\350\275\254\351\200\237", nullptr));
        checkBox_Volt->setText(QCoreApplication::translate("start", "\347\224\265\345\216\213", nullptr));
        checkBox_Current->setText(QCoreApplication::translate("start", "\347\224\265\346\265\201", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("start", "GroupBox", nullptr));
        label_Current->setText(QCoreApplication::translate("start", "\347\224\265\346\265\201:Null", nullptr));
        label_Volt->setText(QCoreApplication::translate("start", "\347\224\265\345\216\213:Null", nullptr));
        label_Rpm->setText(QCoreApplication::translate("start", "\350\275\254\351\200\237:Null", nullptr));
        label_12->setText(QCoreApplication::translate("start", "\347\224\265\346\265\201", nullptr));
        label_13->setText(QCoreApplication::translate("start", "\347\224\265\345\216\213", nullptr));
        label_15->setText(QCoreApplication::translate("start", "\350\275\254\351\200\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("start", "\346\225\260\346\215\256\345\210\206\346\236\220", nullptr));
        groupBox_5->setTitle(QString());
        groupBox_6->setTitle(QString());
        label_14->setText(QString());
        groupBox_10->setTitle(QString());
        label_9->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("start", "\350\257\264\346\230\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
