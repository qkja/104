#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

Widget::~Widget()
{}
