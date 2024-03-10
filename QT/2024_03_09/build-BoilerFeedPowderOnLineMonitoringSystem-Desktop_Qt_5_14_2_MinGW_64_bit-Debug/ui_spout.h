/********************************************************************************
** Form generated from reading UI file 'spout.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPOUT_H
#define UI_SPOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Spout
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Spout)
    {
        if (Spout->objectName().isEmpty())
            Spout->setObjectName(QString::fromUtf8("Spout"));
        Spout->resize(558, 390);
        pushButton = new QPushButton(Spout);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 220, 111, 41));
        pushButton_2 = new QPushButton(Spout);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 220, 111, 41));
        pushButton_3 = new QPushButton(Spout);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 220, 111, 41));
        lineEdit = new QLineEdit(Spout);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(180, 70, 151, 61));

        retranslateUi(Spout);

        QMetaObject::connectSlotsByName(Spout);
    } // setupUi

    void retranslateUi(QWidget *Spout)
    {
        Spout->setWindowTitle(QCoreApplication::translate("Spout", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Spout", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Spout", "\344\277\256\346\224\271", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Spout", "\351\200\200\345\207\272", nullptr));
        lineEdit->setText(QCoreApplication::translate("Spout", "\344\277\256\346\224\271\345\226\267\345\217\243\351\235\242\347\247\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Spout: public Ui_Spout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPOUT_H
