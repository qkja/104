#pragma once

#include <QtWidgets/QWidget>

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

};
