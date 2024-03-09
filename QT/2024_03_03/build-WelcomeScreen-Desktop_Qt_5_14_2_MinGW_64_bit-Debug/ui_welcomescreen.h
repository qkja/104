/********************************************************************************
** Form generated from reading UI file 'welcomescreen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMESCREEN_H
#define UI_WELCOMESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeScreen
{
public:
    QWidget *centralwidget;
    QSlider *verticalSlider;
    QSpinBox *spinBox;
    QSlider *verticalSlider_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WelcomeScreen)
    {
        if (WelcomeScreen->objectName().isEmpty())
            WelcomeScreen->setObjectName(QString::fromUtf8("WelcomeScreen"));
        WelcomeScreen->resize(800, 600);
        centralwidget = new QWidget(WelcomeScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(160, 220, 71, 211));
        verticalSlider->setOrientation(Qt::Vertical);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(270, 360, 49, 24));
        verticalSlider_2 = new QSlider(centralwidget);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(510, 240, 18, 160));
        verticalSlider_2->setOrientation(Qt::Vertical);
        WelcomeScreen->setCentralWidget(centralwidget);
        spinBox->raise();
        verticalSlider_2->raise();
        verticalSlider->raise();
        menubar = new QMenuBar(WelcomeScreen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        WelcomeScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(WelcomeScreen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WelcomeScreen->setStatusBar(statusbar);

        retranslateUi(WelcomeScreen);

        QMetaObject::connectSlotsByName(WelcomeScreen);
    } // setupUi

    void retranslateUi(QMainWindow *WelcomeScreen)
    {
        WelcomeScreen->setWindowTitle(QCoreApplication::translate("WelcomeScreen", "WelcomeScreen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeScreen: public Ui_WelcomeScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMESCREEN_H
