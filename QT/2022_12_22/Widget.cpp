#include "Widget.h"
#include <QPushButton>
Widget::Widget(QWidget* parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	QPushButton* button = new QPushButton;
	//button->show();

	button->setParent(this);
	// 设置按钮的熟悉

	// 名字
	button->setText("这是第一个按钮");
	// 位置
	button->move(100, 100);
	//大小
	button->setFixedSize(400, 400);


	// 这个另外一种
	auto p = new QPushButton("内容", this);

}

// 说一下我们创建按钮的区别
Widget::~Widget()
{}
