#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
//
//void f()
//{
//
//}
void f()
{
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
	cout << "hello" << endl;
}


























//int main()
//{
//	int a = 10;
//	语法没有开辟空间  底层开辟了
//	int& b = a;
//	b = 20;
//
//	语法开辟空间  底层也开辟了
//	int* pa = &a;
//	*pa = 20;
//	return 0;
//}

//inline void swap(int& x, int& y)
//{
//	int ret = x;
//	x = y;
//	y = ret;
//}
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	swap(a,b);
//	cout << "a: " << a << endl;
//	cout << "b: " << b << endl;
//	return 0;
//}

//int& func()
//{
//	int n = 1;
//	n++;
//	return n;
//}
//
//int main()
//{
//	int& ret = func();
//	printf("这是一条华丽的分割线\n");
//	cout << ret << endl;
//	cout << ret << endl;
//	return 0;
//}


//int& func()
//{
//	static int n = 1;
//	n++;
//	cout << &n << endl;
//	return n;
//}
//
//int main()
//{
//	int& ret = func();
//	cout << &ret << endl;
//	return 0;
//}

//int& func()
//{
//	static int n = 1;
//	n++;
//	cout << &n << endl;
//	return n;
//}

//int func()
//{
//	int n = 1;
//	n++;
//	return n;
//}
//
//int main()
//{
//	int& ret = func();
//	return 0;
//}














//#include <stdio.h>
//二分查找
//int search(int* nums, int numsSize, int target) {
//    if (nums == NULL)
//    {
//        return -1;
//    }
//    //二分查找
//    int left = 0;
//    int right = numsSize - 1;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (nums[mid] == target)
//        {
//            return mid;
//        }
//        else if (nums[mid] < target)
//        {
//            left = mid + 1;
//        }
//        else
//        {
//            right = mid - 1;
//        }
//    }
//    return -1;
//}
//
//int main()
//{
//    int nums[] = { -1, 0, 3, 5, 9, 12 };
//    int sz = sizeof(nums) / sizeof(nums[0]);
//    int target = 9;
//   9 search(nums, sz, target);
//    return 0;
//}









//typedef struct A 
//{
//	int arr[10000];
//} A;
//
//void func1(A a)
//{
//
//}
//
//void func2(A& a)
//{
//
//}
//
//void TestRefAndValue()
//{
//	A a;
//
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		func1(a);
//	size_t end1 = clock();
//
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		func2(a);
//	size_t end2 = clock();
//
//	// 分别计算两个函数运行结束后的时间
//	cout << "func1(A)-time:" << end1 - begin1 << endl;
//	cout << "func2(A&)-time:" << end2 - begin2 << endl;
//}

//int main()
//{
//	TestRefAndValue();
//	return 0;
//}




//void func(int& a)
//{
//
//}
//
//int main()
//{
//	int a = 10;
//	double b = 10.2;
//
//	func(a);     
//	func(10);
//	func(b);
//	return 0;
//}


//int main()
//{
//	double d = 1.2;
//
//	const int& a = d;
//	cout << a << endl;
//	return 0;
//}

//int main()
//{
//	const int& a = 10;
//	
//	return 0;
//}

//int main()
//{
//    int a = 10;
//	const int& b = a;
//	return 0;
//}
//int main()
//{
//	const int a = 10;   
//	const int& c = a;  
//
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	int& b = a;        //报错
//	const int& c = a;  // 不报错
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;
//	int c = 20;
//	// 这个一定是赋值
//	b = c;
//	cout << "a: " << a << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;  //b 是  a  的别名
//	int& c = b;  //还可以对c取别名
//
//	c = 20;
//
//	cout << "a: " << a << endl;
//	cout << "b: " << a << endl;
//	cout << "c: " << a << endl;
//	return 0;
//}