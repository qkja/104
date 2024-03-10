/********************************************************************************
** Form generated from reading UI file 'verifypassword.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFYPASSWORD_H
#define UI_VERIFYPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerifyPassword
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *VerifyPassword)
    {
        if (VerifyPassword->objectName().isEmpty())
            VerifyPassword->setObjectName(QString::fromUtf8("VerifyPassword"));
        VerifyPassword->resize(400, 300);
        pushButton = new QPushButton(VerifyPassword);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 190, 81, 41));
        pushButton_2 = new QPushButton(VerifyPassword);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 190, 81, 41));
        lineEdit = new QLineEdit(VerifyPassword);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 100, 113, 23));
        lineEdit_2 = new QLineEdit(VerifyPassword);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 100, 113, 23));

        retranslateUi(VerifyPassword);

        QMetaObject::connectSlotsByName(VerifyPassword);
    } // setupUi

    void retranslateUi(QWidget *VerifyPassword)
    {
        VerifyPassword->setWindowTitle(QCoreApplication::translate("VerifyPassword", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("VerifyPassword", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("VerifyPassword", "\345\217\226\346\266\210", nullptr));
        lineEdit->setText(QCoreApplication::translate("VerifyPassword", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201:", nullptr));
        lineEdit_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VerifyPassword: public Ui_VerifyPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFYPASSWORD_H
