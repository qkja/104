/********************************************************************************
** Form generated from reading UI file 'trendchart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRENDCHART_H
#define UI_TRENDCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <linechart.h>
#include <ruler.h>

QT_BEGIN_NAMESPACE

class Ui_TrendChart
{
public:
    Ruler *widget;
    LineChart *widget_2;

    void setupUi(QWidget *TrendChart)
    {
        if (TrendChart->objectName().isEmpty())
            TrendChart->setObjectName(QString::fromUtf8("TrendChart"));
        TrendChart->resize(922, 548);
        widget = new Ruler(TrendChart);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 50, 321, 371));
        widget_2 = new LineChart(TrendChart);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(490, 60, 411, 441));

        retranslateUi(TrendChart);

        QMetaObject::connectSlotsByName(TrendChart);
    } // setupUi

    void retranslateUi(QWidget *TrendChart)
    {
        TrendChart->setWindowTitle(QCoreApplication::translate("TrendChart", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrendChart: public Ui_TrendChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRENDCHART_H
