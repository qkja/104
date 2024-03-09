/********************************************************************************
** Form generated from reading UI file 'backrestcanal.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKRESTCANAL_H
#define UI_BACKRESTCANAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BackrestCanal
{
public:
    QLineEdit *lineEdit;

    void setupUi(QWidget *BackrestCanal)
    {
        if (BackrestCanal->objectName().isEmpty())
            BackrestCanal->setObjectName(QString::fromUtf8("BackrestCanal"));
        BackrestCanal->resize(400, 300);
        lineEdit = new QLineEdit(BackrestCanal);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 140, 113, 23));

        retranslateUi(BackrestCanal);

        QMetaObject::connectSlotsByName(BackrestCanal);
    } // setupUi

    void retranslateUi(QWidget *BackrestCanal)
    {
        BackrestCanal->setWindowTitle(QCoreApplication::translate("BackrestCanal", "Form", nullptr));
        lineEdit->setText(QCoreApplication::translate("BackrestCanal", "\351\235\240\350\203\214\347\256\241\347\263\273\346\225\260\344\277\256\346\255\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BackrestCanal: public Ui_BackrestCanal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKRESTCANAL_H
