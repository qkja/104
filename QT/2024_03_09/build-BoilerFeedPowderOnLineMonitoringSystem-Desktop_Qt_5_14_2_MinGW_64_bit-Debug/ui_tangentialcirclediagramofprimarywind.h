/********************************************************************************
** Form generated from reading UI file 'tangentialcirclediagramofprimarywind.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TANGENTIALCIRCLEDIAGRAMOFPRIMARYWIND_H
#define UI_TANGENTIALCIRCLEDIAGRAMOFPRIMARYWIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <square.h>

QT_BEGIN_NAMESPACE

class Ui_TangentialCircleDiagramOfPrimaryWind
{
public:
    QPushButton *pushButton;
    Square *widget;
    Square *widget_2;
    Square *widget_3;
    Square *widget_4;
    Square *widget_5;
    Square *widget_6;

    void setupUi(QWidget *TangentialCircleDiagramOfPrimaryWind)
    {
        if (TangentialCircleDiagramOfPrimaryWind->objectName().isEmpty())
            TangentialCircleDiagramOfPrimaryWind->setObjectName(QString::fromUtf8("TangentialCircleDiagramOfPrimaryWind"));
        TangentialCircleDiagramOfPrimaryWind->resize(1374, 588);
        pushButton = new QPushButton(TangentialCircleDiagramOfPrimaryWind);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 89, 24));
        widget = new Square(TangentialCircleDiagramOfPrimaryWind);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 50, 431, 231));
        widget_2 = new Square(TangentialCircleDiagramOfPrimaryWind);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(560, 30, 401, 241));
        widget_3 = new Square(TangentialCircleDiagramOfPrimaryWind);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(990, 30, 271, 251));
        widget_4 = new Square(TangentialCircleDiagramOfPrimaryWind);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(960, 290, 271, 251));
        widget_5 = new Square(TangentialCircleDiagramOfPrimaryWind);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(30, 310, 431, 231));
        widget_6 = new Square(TangentialCircleDiagramOfPrimaryWind);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(530, 290, 401, 241));

        retranslateUi(TangentialCircleDiagramOfPrimaryWind);

        QMetaObject::connectSlotsByName(TangentialCircleDiagramOfPrimaryWind);
    } // setupUi

    void retranslateUi(QWidget *TangentialCircleDiagramOfPrimaryWind)
    {
        TangentialCircleDiagramOfPrimaryWind->setWindowTitle(QCoreApplication::translate("TangentialCircleDiagramOfPrimaryWind", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("TangentialCircleDiagramOfPrimaryWind", "\344\270\200\346\254\241\351\243\216\345\210\207\345\234\206\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TangentialCircleDiagramOfPrimaryWind: public Ui_TangentialCircleDiagramOfPrimaryWind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TANGENTIALCIRCLEDIAGRAMOFPRIMARYWIND_H
