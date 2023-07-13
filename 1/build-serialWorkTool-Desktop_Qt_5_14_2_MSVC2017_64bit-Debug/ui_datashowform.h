/********************************************************************************
** Form generated from reading UI file 'datashowform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASHOWFORM_H
#define UI_DATASHOWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dataShowForm
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QComboBox *comboBox_port;
    QLabel *label_7;
    QComboBox *comboBox_BaudRate;
    QLabel *label_8;
    QComboBox *comboBox_databit;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_data;
    QLabel *label_3;
    QLineEdit *lineEdit_body;
    QPushButton *pushButton_send;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit_recv;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_sum_2;
    QComboBox *comboBox_hex;
    QPushButton *pushButton_sum_2;
    QTextEdit *textEdit_sum;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_sum;
    QComboBox *comboBox_byte;
    QPushButton *pushButton_sum;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_asc;
    QComboBox *comboBox;
    QPushButton *pushButton_sum_asc;

    void setupUi(QWidget *dataShowForm)
    {
        if (dataShowForm->objectName().isEmpty())
            dataShowForm->setObjectName(QString::fromUtf8("dataShowForm"));
        dataShowForm->resize(712, 514);
        gridLayout = new QGridLayout(dataShowForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(dataShowForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        comboBox_port = new QComboBox(groupBox_2);
        comboBox_port->setObjectName(QString::fromUtf8("comboBox_port"));

        horizontalLayout_5->addWidget(comboBox_port);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_7);

        comboBox_BaudRate = new QComboBox(groupBox_2);
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->setObjectName(QString::fromUtf8("comboBox_BaudRate"));

        horizontalLayout_5->addWidget(comboBox_BaudRate);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_8);

        comboBox_databit = new QComboBox(groupBox_2);
        comboBox_databit->addItem(QString());
        comboBox_databit->addItem(QString());
        comboBox_databit->addItem(QString());
        comboBox_databit->addItem(QString());
        comboBox_databit->setObjectName(QString::fromUtf8("comboBox_databit"));

        horizontalLayout_5->addWidget(comboBox_databit);

        pushButton_connect = new QPushButton(groupBox_2);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));

        horizontalLayout_5->addWidget(pushButton_connect);

        pushButton_disconnect = new QPushButton(groupBox_2);
        pushButton_disconnect->setObjectName(QString::fromUtf8("pushButton_disconnect"));

        horizontalLayout_5->addWidget(pushButton_disconnect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 2);

        groupBox_3 = new QGroupBox(dataShowForm);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_data = new QLineEdit(groupBox_3);
        lineEdit_data->setObjectName(QString::fromUtf8("lineEdit_data"));
        lineEdit_data->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(lineEdit_data);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_3);

        lineEdit_body = new QLineEdit(groupBox_3);
        lineEdit_body->setObjectName(QString::fromUtf8("lineEdit_body"));

        horizontalLayout_4->addWidget(lineEdit_body);

        pushButton_send = new QPushButton(groupBox_3);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        horizontalLayout_4->addWidget(pushButton_send);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 2);

        textEdit_recv = new QTextEdit(dataShowForm);
        textEdit_recv->setObjectName(QString::fromUtf8("textEdit_recv"));

        gridLayout->addWidget(textEdit_recv, 2, 0, 1, 1);

        frame = new QFrame(dataShowForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(200, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, -1, -1);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(45, 0));

        horizontalLayout->addWidget(label_5);

        lineEdit_sum_2 = new QLineEdit(groupBox);
        lineEdit_sum_2->setObjectName(QString::fromUtf8("lineEdit_sum_2"));

        horizontalLayout->addWidget(lineEdit_sum_2);

        comboBox_hex = new QComboBox(groupBox);
        comboBox_hex->addItem(QString());
        comboBox_hex->addItem(QString());
        comboBox_hex->addItem(QString());
        comboBox_hex->addItem(QString());
        comboBox_hex->addItem(QString());
        comboBox_hex->addItem(QString());
        comboBox_hex->addItem(QString());
        comboBox_hex->addItem(QString());
        comboBox_hex->setObjectName(QString::fromUtf8("comboBox_hex"));
        comboBox_hex->setMinimumSize(QSize(70, 0));

        horizontalLayout->addWidget(comboBox_hex);

        pushButton_sum_2 = new QPushButton(groupBox);
        pushButton_sum_2->setObjectName(QString::fromUtf8("pushButton_sum_2"));

        horizontalLayout->addWidget(pushButton_sum_2);


        gridLayout_5->addLayout(horizontalLayout, 0, 0, 1, 1);

        textEdit_sum = new QTextEdit(groupBox);
        textEdit_sum->setObjectName(QString::fromUtf8("textEdit_sum"));

        gridLayout_5->addWidget(textEdit_sum, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(45, 0));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_sum = new QLineEdit(groupBox);
        lineEdit_sum->setObjectName(QString::fromUtf8("lineEdit_sum"));

        horizontalLayout_2->addWidget(lineEdit_sum);

        comboBox_byte = new QComboBox(groupBox);
        comboBox_byte->addItem(QString());
        comboBox_byte->addItem(QString());
        comboBox_byte->addItem(QString());
        comboBox_byte->addItem(QString());
        comboBox_byte->addItem(QString());
        comboBox_byte->addItem(QString());
        comboBox_byte->addItem(QString());
        comboBox_byte->addItem(QString());
        comboBox_byte->setObjectName(QString::fromUtf8("comboBox_byte"));
        comboBox_byte->setMinimumSize(QSize(70, 0));

        horizontalLayout_2->addWidget(comboBox_byte);

        pushButton_sum = new QPushButton(groupBox);
        pushButton_sum->setObjectName(QString::fromUtf8("pushButton_sum"));

        horizontalLayout_2->addWidget(pushButton_sum);


        gridLayout_5->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(45, 0));

        horizontalLayout_3->addWidget(label_6);

        lineEdit_asc = new QLineEdit(groupBox);
        lineEdit_asc->setObjectName(QString::fromUtf8("lineEdit_asc"));

        horizontalLayout_3->addWidget(lineEdit_asc);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(70, 0));

        horizontalLayout_3->addWidget(comboBox);

        pushButton_sum_asc = new QPushButton(groupBox);
        pushButton_sum_asc->setObjectName(QString::fromUtf8("pushButton_sum_asc"));

        horizontalLayout_3->addWidget(pushButton_sum_asc);


        gridLayout_5->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 2, 1, 1, 1);


        retranslateUi(dataShowForm);

        comboBox_BaudRate->setCurrentIndex(7);
        comboBox_databit->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(dataShowForm);
    } // setupUi

    void retranslateUi(QWidget *dataShowForm)
    {
        dataShowForm->setWindowTitle(QCoreApplication::translate("dataShowForm", "Form", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("dataShowForm", "\345\210\235\345\247\213\345\214\226", nullptr));
        label->setText(QCoreApplication::translate("dataShowForm", "\347\253\257\345\217\243", nullptr));
        label_7->setText(QCoreApplication::translate("dataShowForm", "\346\263\242\347\211\271\347\216\207", nullptr));
        comboBox_BaudRate->setItemText(0, QCoreApplication::translate("dataShowForm", "1200", nullptr));
        comboBox_BaudRate->setItemText(1, QCoreApplication::translate("dataShowForm", "2400", nullptr));
        comboBox_BaudRate->setItemText(2, QCoreApplication::translate("dataShowForm", "4800", nullptr));
        comboBox_BaudRate->setItemText(3, QCoreApplication::translate("dataShowForm", "9600", nullptr));
        comboBox_BaudRate->setItemText(4, QCoreApplication::translate("dataShowForm", "19200", nullptr));
        comboBox_BaudRate->setItemText(5, QCoreApplication::translate("dataShowForm", "38400", nullptr));
        comboBox_BaudRate->setItemText(6, QCoreApplication::translate("dataShowForm", "57600", nullptr));
        comboBox_BaudRate->setItemText(7, QCoreApplication::translate("dataShowForm", "115200", nullptr));

        label_8->setText(QCoreApplication::translate("dataShowForm", "\346\225\260\346\215\256\344\275\215", nullptr));
        comboBox_databit->setItemText(0, QCoreApplication::translate("dataShowForm", "5", nullptr));
        comboBox_databit->setItemText(1, QCoreApplication::translate("dataShowForm", "6", nullptr));
        comboBox_databit->setItemText(2, QCoreApplication::translate("dataShowForm", "7", nullptr));
        comboBox_databit->setItemText(3, QCoreApplication::translate("dataShowForm", "8", nullptr));

        pushButton_connect->setText(QCoreApplication::translate("dataShowForm", "\350\277\236\346\216\245", nullptr));
        pushButton_disconnect->setText(QCoreApplication::translate("dataShowForm", "\346\226\255\345\274\200", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("dataShowForm", "\346\225\260\346\215\256", nullptr));
        label_2->setText(QCoreApplication::translate("dataShowForm", "head\346\225\260\346\215\256", nullptr));
        label_3->setText(QCoreApplication::translate("dataShowForm", "body", nullptr));
        pushButton_send->setText(QCoreApplication::translate("dataShowForm", "\345\217\221\351\200\201", nullptr));
        groupBox->setTitle(QCoreApplication::translate("dataShowForm", "\346\225\260\346\215\256\346\215\242\347\256\227", nullptr));
        label_5->setText(QCoreApplication::translate("dataShowForm", "10\350\277\233\345\210\266", nullptr));
        comboBox_hex->setItemText(0, QCoreApplication::translate("dataShowForm", "64", nullptr));
        comboBox_hex->setItemText(1, QCoreApplication::translate("dataShowForm", "32", nullptr));
        comboBox_hex->setItemText(2, QCoreApplication::translate("dataShowForm", "16", nullptr));
        comboBox_hex->setItemText(3, QCoreApplication::translate("dataShowForm", "8", nullptr));
        comboBox_hex->setItemText(4, QCoreApplication::translate("dataShowForm", "u64", nullptr));
        comboBox_hex->setItemText(5, QCoreApplication::translate("dataShowForm", "u32", nullptr));
        comboBox_hex->setItemText(6, QCoreApplication::translate("dataShowForm", "u16", nullptr));
        comboBox_hex->setItemText(7, QCoreApplication::translate("dataShowForm", "u8", nullptr));

        pushButton_sum_2->setText(QCoreApplication::translate("dataShowForm", "\346\215\242\347\256\227", nullptr));
        label_4->setText(QCoreApplication::translate("dataShowForm", "16\350\277\233\345\210\266", nullptr));
        comboBox_byte->setItemText(0, QCoreApplication::translate("dataShowForm", "int_64", nullptr));
        comboBox_byte->setItemText(1, QCoreApplication::translate("dataShowForm", "int_32", nullptr));
        comboBox_byte->setItemText(2, QCoreApplication::translate("dataShowForm", "float", nullptr));
        comboBox_byte->setItemText(3, QCoreApplication::translate("dataShowForm", "short", nullptr));
        comboBox_byte->setItemText(4, QCoreApplication::translate("dataShowForm", "char", nullptr));
        comboBox_byte->setItemText(5, QCoreApplication::translate("dataShowForm", "Asc", nullptr));
        comboBox_byte->setItemText(6, QCoreApplication::translate("dataShowForm", "DEC", nullptr));
        comboBox_byte->setItemText(7, QCoreApplication::translate("dataShowForm", "double", nullptr));

        pushButton_sum->setText(QCoreApplication::translate("dataShowForm", "\346\215\242\347\256\227", nullptr));
        label_6->setText(QCoreApplication::translate("dataShowForm", "asc\350\275\254\346\215\242", nullptr));
        pushButton_sum_asc->setText(QCoreApplication::translate("dataShowForm", "\346\215\242\347\256\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dataShowForm: public Ui_dataShowForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASHOWFORM_H
