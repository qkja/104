#include "widget.h"
#include "ui_widget.h"
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 1. 使用纯代码,
    //    QLabel lable;
    //可以在堆上创建, this 是指定对象树的节点的关联,当然也可以不指定
    QLabel* lable = new QLabel(this);
    lable->setText("hello world2");
}

Widget::~Widget()
{
    delete ui;
}

