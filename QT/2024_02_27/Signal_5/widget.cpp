#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(this, &Widget::mySignal, this, &Widget::handleClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick(const QString & text)
{
    this->setWindowTitle(text);
}


void Widget::on_pushButton_clicked()
{
    emit this->mySignal("带有参数的槽函数1", 1);
}

void Widget::on_pushButton_2_clicked()
{
    emit this->mySignal("带有参数的槽函数2", 2);
}
