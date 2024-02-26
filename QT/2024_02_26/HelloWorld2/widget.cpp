#include "widget.h"
#include "ui_widget.h"
#include <QLineEdit>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 使用编辑框来实现helloword
    //    QLineEdit* qLineEdit = new QLineEdit(this);
    //    qLineEdit->setText("hello world");
    // 使用按钮来创建hello world
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    ui->pushButton->setText("hello qt");
}
