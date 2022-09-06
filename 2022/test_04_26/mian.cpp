#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//extern int a;
//int main()
//{
//	a = 10;
//	printf("%d\n", a);
//	return 0;
//}

//namespace N1
//{
//	int a;
//	int b;
//}
//namespace N1
//{
//	int a;
//	int b;
//}
//int main()
//{
//
//	return 0;
//}
//using N1::a;
//
//int main()
//{
//	a = 20;       //直接使用
//	N1::b = 10;
//	printf("%d %d", a, N1::b);
//	return 0;
//}

//namespace byte
//{
//	int a;
//	//数据组
//	namespace data
//	{
//		struct ListNode
//		{
//			int val;
//			struct ListNode* next;
//		};
//	}
//	//缓存组
//	namespace cache
//	{
//		int b;
//		struct ListNode
//		{
//			int val;
//			struct ListNode* next;
//		};
//	}
//}
//using namespace byte;
//using namespace byte::data;
//using byte::cache::b;
//int main()
//{
//	//用域作用限定符
//	byte::a = 10;
//	struct byte::cache::ListNode n1; //有没有struct都可以
//
//	//打开  byte命名空间
//	a = 10;
//	struct data::ListNode n2;  //有没有struct都可以
//
//	//打开  byte命名空间 和  data
//	struct ListNode n3;
//	
//	//使用 cache的的部分元素
//	b = 20;
//	return 0;
//}

//int main()
//{
//	std::cout << "hello word" << std::endl;
//	return 0;
//}

using namespace std;
//
//int main()
//{
//	int a = 0;
//	double d = 0.0f;
//	cin >> a;
//	cin >> d;
//	cout << "a = " <<a << '\n';
//	cout << "d = " <<d << '\n';
//	return 0;
//}
//void func(int a = 10)
//{
//	printf("a == %d\n", a);
//}
//int main()
//{
//	func();
//	func(20);
//	return 0;
//}

//typedef struct Queue
//{
//	int* elem;
//	int cap;
//	int size;
//} Queue;
//
//void QueueInit(Queue* ps, int cap = 4)
//{
//	ps->elem = (int*)malloc(sizeof(int) * cap);
//	ps->cap = cap;
//	ps->size = 0;
//}
//int main()
//{
//	Queue qu;
//	QueueInit(&qu);
//	return 0;
//}
//using namespace std;
//
//void func(int a,int b = 2, int c = 3)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	func(1);
//	cout << endl;
//	func(111);
//	cout << endl;
//
//	func(111, 222);
//	cout << endl;
//
//	func(111, 222, 333);
//	return 0;
//}
//int main()
//{
//	func();
//	cout << endl;
//	func(111);
//	cout << endl;
//
//	func(111,222);
//	cout << endl;
//
//	func(111,222,333);
//	return 0;
//}

//void func(int a, int b);
//void func(int a, int b = 20)
//{
//
//}
//int main()
//{
//	func(1);
//	return 0;
//}
//void func(int a, int b = 10);
//void func(int a, int b = 20)
//{
//	cout << a << endl;
//	cout << b << endl;
//}
//int main()
//{
//	func(1);
//	return 0;
//}
//#include "Test.h"
////
//
//void func(int a);
//void func(int a = 30) 
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	func();
//	return 0;
//}

//#include "Test.h"


void func(int a);
void func(int a = 10)
{
	cout << a << endl;
}

int main()
{
	func();
	func(11);
	return 0;
}
