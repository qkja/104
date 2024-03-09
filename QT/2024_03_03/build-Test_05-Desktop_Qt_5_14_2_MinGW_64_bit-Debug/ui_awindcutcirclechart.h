/********************************************************************************
** Form generated from reading UI file 'awindcutcirclechart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AWINDCUTCIRCLECHART_H
#define UI_AWINDCUTCIRCLECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AWindcutCircleChart
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AWindcutCircleChart)
    {
        if (AWindcutCircleChart->objectName().isEmpty())
            AWindcutCircleChart->setObjectName(QString::fromUtf8("AWindcutCircleChart"));
        AWindcutCircleChart->resize(800, 600);
        centralwidget = new QWidget(AWindcutCircleChart);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(300, 170, 113, 23));
        AWindcutCircleChart->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AWindcutCircleChart);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        AWindcutCircleChart->setMenuBar(menubar);
        statusbar = new QStatusBar(AWindcutCircleChart);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AWindcutCircleChart->setStatusBar(statusbar);

        retranslateUi(AWindcutCircleChart);

        QMetaObject::connectSlotsByName(AWindcutCircleChart);
    } // setupUi

    void retranslateUi(QMainWindow *AWindcutCircleChart)
    {
        AWindcutCircleChart->setWindowTitle(QCoreApplication::translate("AWindcutCircleChart", "MainWindow", nullptr));
        lineEdit->setText(QCoreApplication::translate("AWindcutCircleChart", "\350\277\231\346\230\257\347\254\254\344\272\214\345\234\272\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AWindcutCircleChart: public Ui_AWindcutCircleChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AWINDCUTCIRCLECHART_H
