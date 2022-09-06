#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
using namespace std;
//#define PI 3.14
// 1
//int ThreeMul(int a,int b = 1,int c = 1)
//{
//	return a * b * c;
//}
//
//// 2
//#define PI 3.14
//
//double circum(int r)
//{
//	return 2 * PI * r;
//}
//
//double circum(double r)
//{
//	return 2 * PI * r;
//}
//
//int circum(int x, int y)
//{
//	return 2 * (x + y);
//}
//
//double circum(double x, int y)
//{
//	return 2 * (x + y);
//}
//
//double circum(int x, double y)
//{
//	return 2 * (x + y);
//}
//
//double circum(double x, double y)
//{
//	return 2 * (x + y);
//}
//
//#include<cassert>
//
//class address_list
//{
//public:
//	
//	void Print()
//	{
//		cout << _name << _address << _tel << endl;
//	}
//	void Set(char* name, char* address, char* tel)
//	{
//		assert(name && address && tel);
//		strcpy(_name, name);
//		strcpy(_address, address);
//		strcpy(_tel, tel);
//	}
//
//private:
//	char _name[30];
//	char _address[100];
//	char _tel[12];
//};

//class employee
//{
//public:
//	employee(int num = 0, const char* name = "-", int age = 0, double wage = 0.0)
//	{
//		this->num = num;
//		strcpy(this->name, name);
//		this->age = age;
//		this->wage = wage;
//	}
//	~employee()
//	{
//		cout << this->name << endl;
//	}
//
//	void display();
//
//private:
//	int num;
//	char name[20];
//	int age;
//	double wage;
//};

//employee::/*employee(int num = 0,const char* name = "-", int age = 0,double wage = 0.0)
//{
//	this->num = num;
//	strcpy(this->name, name);
//	this->age = age;
//	this->wage = wage;
//}*/

//employee::~employee()
//{
//}

//int main()
//{
//	address_list a[] = new address_list[3];
//	return 0;
//}


//int main()
//{
//
//	cout << circum(1) << endl;
//	cout << circum(2.0) << endl;
//
//	cout << circum(1, 2) << endl;
//	cout << circum(1.0, 2) << endl;
//	cout << circum(1, 2.0) << endl;
//	cout << circum(1.0, 2.0) << endl;
//
//	return 0;
//}

//int main()
//{
//	cout << ThreeMul(1, 2) << endl;
//	cout << ThreeMul(1, 2,2) << endl;
//	return 0;
//}


//class employee
//{
//public:
//	employee(int num = 0, const char* name = "-", int age = 0, double wage = 0.0)
//	{
//		this->num = num;
//		strcpy(this->name, name);
//		this->age = age;
//		this->wage = wage;
//	}
//	~employee()
//	{
//		cout << this->name << endl;
//	}
//
//	void display()
//	{
//		cout << this->num << " ";
//		cout << this->name << " ";
//		cout << this->age << " ";
//		cout << this->wage;
//		cout << endl;
//	}
//
//private:
//	int num;
//	char name[20];
//	int age;
//	double wage;
//};
//
//int main()
//{
//	employee e1(0, "张三", 18, 9000);
//	employee e2(1, "李四", 18, 100000);
//
//
//	e1.display();
//	e2.display();
//	return 0;
//}

//class Date
//{
//public:
//	//构造函数
//	Date(int year = 1, int month = 1, int day = 1);
//
//	~Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}
//	void Print()
//	{
//		cout << _year << "-";
//		cout << _month << "-";
//		cout << _day << endl;;
//	}
//	
//	Date& operator+=(const int day);
//	
//	Date& operator-=(const int day);
//	Date operator++(int day);
//	Date& operator++();
//
//
//private:
//	bool IsLeapYear(int year)
//	{
//		assert(year > 0);
//		if ((year % 4 == 0 && year % 100 != 0)
//			|| year % 400 == 0)
//		{
//			return true;
//		}
//		return false;
//	}
//	int MonthDays(const int year, const int month)
//	{
//		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (month == 2 && IsLeapYear(year))
//		{
//			return 29;
//		}
//		return  monthDays[month];
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//Date::Date(int year, int month, int day)
//{
//	assert(year > 0);
//	assert(month > 0 && month < 13);
//	if (day > 0 && day <= MonthDays(year, month))
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	else
//	{
//		cout << "数据不合法" << endl;
//	}
//
//}
//
//Date& Date::operator-=(const int day)
//{
//	if (day < 0)
//	{
//		return *this += (-day);
//	}
//
//	_day -= day;
//	while (_day <= 0)
//	{
//		if (_month == 1)
//		{
//			_year -= 1;
//			_month = 12;
//			_day += MonthDays(_year, _month);
//		}
//		else
//		{
//			_month -= 1;
//			_day += MonthDays(_year, _month);
//		}
//	}
//
//	return*this;
//}
//
//Date& Date::operator+=(const int day)
//{
//	//现在开始了
//	if (day < 0)
//	{
//		return *this -= (-day);
//	}
//
//	_day += day;
//
//	while (_day > MonthDays(_year, _month))
//	{
//		_day -= MonthDays(_year, _month);
//		_month += 1;
//		if (_month == 13)
//		{
//			_year += 1;
//			_month = 1;
//		}
//	}
//
//	return *this;
//}
////前置 ++
//Date& Date::operator++()
//{
//	*this += 1;
//	return *this;
//}
//
//Date Date::operator++(int day)
//{
//	Date d(*this);
//	*this += 1;
//	return d;
//}
//
//int main()
//{
//	Date d1(2022, 5, 20);
//	d1++.Print();
//	d1.Print();
//
//	(++d1).Print();
//	return 0;
//}


//建立一个宿舍楼类 Dorm_Building，用来存储宿舍楼的楼号、层数和房间数。建立派生类 room，继承
//Dorm_Building，并存储床位数与房间号。要求每个类都有构造函数和输出相关数据函数，在主函数中定义
//room 类的对象并初始化，显示相关数据。

class Dorm_Building
{
public:
	Dorm_Building(int floor = 0,int layers = 0,int rooms = 0);
	~Dorm_Building();

private:
	int _floor;
	int _layers;
	int _rooms;
};

Dorm_Building::Dorm_Building(int floor, int layers, int rooms)
{
	_floor = floor;
	_layers = layers;
	_rooms = rooms;
}

Dorm_Building::~Dorm_Building()
{
	_floor = 0;
	_layers = 0;
	_rooms = 0;
}

//class room extern Dorm_Building
//{
//public:
//	room extern Dorm_Building();
//	~room extern Dorm_Building();
//
//private:
//
//};
//
//room extern Dorm_Building::room extern Dorm_Building()
//{
//	super();
//}
//
//room extern Dorm_Building::~room extern Dorm_Building()
//{
//}
