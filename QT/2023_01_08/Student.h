#pragma once

#include <QObject>

class Student : public QObject
{
	Q_OBJECT

public:
	Student(QObject* parent = nullptr);
	~Student();
signals:

public slots:
	// 这是槽函数, 生命并实现,可以重在
	void eat();
};
