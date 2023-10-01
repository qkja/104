#include <iostream>
using namespace std;

//int main()
//{
//	cout << "hhe" << std::endl;
//
//	return 0;
//}

//template<class F, class T>
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
//	cout << useF(f, 11.11) << endl;
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber表达式
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//	return 0;
//}