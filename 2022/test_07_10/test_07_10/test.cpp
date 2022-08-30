#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//class Date
//{
//public:
//	void Print()
//	{
//		this = nullptr;
//	}
//private:
//	int _a = 10;
//};

//int main()
//{
//	Date d;
//	d.Print();
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//
//	friend std::istream& operator>>(std::istream& in, Date& d);
//	friend std::ostream& operator<<(std::ostream& out, Date& d);
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//std::istream& operator>>(std::istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//std::ostream& operator<<(std::ostream& out, Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day;
//	return out;
//}
//
//int main()
//{
//	Date d1;
//	cin >> d1;
//	cout << d1;
//	return 0;
//}

//int main()
//{
//
//	int a;
//	int b;
//	cin >> a >> b;
//	printf("a = %d b = %d\n", a, b);
//	return 0;
//}


//int main()
//{
//	Date d1;
//	cin >> d1;
//	cout << d1;
//	return 0;
//}

//int main()
//{
//	Date d1;
//	cin >> d1;
//	return 0;
//}

//template<class T>
//struct __list_iterator
//{
//	typedef list_node<T> Node;
//	Node* _node;
//
//	__list_iterator(Node* node)
//		:_node(node)
//	{}
//	T& operator*()
//	{
//		return _node->_data;
//	}
//	// 前置 不是先++吗  这个  迭代器就是为了 记录下一个的位置
//	__list_iterator<T>& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//	// 那么  后置该如何做
//
//	__list_iterator<T> operator++(int)
//	{
//		//第一步  保存  原来的迭代器
//		//我看着玩意就 跟看天书
//		__list_iterator<T> ret(_node);
//		_node = _node->_next;
//		return ret;
//	}
//
//	bool operator!=(const __list_iterator<T>& it)
//	{
//		return _node != it._node;
//	}
//
//};

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day;
//		cout << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void func(const Date& d)
//{
//	d.Print();
//}
//
//int main()
//{
//	Date d1(2022, 7, 10);
//	func(d1);
//	return 0;
//}




//int main()
//{
//	int a = 10;
//	const int* pa = &a;
//	*pa = 20;
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	const int* pa = &a;
//	*pa = 20;
//	//cout << *pa << endl;
//	return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void func()
	{
		cout << "非const成员函数" << endl;
	}
	void Print() const
	{
		Date ret(*this);
		ret.func();
		cout << "const成员函数" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2022, 7, 10);
	d1.Print();
	return 0;
}