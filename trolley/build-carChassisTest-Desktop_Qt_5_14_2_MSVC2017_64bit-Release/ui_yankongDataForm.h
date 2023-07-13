/********************************************************************************
** Form generated from reading UI file 'yankongDataForm.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YANKONGDATAFORM_H
#define UI_YANKONGDATAFORM_H

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

class Ui_yankongDataForm
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_value;
    QPushButton *pushButton_zhengzhuan;
    QPushButton *pushButton_fanzhuan;
    QPushButton *pushButton_stop;
    QLabel *label;
    QLabel *label_bmq;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_start;
    QLabel *label_value;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_stop_2;
    QSlider *horizontalSlider;
    QRadioButton *radioButton_up;
    QRadioButton *radioButton_back;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTextEdit *textEdit;

    void setupUi(QWidget *yankongDataForm)
    {
        if (yankongDataForm->objectName().isEmpty())
            yankongDataForm->setObjectName(QString::fromUtf8("yankongDataForm"));
        yankongDataForm->resize(803, 483);
        gridLayout = new QGridLayout(yankongDataForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(yankongDataForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_value = new QLineEdit(frame);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));

        horizontalLayout->addWidget(lineEdit_value);

        pushButton_zhengzhuan = new QPushButton(frame);
        pushButton_zhengzhuan->setObjectName(QString::fromUtf8("pushButton_zhengzhuan"));

        horizontalLayout->addWidget(pushButton_zhengzhuan);

        pushButton_fanzhuan = new QPushButton(frame);
        pushButton_fanzhuan->setObjectName(QString::fromUtf8("pushButton_fanzhuan"));

        horizontalLayout->addWidget(pushButton_fanzhuan);

        pushButton_stop = new QPushButton(frame);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        horizontalLayout->addWidget(pushButton_stop);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_bmq = new QLabel(frame);
        label_bmq->setObjectName(QString::fromUtf8("label_bmq"));
        label_bmq->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(label_bmq);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 413, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        groupBox = new QGroupBox(yankongDataForm);
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

        horizontalSpacer_2 = new QSpacerItem(194, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(194, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 5, 1, 1);

        pushButton_stop_2 = new QPushButton(groupBox);
        pushButton_stop_2->setObjectName(QString::fromUtf8("pushButton_stop_2"));

        gridLayout_2->addWidget(pushButton_stop_2, 2, 4, 1, 1);

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

        groupBox_2 = new QGroupBox(yankongDataForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(200, 0));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_3->addWidget(textEdit, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 1, 3, 1);


        retranslateUi(yankongDataForm);

        QMetaObject::connectSlotsByName(yankongDataForm);
    } // setupUi

    void retranslateUi(QWidget *yankongDataForm)
    {
        yankongDataForm->setWindowTitle(QCoreApplication::translate("yankongDataForm", "Form", nullptr));
        pushButton_zhengzhuan->setText(QCoreApplication::translate("yankongDataForm", "\346\255\243\350\275\254", nullptr));
        pushButton_fanzhuan->setText(QCoreApplication::translate("yankongDataForm", "\345\217\215\350\275\254", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("yankongDataForm", "\345\201\234\346\255\242", nullptr));
        label->setText(QCoreApplication::translate("yankongDataForm", "\347\274\226\347\240\201\345\231\250", nullptr));
        label_bmq->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("yankongDataForm", "\345\272\225\347\233\230", nullptr));
        pushButton_start->setText(QCoreApplication::translate("yankongDataForm", "\345\220\257\345\212\250", nullptr));
        label_value->setText(QString());
        pushButton_stop_2->setText(QCoreApplication::translate("yankongDataForm", "\345\201\234\346\255\242", nullptr));
        radioButton_up->setText(QCoreApplication::translate("yankongDataForm", "\345\211\215\350\277\233", nullptr));
        radioButton_back->setText(QCoreApplication::translate("yankongDataForm", "\345\220\216\351\200\200", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("yankongDataForm", "\350\276\223\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yankongDataForm: public Ui_yankongDataForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YANKONGDATAFORM_H
