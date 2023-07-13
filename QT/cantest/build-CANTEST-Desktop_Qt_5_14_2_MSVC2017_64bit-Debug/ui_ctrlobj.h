/********************************************************************************
** Form generated from reading UI file 'ctrlobj.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRLOBJ_H
#define UI_CTRLOBJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ctrlobj
{
public:
    QPushButton *bt_Connected;
    QComboBox *CB_Baud;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *CB_EXT;
    QComboBox *CB_RTR;
    QPushButton *BT_Send;
    QLineEdit *T_ID;
    QLineEdit *T_DATA;
    QTextEdit *textEdit;

    void setupUi(QWidget *ctrlobj)
    {
        if (ctrlobj->objectName().isEmpty())
            ctrlobj->setObjectName(QString::fromUtf8("ctrlobj"));
        ctrlobj->resize(637, 474);
        bt_Connected = new QPushButton(ctrlobj);
        bt_Connected->setObjectName(QString::fromUtf8("bt_Connected"));
        bt_Connected->setGeometry(QRect(200, 10, 75, 23));
        CB_Baud = new QComboBox(ctrlobj);
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->addItem(QString());
        CB_Baud->setObjectName(QString::fromUtf8("CB_Baud"));
        CB_Baud->setGeometry(QRect(120, 10, 69, 22));
        CB_Baud->setInsertPolicy(QComboBox::InsertAtBottom);
        label = new QLabel(ctrlobj);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 54, 12));
        label_2 = new QLabel(ctrlobj);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 60, 54, 12));
        label_3 = new QLabel(ctrlobj);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 100, 54, 12));
        label_4 = new QLabel(ctrlobj);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 130, 54, 12));
        label_5 = new QLabel(ctrlobj);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 160, 54, 12));
        CB_EXT = new QComboBox(ctrlobj);
        CB_EXT->addItem(QString());
        CB_EXT->addItem(QString());
        CB_EXT->setObjectName(QString::fromUtf8("CB_EXT"));
        CB_EXT->setGeometry(QRect(120, 50, 69, 22));
        CB_EXT->setInsertPolicy(QComboBox::InsertAtBottom);
        CB_RTR = new QComboBox(ctrlobj);
        CB_RTR->addItem(QString());
        CB_RTR->addItem(QString());
        CB_RTR->setObjectName(QString::fromUtf8("CB_RTR"));
        CB_RTR->setGeometry(QRect(120, 90, 69, 22));
        CB_RTR->setInsertPolicy(QComboBox::InsertAtBottom);
        BT_Send = new QPushButton(ctrlobj);
        BT_Send->setObjectName(QString::fromUtf8("BT_Send"));
        BT_Send->setGeometry(QRect(380, 150, 75, 23));
        T_ID = new QLineEdit(ctrlobj);
        T_ID->setObjectName(QString::fromUtf8("T_ID"));
        T_ID->setGeometry(QRect(120, 120, 113, 20));
        T_ID->setMaxLength(8);
        T_DATA = new QLineEdit(ctrlobj);
        T_DATA->setObjectName(QString::fromUtf8("T_DATA"));
        T_DATA->setGeometry(QRect(120, 160, 151, 20));
        T_DATA->setMaxLength(23);
        textEdit = new QTextEdit(ctrlobj);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(70, 220, 461, 151));

        retranslateUi(ctrlobj);

        CB_Baud->setCurrentIndex(0);
        CB_EXT->setCurrentIndex(0);
        CB_RTR->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ctrlobj);
    } // setupUi

    void retranslateUi(QWidget *ctrlobj)
    {
        ctrlobj->setWindowTitle(QCoreApplication::translate("ctrlobj", "ctrlobj", nullptr));
        bt_Connected->setText(QCoreApplication::translate("ctrlobj", "\350\277\236\346\216\245", nullptr));
        CB_Baud->setItemText(0, QCoreApplication::translate("ctrlobj", "1000k", nullptr));
        CB_Baud->setItemText(1, QCoreApplication::translate("ctrlobj", "800k", nullptr));
        CB_Baud->setItemText(2, QCoreApplication::translate("ctrlobj", "666k", nullptr));
        CB_Baud->setItemText(3, QCoreApplication::translate("ctrlobj", "500k", nullptr));
        CB_Baud->setItemText(4, QCoreApplication::translate("ctrlobj", "400k", nullptr));
        CB_Baud->setItemText(5, QCoreApplication::translate("ctrlobj", "250k", nullptr));
        CB_Baud->setItemText(6, QCoreApplication::translate("ctrlobj", "200k", nullptr));
        CB_Baud->setItemText(7, QCoreApplication::translate("ctrlobj", "125k", nullptr));
        CB_Baud->setItemText(8, QCoreApplication::translate("ctrlobj", "100k", nullptr));
        CB_Baud->setItemText(9, QCoreApplication::translate("ctrlobj", "80k", nullptr));
        CB_Baud->setItemText(10, QCoreApplication::translate("ctrlobj", "50k", nullptr));

        CB_Baud->setCurrentText(QCoreApplication::translate("ctrlobj", "1000k", nullptr));
        label->setText(QCoreApplication::translate("ctrlobj", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("ctrlobj", "\345\270\247\347\261\273\345\236\213\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("ctrlobj", "\345\270\247\346\240\274\345\274\217\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("ctrlobj", "\345\270\247ID\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("ctrlobj", "\345\270\247\346\225\260\346\215\256\357\274\232", nullptr));
        CB_EXT->setItemText(0, QCoreApplication::translate("ctrlobj", "\346\240\207\345\207\206\345\270\247", nullptr));
        CB_EXT->setItemText(1, QCoreApplication::translate("ctrlobj", "\346\211\251\345\261\225\345\270\247", nullptr));

        CB_EXT->setCurrentText(QCoreApplication::translate("ctrlobj", "\346\240\207\345\207\206\345\270\247", nullptr));
        CB_RTR->setItemText(0, QCoreApplication::translate("ctrlobj", "\346\225\260\346\215\256\345\270\247", nullptr));
        CB_RTR->setItemText(1, QCoreApplication::translate("ctrlobj", "\350\277\234\347\250\213\345\270\247", nullptr));

        CB_RTR->setCurrentText(QCoreApplication::translate("ctrlobj", "\346\225\260\346\215\256\345\270\247", nullptr));
        BT_Send->setText(QCoreApplication::translate("ctrlobj", "\345\217\221\351\200\201", nullptr));
        T_ID->setText(QCoreApplication::translate("ctrlobj", "00000008", nullptr));
        T_DATA->setText(QCoreApplication::translate("ctrlobj", "00 01 02 03 04 05 06 07", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ctrlobj: public Ui_ctrlobj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRLOBJ_H
