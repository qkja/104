/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QAction *action_01;
    QAction *spout;
    QAction *give_an_alarm;
    QAction *word_of_command;
    QAction *mytime;
    QAction *quit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *system_setting_menu_1;
    QMenu *status_view_menu_2;
    QMenu *data_processing_menu_3;
    QMenu *assist_menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName(QString::fromUtf8("MainScreen"));
        MainScreen->resize(800, 600);
        action_01 = new QAction(MainScreen);
        action_01->setObjectName(QString::fromUtf8("action_01"));
        spout = new QAction(MainScreen);
        spout->setObjectName(QString::fromUtf8("spout"));
        give_an_alarm = new QAction(MainScreen);
        give_an_alarm->setObjectName(QString::fromUtf8("give_an_alarm"));
        word_of_command = new QAction(MainScreen);
        word_of_command->setObjectName(QString::fromUtf8("word_of_command"));
        mytime = new QAction(MainScreen);
        mytime->setObjectName(QString::fromUtf8("mytime"));
        quit = new QAction(MainScreen);
        quit->setObjectName(QString::fromUtf8("quit"));
        centralwidget = new QWidget(MainScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScreen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        system_setting_menu_1 = new QMenu(menubar);
        system_setting_menu_1->setObjectName(QString::fromUtf8("system_setting_menu_1"));
        status_view_menu_2 = new QMenu(menubar);
        status_view_menu_2->setObjectName(QString::fromUtf8("status_view_menu_2"));
        data_processing_menu_3 = new QMenu(menubar);
        data_processing_menu_3->setObjectName(QString::fromUtf8("data_processing_menu_3"));
        assist_menu_4 = new QMenu(menubar);
        assist_menu_4->setObjectName(QString::fromUtf8("assist_menu_4"));
        MainScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(MainScreen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainScreen->setStatusBar(statusbar);

        menubar->addAction(system_setting_menu_1->menuAction());
        menubar->addAction(status_view_menu_2->menuAction());
        menubar->addAction(data_processing_menu_3->menuAction());
        menubar->addAction(assist_menu_4->menuAction());
        system_setting_menu_1->addAction(give_an_alarm);
        system_setting_menu_1->addAction(word_of_command);
        system_setting_menu_1->addAction(mytime);
        system_setting_menu_1->addAction(quit);
        system_setting_menu_1->addAction(spout);
        system_setting_menu_1->addSeparator();
        system_setting_menu_1->addSeparator();

        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QMainWindow *MainScreen)
    {
        MainScreen->setWindowTitle(QCoreApplication::translate("MainScreen", "MainWindow", nullptr));
        action_01->setText(QCoreApplication::translate("MainScreen", "\351\235\240\350\203\214\347\256\241\347\263\273\346\225\260\344\277\256\346\255\243", nullptr));
        spout->setText(QCoreApplication::translate("MainScreen", "\350\256\276\345\256\232\345\226\267\345\217\243\351\235\242\347\247\257", nullptr));
        give_an_alarm->setText(QCoreApplication::translate("MainScreen", "\350\256\276\345\256\232\346\212\245\350\255\246\351\231\220", nullptr));
        word_of_command->setText(QCoreApplication::translate("MainScreen", "\344\277\256\346\224\271\345\217\243\344\273\244", nullptr));
        mytime->setText(QCoreApplication::translate("MainScreen", "\344\277\256\345\256\232\346\227\266\351\227\264", nullptr));
        quit->setText(QCoreApplication::translate("MainScreen", "\351\200\200\345\207\272", nullptr));
        system_setting_menu_1->setTitle(QCoreApplication::translate("MainScreen", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        status_view_menu_2->setTitle(QCoreApplication::translate("MainScreen", "\347\212\266\346\200\201\346\237\245\347\234\213", nullptr));
        data_processing_menu_3->setTitle(QCoreApplication::translate("MainScreen", "\346\225\260\346\215\256\345\244\204\347\220\206", nullptr));
        assist_menu_4->setTitle(QCoreApplication::translate("MainScreen", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
