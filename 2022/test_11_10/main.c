#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int g_key = 20;        //全局变量
double g_val = 10.00;

int main()
{

	printf("%d\n", g_key);
	printf("%d\n", g_val);
	return 0;
}

//int main()
//{
//	int a = 10;
//	{
//		int x = 20;
//		printf("x = %d\n", x);
//	}
//	printf("x = %d\n", x);
//
//	return 0;
//}

//int main()
//{
//	printf("我是C语言的初学者");
//
//	return 0;
//}

//void main()
//{
//
//}