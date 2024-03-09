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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTime
{
public:

    void setupUi(QWidget *MyTime)
    {
        if (MyTime->objectName().isEmpty())
            MyTime->setObjectName(QString::fromUtf8("MyTime"));
        MyTime->resize(400, 300);

        retranslateUi(MyTime);

        QMetaObject::connectSlotsByName(MyTime);
    } // setupUi

    void retranslateUi(QWidget *MyTime)
    {
        MyTime->setWindowTitle(QCoreApplication::translate("MyTime", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTime: public Ui_MyTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTIME_H
