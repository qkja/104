/********************************************************************************
** Form generated from reading UI file 'mytime.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTIME_H
#define UI_MYTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTime
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MyTime)
    {
        if (MyTime->objectName().isEmpty())
            MyTime->setObjectName(QString::fromUtf8("MyTime"));
        MyTime->resize(400, 300);
        lineEdit = new QLineEdit(MyTime);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 60, 113, 23));
        pushButton = new QPushButton(MyTime);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 210, 111, 51));
        pushButton_2 = new QPushButton(MyTime);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 210, 111, 51));

        retranslateUi(MyTime);

        QMetaObject::connectSlotsByName(MyTime);
    } // setupUi

    void retranslateUi(QWidget *MyTime)
    {
        MyTime->setWindowTitle(QCoreApplication::translate("MyTime", "Form", nullptr));
        lineEdit->setText(QCoreApplication::translate("MyTime", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        pushButton->setText(QCoreApplication::translate("MyTime", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MyTime", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTime: public Ui_MyTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTIME_H
