#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    myButton = new QPushButton(this);
    myButton->setText("关闭窗口");
    myButton->move(200, 300);
    //    connect(myButton, &QPushButton::clicked, this, &Widget::handleClick);
    connect(myButton, &QPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{
    delete ui;
}

//void Widget::handleClick()
//{
//    close();
//}

