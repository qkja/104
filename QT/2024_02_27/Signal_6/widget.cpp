#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    connect(button, &QPushButton::clicked, this, [](){
        qDebug() <<"被执行了";
    });
}

Widget::~Widget()
{
    delete ui;
}

