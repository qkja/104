/********************************************************************************
** Form generated from reading UI file 'mymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMainWindow
{
public:
    QAction *actionaction_01;
    QAction *actionaction_02;
    QAction *actionaction_03;
    QAction *actionaction_04;
    QAction *actionaction_05;
    QAction *actionaction_6;
    QAction *actionaction_06;
    QAction *actionfig_01;
    QAction *actionfig_02;
    QAction *actionfig_03;
    QAction *actiondata;
    QAction *actiondata_02;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyMainWindow)
    {
        if (MyMainWindow->objectName().isEmpty())
            MyMainWindow->setObjectName(QString::fromUtf8("MyMainWindow"));
        MyMainWindow->resize(800, 600);
        actionaction_01 = new QAction(MyMainWindow);
        actionaction_01->setObjectName(QString::fromUtf8("actionaction_01"));
        actionaction_02 = new QAction(MyMainWindow);
        actionaction_02->setObjectName(QString::fromUtf8("actionaction_02"));
        actionaction_03 = new QAction(MyMainWindow);
        actionaction_03->setObjectName(QString::fromUtf8("actionaction_03"));
        actionaction_04 = new QAction(MyMainWindow);
        actionaction_04->setObjectName(QString::fromUtf8("actionaction_04"));
        actionaction_05 = new QAction(MyMainWindow);
        actionaction_05->setObjectName(QString::fromUtf8("actionaction_05"));
        actionaction_6 = new QAction(MyMainWindow);
        actionaction_6->setObjectName(QString::fromUtf8("actionaction_6"));
        actionaction_06 = new QAction(MyMainWindow);
        actionaction_06->setObjectName(QString::fromUtf8("actionaction_06"));
        actionfig_01 = new QAction(MyMainWindow);
        actionfig_01->setObjectName(QString::fromUtf8("actionfig_01"));
        actionfig_02 = new QAction(MyMainWindow);
        actionfig_02->setObjectName(QString::fromUtf8("actionfig_02"));
        actionfig_03 = new QAction(MyMainWindow);
        actionfig_03->setObjectName(QString::fromUtf8("actionfig_03"));
        actiondata = new QAction(MyMainWindow);
        actiondata->setObjectName(QString::fromUtf8("actiondata"));
        actiondata_02 = new QAction(MyMainWindow);
        actiondata_02->setObjectName(QString::fromUtf8("actiondata_02"));
        centralwidget = new QWidget(MyMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MyMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MyMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MyMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MyMainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actionaction_01);
        menu->addSeparator();
        menu->addAction(actionaction_02);
        menu->addSeparator();
        menu->addAction(actionaction_03);
        menu->addSeparator();
        menu->addAction(actionaction_04);
        menu->addSeparator();
        menu->addAction(actionaction_05);
        menu->addSeparator();
        menu->addAction(actionaction_6);
        menu->addSeparator();
        menu_2->addAction(actionfig_01);
        menu_2->addAction(actionfig_02);
        menu_2->addAction(actionfig_03);
        menu_3->addAction(actiondata);
        menu_3->addAction(actiondata_02);

        retranslateUi(MyMainWindow);

        QMetaObject::connectSlotsByName(MyMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyMainWindow)
    {
        MyMainWindow->setWindowTitle(QCoreApplication::translate("MyMainWindow", "MainWindow", nullptr));
        actionaction_01->setText(QCoreApplication::translate("MyMainWindow", "\350\256\276\345\256\232\350\203\214\351\235\240\347\256\241", nullptr));
        actionaction_02->setText(QCoreApplication::translate("MyMainWindow", "\350\256\276\345\256\232\345\226\267\345\217\243", nullptr));
        actionaction_03->setText(QCoreApplication::translate("MyMainWindow", "\350\256\276\345\256\232\347\263\273\346\225\260", nullptr));
        actionaction_04->setText(QCoreApplication::translate("MyMainWindow", "\344\277\256\346\224\271\345\217\243\344\273\244", nullptr));
        actionaction_05->setText(QCoreApplication::translate("MyMainWindow", "\344\277\256\345\256\232\346\227\266\351\227\264", nullptr));
        actionaction_6->setText(QCoreApplication::translate("MyMainWindow", "\351\200\200\345\207\272", nullptr));
        actionaction_06->setText(QCoreApplication::translate("MyMainWindow", "\344\277\256\346\224\271\351\235\240\350\203\214\347\256\241\347\263\273\346\225\260", nullptr));
        actionfig_01->setText(QCoreApplication::translate("MyMainWindow", "\346\243\222\345\236\213\351\243\216\347\262\211\345\233\276", nullptr));
        actionfig_02->setText(QCoreApplication::translate("MyMainWindow", "\344\270\200\346\254\241\351\243\216\345\210\207\345\234\206\345\233\276", nullptr));
        actionfig_03->setText(QCoreApplication::translate("MyMainWindow", "\350\266\213\345\212\277\345\233\276\345\217\212\345\216\206\345\217\262\350\266\213\345\212\277\345\233\276", nullptr));
        actiondata->setText(QCoreApplication::translate("MyMainWindow", "\346\212\245\350\255\246\346\225\260\346\215\256", nullptr));
        actiondata_02->setText(QCoreApplication::translate("MyMainWindow", "\351\200\232\351\201\223\346\225\260\346\215\256", nullptr));
        menu->setTitle(QCoreApplication::translate("MyMainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MyMainWindow", "\347\212\266\346\200\201\346\237\245\347\234\213", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MyMainWindow", "\346\225\260\346\215\256\345\244\204\347\220\206", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MyMainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyMainWindow: public Ui_MyMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
