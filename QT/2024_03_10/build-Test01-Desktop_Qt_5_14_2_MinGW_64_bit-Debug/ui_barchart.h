/********************************************************************************
** Form generated from reading UI file 'barchart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARCHART_H
#define UI_BARCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BarChart
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *BarChart)
    {
        if (BarChart->objectName().isEmpty())
            BarChart->setObjectName(QString::fromUtf8("BarChart"));
        BarChart->resize(400, 300);
        verticalLayoutWidget = new QWidget(BarChart);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 40, 241, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(BarChart);

        QMetaObject::connectSlotsByName(BarChart);
    } // setupUi

    void retranslateUi(QWidget *BarChart)
    {
        BarChart->setWindowTitle(QCoreApplication::translate("BarChart", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BarChart: public Ui_BarChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCHART_H
