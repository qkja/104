#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(200, 300);
    connect(button, &QPushButton::clicked, this, &Widget::handleClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClicked()
{
    // 修改窗口的标题
    this->setWindowTitle("按钮已经按下");
}

