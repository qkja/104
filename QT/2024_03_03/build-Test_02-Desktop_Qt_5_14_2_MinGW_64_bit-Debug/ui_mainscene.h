/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mainscene
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *Mainscene)
    {
        if (Mainscene->objectName().isEmpty())
            Mainscene->setObjectName(QString::fromUtf8("Mainscene"));
        Mainscene->resize(800, 600);
        actionquit = new QAction(Mainscene);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        centralwidget = new QWidget(Mainscene);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Mainscene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Mainscene);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Mainscene->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionquit);

        retranslateUi(Mainscene);

        QMetaObject::connectSlotsByName(Mainscene);
    } // setupUi

    void retranslateUi(QMainWindow *Mainscene)
    {
        Mainscene->setWindowTitle(QCoreApplication::translate("Mainscene", "Mainscene", nullptr));
        actionquit->setText(QCoreApplication::translate("Mainscene", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QCoreApplication::translate("Mainscene", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mainscene: public Ui_Mainscene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
