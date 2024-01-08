#include "Widget.h"
#include "qpushbutton.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{


    QPushButton* b = new QPushButton("点击关闭矿口", this);
    this->resize(600, 400);
    connect(b, &QPushButton::clicked, this, &Widget::classOver);
    // 发出者
    // 接受者
    this->teacher = new Teacher();
    this->student = new Student();
    // 链接
    void(Teacher::*tearchersignal)(QString) =  &Teacher::hungury;
    void(Student::*studentsignal)(QString) =   &Student::eat;
    //	connect(teacher, &Teacher::hungury, student, &Student::eat);
    connect(teacher, tearchersignal, student, studentsignal);
    // 发出信号
    //classOver();
}

Widget::~Widget()
{}

void Widget::classOver()
{
    // 发出信号
    emit teacher->hungury("排骨");


}
