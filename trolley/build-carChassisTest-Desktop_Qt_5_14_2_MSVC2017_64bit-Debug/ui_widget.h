/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_4;
    QFrame *frame;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_value;
    QPushButton *pushButton_zhengzhuan;
    QPushButton *pushButton_fanzhuan;
    QPushButton *pushButton_stop;
    QLabel *label_2;
    QLabel *label_bmq;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTextEdit *textEdit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_start;
    QLabel *label_value;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_stop_3;
    QSlider *horizontalSlider;
    QRadioButton *radioButton_up;
    QRadioButton *radioButton_back;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1045, 576);
        gridLayout_4 = new QGridLayout(Widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_value = new QLineEdit(frame_2);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));

        horizontalLayout_2->addWidget(lineEdit_value);

        pushButton_zhengzhuan = new QPushButton(frame_2);
        pushButton_zhengzhuan->setObjectName(QString::fromUtf8("pushButton_zhengzhuan"));

        horizontalLayout_2->addWidget(pushButton_zhengzhuan);

        pushButton_fanzhuan = new QPushButton(frame_2);
        pushButton_fanzhuan->setObjectName(QString::fromUtf8("pushButton_fanzhuan"));

        horizontalLayout_2->addWidget(pushButton_fanzhuan);

        pushButton_stop = new QPushButton(frame_2);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        horizontalLayout_2->addWidget(pushButton_stop);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label_bmq = new QLabel(frame_2);
        label_bmq->setObjectName(QString::fromUtf8("label_bmq"));
        label_bmq->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(label_bmq);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addWidget(frame_2, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(200, 0));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_3->addWidget(textEdit, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 1, 3, 1);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 140));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(194, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 3, 1, 1);

        pushButton_start = new QPushButton(groupBox);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));

        gridLayout_2->addWidget(pushButton_start, 2, 2, 1, 1);

        label_value = new QLabel(groupBox);
        label_value->setObjectName(QString::fromUtf8("label_value"));

        gridLayout_2->addWidget(label_value, 0, 2, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(300, 0));

        gridLayout_2->addWidget(lineEdit, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(194, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(194, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 2, 5, 1, 1);

        pushButton_stop_3 = new QPushButton(groupBox);
        pushButton_stop_3->setObjectName(QString::fromUtf8("pushButton_stop_3"));

        gridLayout_2->addWidget(pushButton_stop_3, 2, 4, 1, 1);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(4095);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider, 0, 1, 1, 1);

        radioButton_up = new QRadioButton(groupBox);
        radioButton_up->setObjectName(QString::fromUtf8("radioButton_up"));

        gridLayout_2->addWidget(radioButton_up, 1, 2, 1, 1);

        radioButton_back = new QRadioButton(groupBox);
        radioButton_back->setObjectName(QString::fromUtf8("radioButton_back"));

        gridLayout_2->addWidget(radioButton_back, 1, 3, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 340, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout_4->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_zhengzhuan->setText(QCoreApplication::translate("Widget", "\346\255\243\350\275\254", nullptr));
        pushButton_fanzhuan->setText(QCoreApplication::translate("Widget", "\345\217\215\350\275\254", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\274\226\347\240\201\345\231\250", nullptr));
        label_bmq->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\350\276\223\345\207\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\345\272\225\347\233\230", nullptr));
        pushButton_start->setText(QCoreApplication::translate("Widget", "\345\220\257\345\212\250", nullptr));
        label_value->setText(QString());
        pushButton_stop_3->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
        radioButton_up->setText(QCoreApplication::translate("Widget", "\345\211\215\350\277\233", nullptr));
        radioButton_back->setText(QCoreApplication::translate("Widget", "\345\220\216\351\200\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
