#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include "HashTable.h"
using namespace std;

int main()
{
	Bucket::test2();
	//Bucket::test1();
	return 0;
}
//struct MyStruct
//{
//	MyStruct()
//	{
//		cout << "构造函数" << endl;
//	}
//	int _a;
//};
//int main()
//{
//	vector<MyStruct*> v;
//	v.resize(3);
//	//v.reserve(10);
//	//MyStruct* node = new MyStruct;
//	//MyStruct* node;
//	return 0;
//}













// 本来想测试map为何不同仿函数,但是想到特可以比较  里面自带的等于和 比较
//int main()
//{
//
//	return 0;
//}

//int main()
//{
//	bit::test_hash5();
//	//bit::test_hash4();
//	return 0;
//}

//int main()
//{
//	
//	//bit::test_hash1();
//	//bit::test_hash2();
//	//bit::test_hash3();
//	bit::test_hash4();
//	return 0;
//}
//int fun(const int a)
//{
//	return a;
//}
//int main()
//{
//	/*int b = 10;*/
//	/*const int a = 10;
//	int b = a;
//	cout << b;*/
//	//cout << fun(1);
//	//bit::test_hash1();
//	//bit::test_hash2();
//	return 0;
//}