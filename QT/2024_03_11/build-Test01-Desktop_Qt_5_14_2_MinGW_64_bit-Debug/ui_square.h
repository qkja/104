/********************************************************************************
** Form generated from reading UI file 'square.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQUARE_H
#define UI_SQUARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Square
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Square)
    {
        if (Square->objectName().isEmpty())
            Square->setObjectName(QString::fromUtf8("Square"));
        Square->resize(400, 300);
        graphicsView = new QGraphicsView(Square);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(50, 40, 291, 211));

        retranslateUi(Square);

        QMetaObject::connectSlotsByName(Square);
    } // setupUi

    void retranslateUi(QWidget *Square)
    {
        Square->setWindowTitle(QCoreApplication::translate("Square", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Square: public Ui_Square {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQUARE_H
