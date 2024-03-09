/********************************************************************************
** Form generated from reading UI file 'form_small.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SMALL_H
#define UI_FORM_SMALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_small
{
public:
    QLineEdit *lineEdit_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QSlider *verticalSlider;
    QSpinBox *spinBox;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_2;
    QSlider *verticalSlider_2;
    QSpinBox *spinBox_2;

    void setupUi(QWidget *Form_small)
    {
        if (Form_small->objectName().isEmpty())
            Form_small->setObjectName(QString::fromUtf8("Form_small"));
        Form_small->resize(214, 326);
        lineEdit_3 = new QLineEdit(Form_small);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 0, 71, 23));
        widget = new QWidget(Form_small);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 41, 421));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);

        widget_2 = new QWidget(Form_small);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(40, 90, 67, 231));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        verticalSlider = new QSlider(widget_2);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(verticalSlider);

        spinBox = new QSpinBox(widget_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        verticalLayout_2->addWidget(spinBox);

        widget_3 = new QWidget(Form_small);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(180, 30, 41, 401));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEdit_6 = new QLineEdit(widget_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        verticalLayout_3->addWidget(lineEdit_6);

        lineEdit_7 = new QLineEdit(widget_3);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        verticalLayout_3->addWidget(lineEdit_7);

        widget_4 = new QWidget(Form_small);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(110, 90, 67, 231));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_2 = new QLineEdit(widget_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_4->addWidget(lineEdit_2);

        verticalSlider_2 = new QSlider(widget_4);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(verticalSlider_2);

        spinBox_2 = new QSpinBox(widget_4);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        verticalLayout_4->addWidget(spinBox_2);


        retranslateUi(Form_small);

        QMetaObject::connectSlotsByName(Form_small);
    } // setupUi

    void retranslateUi(QWidget *Form_small)
    {
        Form_small->setWindowTitle(QCoreApplication::translate("Form_small", "Form", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Form_small", " \345\220\215\345\255\227", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("Form_small", "40", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("Form_small", "0", nullptr));
        lineEdit->setText(QCoreApplication::translate("Form_small", "\344\270\212\351\231\220", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("Form_small", "40", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("Form_small", "0", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Form_small", "\344\270\212\351\231\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_small: public Ui_Form_small {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SMALL_H
