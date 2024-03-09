#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //    QRect rect1 = this->geometry();
    //    QRect rect2 = this->frameGeometry();
    //    qDebug() << rect1;
    //    qDebug() << rect2;
    QPushButton* buuton = new QPushButton(this);
    buuton->setText("按钮");
    buuton->move(200, 300);
    connect(buuton, &QPushButton::clicked, this, &Widget::handle);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    QRect rect1 = this->geometry();
    QRect rect2 = this->frameGeometry();
    qDebug() << rect1;
    qDebug() << rect2;
}

