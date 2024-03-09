/********************************************************************************
** Form generated from reading UI file 'wordofcommand.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORDOFCOMMAND_H
#define UI_WORDOFCOMMAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WordOfCommand
{
public:

    void setupUi(QWidget *WordOfCommand)
    {
        if (WordOfCommand->objectName().isEmpty())
            WordOfCommand->setObjectName(QString::fromUtf8("WordOfCommand"));
        WordOfCommand->resize(400, 300);

        retranslateUi(WordOfCommand);

        QMetaObject::connectSlotsByName(WordOfCommand);
    } // setupUi

    void retranslateUi(QWidget *WordOfCommand)
    {
        WordOfCommand->setWindowTitle(QCoreApplication::translate("WordOfCommand", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WordOfCommand: public Ui_WordOfCommand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDOFCOMMAND_H
