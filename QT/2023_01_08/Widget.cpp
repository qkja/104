#include "Widget.h"
#include "qpushbutton.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QPushButton* b = new QPushButton("点击关闭矿口", this);
	this->resize(600, 400);
	connect(b, &QPushButton::clicked, this, &Widget::classOver);
	// 发出者
	// 接受者
	this->teacher = new Teacher();
	this->student = new Student();
	// 链接
	connect(teacher, &Teacher::hungury, student, &Student::eat);

	// 发出信号
	//classOver();
}

Widget::~Widget()
{}

void Widget::classOver()
{
	// 发出信号
	emit teacher->hungury();
}
