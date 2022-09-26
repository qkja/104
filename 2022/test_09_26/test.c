#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>

int main()
{
	printf("char*      : %d\n", sizeof(char*));
	printf("short*     : %d\n", sizeof(short*));
	printf("int*       : %d\n", sizeof(int*));
	printf("long*      : %d\n", sizeof(long*));
	printf("long long* : %d\n", sizeof(long long*));
	printf("float*     : %d\n", sizeof(float*));
	printf("double*    : %d\n", sizeof(double*));
	return 0;
}



















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