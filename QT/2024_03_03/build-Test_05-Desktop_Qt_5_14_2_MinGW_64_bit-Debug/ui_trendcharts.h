/********************************************************************************
** Form generated from reading UI file 'trendcharts.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRENDCHARTS_H
#define UI_TRENDCHARTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrendCharts
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TrendCharts)
    {
        if (TrendCharts->objectName().isEmpty())
            TrendCharts->setObjectName(QString::fromUtf8("TrendCharts"));
        TrendCharts->resize(800, 600);
        centralwidget = new QWidget(TrendCharts);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 270, 113, 23));
        TrendCharts->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TrendCharts);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        TrendCharts->setMenuBar(menubar);
        statusbar = new QStatusBar(TrendCharts);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TrendCharts->setStatusBar(statusbar);

        retranslateUi(TrendCharts);

        QMetaObject::connectSlotsByName(TrendCharts);
    } // setupUi

    void retranslateUi(QMainWindow *TrendCharts)
    {
        TrendCharts->setWindowTitle(QCoreApplication::translate("TrendCharts", "MainWindow", nullptr));
        lineEdit->setText(QCoreApplication::translate("TrendCharts", "\350\277\231\346\230\257\347\254\254\344\270\211\347\253\240\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrendCharts: public Ui_TrendCharts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRENDCHARTS_H
