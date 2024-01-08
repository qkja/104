#include "Student.h"
#include "qdebug.h"
#include <iostream>
Student::Student(QObject* parent)
	: QObject(parent)
{}

Student::~Student()
{}

void Student::eat(QString food)
{
    qDebug() << "吃饭" << food;
}

void Student::eat()
{
    qDebug() << "吃饭";
}


