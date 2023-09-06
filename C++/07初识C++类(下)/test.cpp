// 前置++ 赋值运算符重载直接写
// 后置++ 参数是int

// 类具有堆单个参数的构造函数具有类型转换的作用,如果不想要,可以explicit 
#include <iostream>
using namespace std;

//class Widget
//{
//public:
//	Widget()
//	{
//
//	}
//	Widget(const Widget& w)
//	{
//		cout << "Widget(const Widget& w)" << endl;
//	}
//	Widget& operator=(const Widget& w)
//	{
//		//*this = w;
//		cout << "Widget& operator=(const Widget& w)" << endl;
//		return *this;
//	}
//	~Widget()
//	{
//		cout << "~Widget()" << endl;
//	}
//
//private:
//
//};
//
//Widget f(const Widget& u)
//{
//	return u;
//}
//
//int main()
//{
//	Widget x, y;
//	// 
//	x  = f(y); // 
//	return 0;
//}