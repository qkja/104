#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>

int main()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;
	return 0;
}
//#include<stdio.h>
//
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	for (int i = 0; i <= 10; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}


//int* func()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p;
//	p = func();
//	printf("%d \n", *p);
//	printf("%d \n", *p);
//	return 0;
//}

//int main()
//{
//	int* p;
//	printf("%d \n", *p);
//	return 0;
//}




//int myStrlen(char* p)
//{
//	if (p == NULL)
//		return 0;
//	// 记录 '\0' 的 地址
//	char* end = p;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - p;
//}

//void resreval(char arr[], int sz)
//{
//	char* left = arr;
//	char* right = arr + sz - 1;
//	while (left < right) // 这里 就是  指针的比较
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = { '1','2','3','4','5' };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	resreval(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	
//	return 0;
//}
//int main()
//{
//	char* p = "abcde";
//	printf("%d", myStrlen(p));
//	return 0;
//}

//int main()
//{
//	int a = 0x11223344;
//	int* p1 = &a;
//	*p1 = 0;
//	printf("%#x", a);
//	return 0;
//}



//#include<stdio.h>
//
//int main()
//{
//	int a = 0x11223344;
//	int* p1 = &a;
//	char* p2 = (char*)p1; // 强制类型转换
//	*p2 = 0;
//	printf("%#x", a);
//	return 0;
//}
//int main()
//{
//	printf("char*      : %d\n", sizeof(char*));
//	printf("short*     : %d\n", sizeof(short*));
//	printf("int*       : %d\n", sizeof(int*));
//	printf("long*      : %d\n", sizeof(long*));
//	printf("long long* : %d\n", sizeof(long long*));
//	printf("float*     : %d\n", sizeof(float*));
//	printf("double*    : %d\n", sizeof(double*));
//	return 0;
//}



















//void swap1(int x, int y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前：a = %d b = %d\n", a, b);
//	swap1(a, b);
//	printf("交换后：a = %d b = %d\n", a, b);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	return 0;
//}

//void swap2(int* pa, int* pb)
//{
//	int temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}