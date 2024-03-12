/********************************************************************************
** Form generated from reading UI file 'historicaltrendchart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORICALTRENDCHART_H
#define UI_HISTORICALTRENDCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <linechart.h>
#include <ruler.h>

QT_BEGIN_NAMESPACE

class Ui_HistoricalTrendChart
{
public:
    Ruler *widget;
    LineChart *widget_2;

    void setupUi(QWidget *HistoricalTrendChart)
    {
        if (HistoricalTrendChart->objectName().isEmpty())
            HistoricalTrendChart->setObjectName(QString::fromUtf8("HistoricalTrendChart"));
        HistoricalTrendChart->resize(824, 453);
        widget = new Ruler(HistoricalTrendChart);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 60, 151, 301));
        widget_2 = new LineChart(HistoricalTrendChart);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(290, 40, 381, 361));

        retranslateUi(HistoricalTrendChart);

        QMetaObject::connectSlotsByName(HistoricalTrendChart);
    } // setupUi

    void retranslateUi(QWidget *HistoricalTrendChart)
    {
        HistoricalTrendChart->setWindowTitle(QCoreApplication::translate("HistoricalTrendChart", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoricalTrendChart: public Ui_HistoricalTrendChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORICALTRENDCHART_H
