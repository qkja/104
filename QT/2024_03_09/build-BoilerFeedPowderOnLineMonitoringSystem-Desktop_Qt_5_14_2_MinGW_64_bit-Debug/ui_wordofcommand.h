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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WordOfCommand
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;

    void setupUi(QWidget *WordOfCommand)
    {
        if (WordOfCommand->objectName().isEmpty())
            WordOfCommand->setObjectName(QString::fromUtf8("WordOfCommand"));
        WordOfCommand->resize(400, 300);
        pushButton = new QPushButton(WordOfCommand);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 190, 111, 41));
        pushButton_2 = new QPushButton(WordOfCommand);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 180, 101, 51));
        lineEdit = new QLineEdit(WordOfCommand);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 70, 113, 23));
        lineEdit_2 = new QLineEdit(WordOfCommand);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 100, 113, 23));
        lineEdit_3 = new QLineEdit(WordOfCommand);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(180, 70, 113, 23));
        lineEdit_4 = new QLineEdit(WordOfCommand);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(180, 100, 113, 23));

        retranslateUi(WordOfCommand);

        QMetaObject::connectSlotsByName(WordOfCommand);
    } // setupUi

    void retranslateUi(QWidget *WordOfCommand)
    {
        WordOfCommand->setWindowTitle(QCoreApplication::translate("WordOfCommand", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("WordOfCommand", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("WordOfCommand", "\345\217\226\346\266\210", nullptr));
        lineEdit->setText(QCoreApplication::translate("WordOfCommand", "\346\227\247\345\217\243\344\273\244", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("WordOfCommand", "\346\226\260\345\217\243\344\273\244", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WordOfCommand: public Ui_WordOfCommand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDOFCOMMAND_H
