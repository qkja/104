#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* mybutton = new QPushButton(this);
    mybutton->setText("按钮");
    mybutton->move(200, 300);
}

Widget::~Widget()
{
    delete ui;
}

