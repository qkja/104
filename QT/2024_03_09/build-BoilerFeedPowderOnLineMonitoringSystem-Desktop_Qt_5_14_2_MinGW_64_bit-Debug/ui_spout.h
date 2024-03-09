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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Spout
{
public:

    void setupUi(QWidget *Spout)
    {
        if (Spout->objectName().isEmpty())
            Spout->setObjectName(QString::fromUtf8("Spout"));
        Spout->resize(400, 300);

        retranslateUi(Spout);

        QMetaObject::connectSlotsByName(Spout);
    } // setupUi

    void retranslateUi(QWidget *Spout)
    {
        Spout->setWindowTitle(QCoreApplication::translate("Spout", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Spout: public Ui_Spout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPOUT_H
