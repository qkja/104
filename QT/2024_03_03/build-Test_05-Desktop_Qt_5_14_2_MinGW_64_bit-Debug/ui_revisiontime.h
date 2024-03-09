/********************************************************************************
** Form generated from reading UI file 'revisiontime.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVISIONTIME_H
#define UI_REVISIONTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RevisionTime
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_2;
    QTimeEdit *timeEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *RevisionTime)
    {
        if (RevisionTime->objectName().isEmpty())
            RevisionTime->setObjectName(QString::fromUtf8("RevisionTime"));
        RevisionTime->resize(605, 349);
        widget = new QWidget(RevisionTime);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 60, 279, 42));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout->addWidget(dateEdit);

        widget_2 = new QWidget(RevisionTime);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(90, 110, 239, 42));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        timeEdit = new QTimeEdit(widget_2);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));

        horizontalLayout_2->addWidget(timeEdit);

        pushButton = new QPushButton(RevisionTime);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 240, 89, 24));
        pushButton_2 = new QPushButton(RevisionTime);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 240, 89, 24));

        retranslateUi(RevisionTime);

        QMetaObject::connectSlotsByName(RevisionTime);
    } // setupUi

    void retranslateUi(QWidget *RevisionTime)
    {
        RevisionTime->setWindowTitle(QCoreApplication::translate("RevisionTime", "Form", nullptr));
        lineEdit->setText(QCoreApplication::translate("RevisionTime", "\346\227\245\346\234\237", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("RevisionTime", "\346\227\266\351\227\264", nullptr));
        pushButton->setText(QCoreApplication::translate("RevisionTime", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RevisionTime", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RevisionTime: public Ui_RevisionTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVISIONTIME_H
