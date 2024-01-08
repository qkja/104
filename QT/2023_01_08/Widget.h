#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QWidget>
#include "ui_Widget.h"
#include "Teacher.h"
#include "Student.h"
class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();
	void classOver();
public:

	Teacher* teacher;
	Student* student;
private:
	Ui::WidgetClass ui;
};
