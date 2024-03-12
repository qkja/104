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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <alarmvalue.h>

QT_BEGIN_NAMESPACE

class Ui_GiveAnAlarm
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_determine;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_cancel;
    AlarmValue *widget_2;
    AlarmValue *widget_3;
    AlarmValue *widget_4;

    void setupUi(QWidget *GiveAnAlarm)
    {
        if (GiveAnAlarm->objectName().isEmpty())
            GiveAnAlarm->setObjectName(QString::fromUtf8("GiveAnAlarm"));
        GiveAnAlarm->resize(1028, 572);
        widget = new QWidget(GiveAnAlarm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(880, 150, 98, 301));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_determine = new QPushButton(widget);
        pushButton_determine->setObjectName(QString::fromUtf8("pushButton_determine"));

        verticalLayout->addWidget(pushButton_determine);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_cancel = new QPushButton(widget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        verticalLayout->addWidget(pushButton_cancel);

        widget_2 = new AlarmValue(GiveAnAlarm);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(20, 70, 171, 411));
        widget_3 = new AlarmValue(GiveAnAlarm);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(280, 60, 341, 411));
        widget_4 = new AlarmValue(GiveAnAlarm);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(681, 100, 191, 411));

        retranslateUi(GiveAnAlarm);

        QMetaObject::connectSlotsByName(GiveAnAlarm);
    } // setupUi

    void retranslateUi(QWidget *GiveAnAlarm)
    {
        GiveAnAlarm->setWindowTitle(QCoreApplication::translate("GiveAnAlarm", "Form", nullptr));
        pushButton_determine->setText(QCoreApplication::translate("GiveAnAlarm", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("GiveAnAlarm", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GiveAnAlarm: public Ui_GiveAnAlarm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIVEANALARM_H
