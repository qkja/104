/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *pushButton_accept;
    QPushButton *pushButton_reject;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 130, 171, 111));
        pushButton_accept = new QPushButton(Widget);
        pushButton_accept->setObjectName(QString::fromUtf8("pushButton_accept"));
        pushButton_accept->setGeometry(QRect(210, 410, 141, 51));
        pushButton_reject = new QPushButton(Widget);
        pushButton_reject->setObjectName(QString::fromUtf8("pushButton_reject"));
        pushButton_reject->setGeometry(QRect(440, 400, 121, 61));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\245\263\347\245\236,\344\275\240\344\275\234\344\270\272\346\210\221\346\234\213\345\217\213\345\245\275\344\270\215\345\245\275", nullptr));
        pushButton_accept->setText(QCoreApplication::translate("Widget", "\345\220\214\346\204\217", nullptr));
        pushButton_reject->setText(QCoreApplication::translate("Widget", "\346\213\222\347\273\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
