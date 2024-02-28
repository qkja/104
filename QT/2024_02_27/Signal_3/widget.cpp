#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    connect(ui->pushButton, &QPushButton::clicked, this, )
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    this->setWindowTitle("按钮以及按下");
}
