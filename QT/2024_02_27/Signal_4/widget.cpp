#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //    这里仅仅是建立链接,不代表我们的信号已经发出来了
    connect(this, &Widget::mySignal, this, &Widget::handleMySignal);
    // 调用信号函数,才是我们的发出信号的动作
    //    mySignal();
    emit mySignal();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleMySignal()
{
    this->setWindowTitle("窗口处理自定义信号");
}

