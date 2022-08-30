#define _CRT_SECURE_NO_WARNINGS 1

//所有的局部变量都是auto

#include<stdio.h>
#include<Windows.h>

//typedef int* i_p;


//#define  i_p int*

//auto int b = 10;

//int g_a;
//int g_b = 10;

//int main()
//{
//
//	/*int n = 10;
//	int arr[n];
//*/
//
//	/*int a = 0;
//    printf("%p\n", &g_b);
//	printf("%p\n", &g_a);
//	printf("%p\n", &a);*/
//	//INT_MAX;
//
//	//float a = 9.5;
//	//printf("%d", a);
//	//float a = 10.1f;
//	//但浮点数被强制类型转换后，
//	//读取的究竟是什么？
//	/*printf("%d\n", a);
//	printf("%d\n", a);*/
//
//	//int b = (int)a;         //   9
//    // char c = (char)a;       //  9
//	//0100 0001 0001 1000 0000 0000 0000 0000
//
//	//41 18 00 00
//	//00 00 18 41
//
//	//int* p = NULL;
//	//int* a, b;
//	//i_p a, b;
//
//	/*int b = -1;
//	
//	auto int a = 10;
//	a = ~b;
//	printf("%d", a);*/
//	system("pause");
//	return 0;
//}
//void test(void)
//{
//    static int a = 10;
//}
//extern int g_val;
int main()
{

	int a = 10;
	int b = 20;
	int c = 20;
	printf("stack addr: %p\n", &a);
	printf("stack addr: %p\n", &b);
	printf("stack addr: %p\n", &c);
	//printf("%d ", g_val);
	/*test();*/
	//printf("%d", a);
	/*printf("hehehehe\n");*/
	system("pause");
	return 0;
}