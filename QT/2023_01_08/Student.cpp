#include "Student.h"
#include "qdebug.h"
#include <iostream>
Student::Student(QObject* parent)
	: QObject(parent)
{}

Student::~Student()
{}

void Student::eat()
{
	qDebug() << "吃饭";
}

