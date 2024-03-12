/********************************************************************************
** Form generated from reading UI file 'alarmvalue.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMVALUE_H
#define UI_ALARMVALUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <customverticalscrollbar.h>

QT_BEGIN_NAMESPACE

class Ui_AlarmValue
{
public:
    QGroupBox *groupBox;
    CustomVerticalScrollBar *verticalSlider;
    CustomVerticalScrollBar *verticalSlider_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *AlarmValue)
    {
        if (AlarmValue->objectName().isEmpty())
            AlarmValue->setObjectName(QString::fromUtf8("AlarmValue"));
        AlarmValue->resize(359, 376);
        groupBox = new QGroupBox(AlarmValue);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 341, 371));
        verticalSlider = new CustomVerticalScrollBar(groupBox);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(70, 70, 71, 231));
        verticalSlider->setValue(0);
        verticalSlider->setSliderPosition(0);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider_2 = new CustomVerticalScrollBar(groupBox);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(180, 70, 71, 231));
        verticalSlider_2->setOrientation(Qt::Vertical);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 320, 72, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 72, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 290, 72, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 60, 72, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 290, 72, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(190, 320, 72, 21));
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(90, 290, 71, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(180, 290, 71, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(180, 60, 71, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(groupBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(70, 60, 71, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 40, 72, 21));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(190, 40, 72, 21));

        retranslateUi(AlarmValue);

        QMetaObject::connectSlotsByName(AlarmValue);
    } // setupUi

    void retranslateUi(QWidget *AlarmValue)
    {
        AlarmValue->setWindowTitle(QCoreApplication::translate("AlarmValue", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AlarmValue", "\346\265\223\345\272\246", nullptr));
        label->setText(QCoreApplication::translate("AlarmValue", "\345\275\223\345\211\215\346\225\260\346\215\256", nullptr));
        label_2->setText(QCoreApplication::translate("AlarmValue", "\346\234\200\345\244\247", nullptr));
        label_3->setText(QCoreApplication::translate("AlarmValue", "\346\234\200\345\260\217", nullptr));
        label_4->setText(QCoreApplication::translate("AlarmValue", "\346\234\200\345\244\247", nullptr));
        label_5->setText(QCoreApplication::translate("AlarmValue", "\346\234\200\345\260\217", nullptr));
        label_6->setText(QCoreApplication::translate("AlarmValue", "\345\275\223\345\211\215\346\225\260\346\215\256", nullptr));
        label_7->setText(QCoreApplication::translate("AlarmValue", "\344\270\212\351\231\220", nullptr));
        label_8->setText(QCoreApplication::translate("AlarmValue", "\344\270\213\351\231\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlarmValue: public Ui_AlarmValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMVALUE_H
