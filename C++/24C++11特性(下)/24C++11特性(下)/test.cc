#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <functional>
#include <string>

using std::cin; 
using std::cout;
using std::endl;
using std::function;

//int main()
//{
//	std::string str = "hello";
//	std::move(str);
//
//	return 0;
//}
//int main()
//{
//	//int a = 1;
//	//int b = 0;
//	//auto fun1 = [&](int c){b = 1; b = a + c;  };
//	//fun1(10);
//	//cout << b << endl;
//	int x = 10;
//	auto add_x = [&x] { x *= 2; return 10; };//取消参数列表的常数性
//	cout << add_x() << endl;
//	cout << x << endl;
//	return 0;
//}
//template <class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{
//	// 函数名
//	cout << useF(f, 11.11) << endl; // count:1 count:0025C140  5.555
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl; // count:1 count: 0025C144 3.70333
//	// lamber表达式
//	cout << useF([](double d) -> double
//	{ return d / 4; },
//	11.11)
//	<< endl; // count : 1 count: 0025C148 2.7775
//	return 0;
//}

//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//
//	return (f(x));
//}
//double f(double i) {
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//
//
//int main()
//{
//	// 函数名
//	function<double(double)> fn1 = f;
//	//function<double(double)> fn1 ( f); 支持
//	cout << useF(fn1, 11.11) << endl;
//
//	// 函数对象
//	function<double(double)> fn2 = Functor();
//	//function<double(double)> fn2(Functor());   //不支持，因为function<double(double)>、Functor()不是同一个类型（类型匹配匹配不上）
//	//function<double(Functor,double)> fn2=&Functor::operator();  //支持
//	//function<double(double)> fn2 = bind(&Functor::operator(), Functor(), placeholders::_1); //支持
//	cout << useF(fn2, 11.11) << endl;
//
//	// lamber表达式
//	function<double(double)> fn3([](double d)->double { return d / 4; });
//	cout << useF(fn3, 11.11) << endl;
//	return 0;
//}
template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;
	return f(x);
}
double f(double i)
{
	return i / 2;
}
struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};
int main()
{
	// 函数名
	cout << useF(f, 11.11) << endl;
	// 函数对象
	cout << useF(Functor(), 11.11) << endl;
	// lamber表达式
	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
	return 0;
}