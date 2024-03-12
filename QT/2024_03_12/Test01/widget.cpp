#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    ui->groupBox->setTitle("1111");
    QObject::connect( ui->verticalSlider, &QSlider::valueChanged, [=](int value) {
           ui->label->setNum(value);
    });

//    ui->label->setNum(-10);
//            ui->label_6;
}

Widget::~Widget()
{
    delete ui;
}

