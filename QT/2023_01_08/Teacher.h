#pragma once

#include <QObject>

class Teacher : public QObject
{
	Q_OBJECT

public:
	Teacher(QObject* parent = nullptr);
	~Teacher();
signals:
	// 自定义声明,不需要实现,可以重载
	void hungury();

};
