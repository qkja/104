/********************************************************************************
** Form generated from reading UI file 'alarm.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARM_H
#define UI_ALARM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <form_small.h>

QT_BEGIN_NAMESPACE

class Ui_Alarm
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    Form_small *widget_1;
    Form_small *widget_2;
    Form_small *widget_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Alarm)
    {
        if (Alarm->objectName().isEmpty())
            Alarm->setObjectName(QString::fromUtf8("Alarm"));
        Alarm->resize(877, 633);
        centralwidget = new QWidget(Alarm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(720, 140, 89, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(720, 350, 89, 24));
        widget_1 = new Form_small(centralwidget);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setGeometry(QRect(30, 100, 181, 381));
        widget_2 = new Form_small(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(290, 100, 171, 341));
        widget_3 = new Form_small(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(540, 110, 161, 331));
        Alarm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Alarm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 877, 25));
        Alarm->setMenuBar(menubar);
        statusbar = new QStatusBar(Alarm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Alarm->setStatusBar(statusbar);

        retranslateUi(Alarm);

        QMetaObject::connectSlotsByName(Alarm);
    } // setupUi

    void retranslateUi(QMainWindow *Alarm)
    {
        Alarm->setWindowTitle(QCoreApplication::translate("Alarm", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("Alarm", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Alarm", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Alarm: public Ui_Alarm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARM_H
