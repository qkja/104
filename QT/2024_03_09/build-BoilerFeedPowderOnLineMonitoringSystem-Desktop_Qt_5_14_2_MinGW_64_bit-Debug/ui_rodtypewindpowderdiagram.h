/********************************************************************************
** Form generated from reading UI file 'rodtypewindpowderdiagram.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RODTYPEWINDPOWDERDIAGRAM_H
#define UI_RODTYPEWINDPOWDERDIAGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <graph.h>

QT_BEGIN_NAMESPACE

class Ui_RodTypeWindPowderDiagram
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    Graph *widget;
    Graph *widget_2;
    Graph *widget_3;

    void setupUi(QWidget *RodTypeWindPowderDiagram)
    {
        if (RodTypeWindPowderDiagram->objectName().isEmpty())
            RodTypeWindPowderDiagram->setObjectName(QString::fromUtf8("RodTypeWindPowderDiagram"));
        RodTypeWindPowderDiagram->resize(1219, 857);
        pushButton = new QPushButton(RodTypeWindPowderDiagram);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 790, 211, 31));
        pushButton_2 = new QPushButton(RodTypeWindPowderDiagram);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 790, 211, 31));
        widget = new Graph(RodTypeWindPowderDiagram);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 30, 1161, 211));
        widget_2 = new Graph(RodTypeWindPowderDiagram);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(20, 250, 1161, 211));
        widget_3 = new Graph(RodTypeWindPowderDiagram);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(20, 470, 1161, 211));

        retranslateUi(RodTypeWindPowderDiagram);

        QMetaObject::connectSlotsByName(RodTypeWindPowderDiagram);
    } // setupUi

    void retranslateUi(QWidget *RodTypeWindPowderDiagram)
    {
        RodTypeWindPowderDiagram->setWindowTitle(QCoreApplication::translate("RodTypeWindPowderDiagram", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("RodTypeWindPowderDiagram", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RodTypeWindPowderDiagram", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RodTypeWindPowderDiagram: public Ui_RodTypeWindPowderDiagram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RODTYPEWINDPOWDERDIAGRAM_H
