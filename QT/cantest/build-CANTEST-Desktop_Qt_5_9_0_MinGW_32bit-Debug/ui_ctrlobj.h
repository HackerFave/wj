/********************************************************************************
** Form generated from reading UI file 'ctrlobj.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRLOBJ_H
#define UI_CTRLOBJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
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
            ctrlobj->setObjectName(QStringLiteral("ctrlobj"));
        ctrlobj->resize(637, 474);
        bt_Connected = new QPushButton(ctrlobj);
        bt_Connected->setObjectName(QStringLiteral("bt_Connected"));
        bt_Connected->setGeometry(QRect(200, 10, 75, 23));
        CB_Baud = new QComboBox(ctrlobj);
        CB_Baud->setObjectName(QStringLiteral("CB_Baud"));
        CB_Baud->setGeometry(QRect(120, 10, 69, 22));
        CB_Baud->setInsertPolicy(QComboBox::InsertAtBottom);
        label = new QLabel(ctrlobj);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 20, 54, 12));
        label_2 = new QLabel(ctrlobj);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 60, 54, 12));
        label_3 = new QLabel(ctrlobj);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 100, 54, 12));
        label_4 = new QLabel(ctrlobj);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 130, 54, 12));
        label_5 = new QLabel(ctrlobj);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 160, 54, 12));
        CB_EXT = new QComboBox(ctrlobj);
        CB_EXT->setObjectName(QStringLiteral("CB_EXT"));
        CB_EXT->setGeometry(QRect(120, 50, 69, 22));
        CB_EXT->setInsertPolicy(QComboBox::InsertAtBottom);
        CB_RTR = new QComboBox(ctrlobj);
        CB_RTR->setObjectName(QStringLiteral("CB_RTR"));
        CB_RTR->setGeometry(QRect(120, 90, 69, 22));
        CB_RTR->setInsertPolicy(QComboBox::InsertAtBottom);
        BT_Send = new QPushButton(ctrlobj);
        BT_Send->setObjectName(QStringLiteral("BT_Send"));
        BT_Send->setGeometry(QRect(380, 150, 75, 23));
        T_ID = new QLineEdit(ctrlobj);
        T_ID->setObjectName(QStringLiteral("T_ID"));
        T_ID->setGeometry(QRect(120, 120, 113, 20));
        T_ID->setMaxLength(8);
        T_DATA = new QLineEdit(ctrlobj);
        T_DATA->setObjectName(QStringLiteral("T_DATA"));
        T_DATA->setGeometry(QRect(120, 160, 151, 20));
        T_DATA->setMaxLength(23);
        textEdit = new QTextEdit(ctrlobj);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(70, 220, 461, 151));

        retranslateUi(ctrlobj);

        CB_Baud->setCurrentIndex(0);
        CB_EXT->setCurrentIndex(0);
        CB_RTR->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ctrlobj);
    } // setupUi

    void retranslateUi(QWidget *ctrlobj)
    {
        ctrlobj->setWindowTitle(QApplication::translate("ctrlobj", "ctrlobj", Q_NULLPTR));
        bt_Connected->setText(QApplication::translate("ctrlobj", "\350\277\236\346\216\245", Q_NULLPTR));
        CB_Baud->clear();
        CB_Baud->insertItems(0, QStringList()
         << QApplication::translate("ctrlobj", "1000k", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "800k", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "666k", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "500k", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "400k", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "250k", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "200k", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "125k", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "100k", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "80k", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "50k", Q_NULLPTR)
        );
        CB_Baud->setCurrentText(QApplication::translate("ctrlobj", "1000k", Q_NULLPTR));
        label->setText(QApplication::translate("ctrlobj", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ctrlobj", "\345\270\247\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("ctrlobj", "\345\270\247\346\240\274\345\274\217\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ctrlobj", "\345\270\247ID\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("ctrlobj", "\345\270\247\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        CB_EXT->clear();
        CB_EXT->insertItems(0, QStringList()
         << QApplication::translate("ctrlobj", "\346\240\207\345\207\206\345\270\247", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "\346\211\251\345\261\225\345\270\247", Q_NULLPTR)
        );
        CB_EXT->setCurrentText(QApplication::translate("ctrlobj", "\346\240\207\345\207\206\345\270\247", Q_NULLPTR));
        CB_RTR->clear();
        CB_RTR->insertItems(0, QStringList()
         << QApplication::translate("ctrlobj", "\346\225\260\346\215\256\345\270\247", Q_NULLPTR)
         << QApplication::translate("ctrlobj", "\350\277\234\347\250\213\345\270\247", Q_NULLPTR)
        );
        CB_RTR->setCurrentText(QApplication::translate("ctrlobj", "\346\225\260\346\215\256\345\270\247", Q_NULLPTR));
        BT_Send->setText(QApplication::translate("ctrlobj", "\345\217\221\351\200\201", Q_NULLPTR));
        T_ID->setText(QApplication::translate("ctrlobj", "00000008", Q_NULLPTR));
        T_DATA->setText(QApplication::translate("ctrlobj", "00 01 02 03 04 05 06 07", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ctrlobj: public Ui_ctrlobj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRLOBJ_H
