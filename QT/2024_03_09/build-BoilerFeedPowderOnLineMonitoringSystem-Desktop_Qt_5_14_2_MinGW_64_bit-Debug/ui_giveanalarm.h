/********************************************************************************
** Form generated from reading UI file 'giveanalarm.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIVEANALARM_H
#define UI_GIVEANALARM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GiveAnAlarm
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton_determine;
    QPushButton *pushButton_cancel;

    void setupUi(QWidget *GiveAnAlarm)
    {
        if (GiveAnAlarm->objectName().isEmpty())
            GiveAnAlarm->setObjectName(QString::fromUtf8("GiveAnAlarm"));
        GiveAnAlarm->resize(705, 506);
        lineEdit = new QLineEdit(GiveAnAlarm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 200, 113, 23));
        pushButton_determine = new QPushButton(GiveAnAlarm);
        pushButton_determine->setObjectName(QString::fromUtf8("pushButton_determine"));
        pushButton_determine->setGeometry(QRect(440, 100, 121, 71));
        pushButton_cancel = new QPushButton(GiveAnAlarm);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(440, 240, 121, 71));

        retranslateUi(GiveAnAlarm);

        QMetaObject::connectSlotsByName(GiveAnAlarm);
    } // setupUi

    void retranslateUi(QWidget *GiveAnAlarm)
    {
        GiveAnAlarm->setWindowTitle(QCoreApplication::translate("GiveAnAlarm", "Form", nullptr));
        lineEdit->setText(QCoreApplication::translate("GiveAnAlarm", "\346\212\245\350\255\246", nullptr));
        pushButton_determine->setText(QCoreApplication::translate("GiveAnAlarm", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("GiveAnAlarm", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GiveAnAlarm: public Ui_GiveAnAlarm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIVEANALARM_H
