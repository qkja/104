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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeScreen
{
public:
    QPushButton *welcome_pushButton;

    void setupUi(QWidget *WelcomeScreen)
    {
        if (WelcomeScreen->objectName().isEmpty())
            WelcomeScreen->setObjectName(QString::fromUtf8("WelcomeScreen"));
        WelcomeScreen->resize(800, 600);
        welcome_pushButton = new QPushButton(WelcomeScreen);
        welcome_pushButton->setObjectName(QString::fromUtf8("welcome_pushButton"));
        welcome_pushButton->setGeometry(QRect(340, 310, 161, 71));

        retranslateUi(WelcomeScreen);

        QMetaObject::connectSlotsByName(WelcomeScreen);
    } // setupUi

    void retranslateUi(QWidget *WelcomeScreen)
    {
        WelcomeScreen->setWindowTitle(QCoreApplication::translate("WelcomeScreen", "WelcomeScreen", nullptr));
        welcome_pushButton->setText(QCoreApplication::translate("WelcomeScreen", "\351\224\205\347\202\211\347\207\203\347\203\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeScreen: public Ui_WelcomeScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMESCREEN_H
