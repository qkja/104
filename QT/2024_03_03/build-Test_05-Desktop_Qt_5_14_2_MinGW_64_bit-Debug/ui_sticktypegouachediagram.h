/********************************************************************************
** Form generated from reading UI file 'sticktypegouachediagram.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STICKTYPEGOUACHEDIAGRAM_H
#define UI_STICKTYPEGOUACHEDIAGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StickTypeGouacheDiagram
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StickTypeGouacheDiagram)
    {
        if (StickTypeGouacheDiagram->objectName().isEmpty())
            StickTypeGouacheDiagram->setObjectName(QString::fromUtf8("StickTypeGouacheDiagram"));
        StickTypeGouacheDiagram->resize(800, 600);
        centralwidget = new QWidget(StickTypeGouacheDiagram);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(340, 240, 113, 23));
        StickTypeGouacheDiagram->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StickTypeGouacheDiagram);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        StickTypeGouacheDiagram->setMenuBar(menubar);
        statusbar = new QStatusBar(StickTypeGouacheDiagram);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StickTypeGouacheDiagram->setStatusBar(statusbar);

        retranslateUi(StickTypeGouacheDiagram);

        QMetaObject::connectSlotsByName(StickTypeGouacheDiagram);
    } // setupUi

    void retranslateUi(QMainWindow *StickTypeGouacheDiagram)
    {
        StickTypeGouacheDiagram->setWindowTitle(QCoreApplication::translate("StickTypeGouacheDiagram", "MainWindow", nullptr));
        lineEdit->setText(QCoreApplication::translate("StickTypeGouacheDiagram", "\350\277\231\346\230\257  \347\254\254\344\270\200\344\270\252\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StickTypeGouacheDiagram: public Ui_StickTypeGouacheDiagram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STICKTYPEGOUACHEDIAGRAM_H
