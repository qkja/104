/********************************************************************************
** Form generated from reading UI file 'alarmdatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMDATABASE_H
#define UI_ALARMDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmDatabase
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *AlarmDatabase)
    {
        if (AlarmDatabase->objectName().isEmpty())
            AlarmDatabase->setObjectName(QString::fromUtf8("AlarmDatabase"));
        AlarmDatabase->resize(926, 595);
        tableWidget = new QTableWidget(AlarmDatabase);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(200, 160, 591, 192));
        pushButton = new QPushButton(AlarmDatabase);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 480, 141, 51));
        pushButton_2 = new QPushButton(AlarmDatabase);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 470, 141, 51));

        retranslateUi(AlarmDatabase);

        QMetaObject::connectSlotsByName(AlarmDatabase);
    } // setupUi

    void retranslateUi(QWidget *AlarmDatabase)
    {
        AlarmDatabase->setWindowTitle(QCoreApplication::translate("AlarmDatabase", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AlarmDatabase", "\344\274\240\346\204\237\345\231\250\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AlarmDatabase", "\345\207\272\351\231\220\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AlarmDatabase", "\350\265\267\345\247\213\346\227\266\351\227\264\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AlarmDatabase", "\346\236\201\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AlarmDatabase", "\347\273\223\346\235\237\346\227\266\351\227\264\347\202\271", nullptr));
        pushButton->setText(QCoreApplication::translate("AlarmDatabase", "\345\210\267\346\226\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AlarmDatabase", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlarmDatabase: public Ui_AlarmDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMDATABASE_H
