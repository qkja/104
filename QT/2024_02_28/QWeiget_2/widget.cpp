#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_clicked()
{
    qDebug() << "执行槽函数";
}

void Widget::on_pushButton_enable_clicked()
{
    // 1. 获取状态
    bool enable = ui->pushButton->isEnabled();
    if(enable)
    {
        qDebug()<<"设置禁用";
        ui->pushButton->setEnabled(false);
    }
    else
    {
        qDebug()<<"设置可用";
        ui->pushButton->setEnabled(true);
    }
}