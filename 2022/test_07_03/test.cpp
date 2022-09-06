#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using std::cout;
using std::endl;

template<class K,class V = char>
void func()
{
	cout << sizeof(K) << endl;
	cout << sizeof(V) << endl;
}

int main()
{
	func<int>();
	return 0;
}









//template<class T>
//T add(const T& left, const T& right)
//{
//	cout << "T add" << endl;
//	return left + right;
//}
//
//int main()
//{
//	add<int>(1, 2.2);
//	add(1, (int)2.2);
//
//	add((double)1, 2.2);
//	return 0;
//}


//template<class T>
//T add(T& left, T& right)
//{
//	cout << "T add" << endl;
//	return left + right;
//}
//
//int add(int& left, int& right)
//{
//	cout << "int add" << endl;
//	return left + right;
//}
//
//int main()
//{
//	int x = 1;
//	int y = 2;
//	add<int>(x,y);
//	return 0;
//}

//  函数模板 
//  模板关键字  class 或者 typename
//template<class T>
//
//int func(T a)
//{
//	return a + 10;
//}

//template<class T>
//T add(T& a, T& b)
//{
//	return a + b;
//}

//template<class T>
//T func(T n)
//{
//	return n;
//}
//
//int main()
//{
//	int ret = func<int>(10.0);
//	cout << ret << endl;
//	return 0;
//}

//int main()
//{
//	int x = 1;
//	int y = 2;
//	int ret = add(x,y);
//	cout << ret << endl;
//	return 0;
//}

//template<class T = int>
//T func(int n)
//{
//	return n;
//}
//
//int main()
//{
//	int ret = func(10);
//	cout << ret << endl;
//	return 0;
//}
//
//template<class T>
//void Swap(T& left, T& right);
//
//template<class T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}

//template<class T>
//class Student
//{
//public:
//	Student()
//	{
//
//	}
//private:
//	T* elem;
//	int cap;
//}