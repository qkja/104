#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdio.h>
//
////int main()
////{
////	printf("hehe\n");
////	return 0;
////}
//
////看成unsingned  int   厉害  是的
//
////int BinaryNum(int x)
////{
////	int i = 0;
////	int count = 0;
////	for (i = 0; i < 32; i++)
////	{
////		int ret = (x >> i) & 1;
////		if (1 == ret)
////			count++;
////	}
////	return count;
////}
//
//
//﻿
////void fun(int x)
////{
////	int i = 32;
////	short num[32] = { 0 };
////	if (x < 0)
////	{
////		num[0] = 1;
////		x = -x;
////	}
////
////	while (x)
////	{
////		i--;
////		num[i] = x % 2;
////		x /= 2;
////	}
////
////	printf("偶数：");
////	for (i = 0; i < 32; i += 2)
////	{
////		printf("%d ", num[i]);
////	}
////
////	printf("\n奇数：");
////	for (i = 1; i < 32; i += 2)
////	{
////		printf("%d ", num[i]);
////	}
////	//0 2 4
////
////
////
////}
//
////int main()
////{
////	fun(-2147483647);
////	return 0;
////}
//
////int main()
////{
////	printf("%d\n", BinaryNum(1));
////	printf("%d\n", BinaryNum(-1));
////	return 0;
////}
////#include<stdio.h>
////
////void fun(int x)
////{
////	int i = 32;
////	short num[32] = { 0 };
////	if (x < 0)
////	{
////		num[0] = 1;
////		x = -x;
////	}
////
////	while (x)
////	{
////		i--;
////		num[i] = x % 2;
////		x /= 2;
////	}
////
////	printf("偶数：");
////	for (i = 0; i < 32; i += 2)
////	{
////		printf("%d ", num[i]);
////	}
////
////	printf("\n奇数：");
////	for (i = 1; i < 32; i += 2)
////	{
////		printf("%d ", num[i]);
////	}
////	//0 2 4
////
////
////
////}
//
//
////int main()
////{
////	fun(-1);
////	printf("He");
////	return 0;;
////}//



//#include<stdio.h>
//﻿
//void fun(int x)
//{
//	int i = 32;
//	short num[32] = { 0 };
//	if (x < 0)
//	{
//		num[0] = 1;
//		x = -x;
//	}
// 
//	while (x)
//	{
//		i--;
//		num[i] = x % 2;
//		x /= 2;
//	}
// 
//	printf("偶数：");
//	for (i = 0; i < 32; i+=2)
//	{
//		printf("%d ", num[i]);
//	}
// 
//	printf("\n奇数：");
//	for (i = 1; i < 32; i += 2)
//	{
//		printf("%d ", num[i]);
//	}
//	//0 2 4
// 
// 
// 
//}
// 
//int main()
//{
//	fun(-2147483647);
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//
//	int n = 10;
//	int ret = scanf("%d", &n);
//
//	printf("%d\n", ret);
//	/*if (1 == n % 2)
//	{
//		printf("奇数");
//	}*/
//
//	return 0;
//}


//m&1  m>>=1
//struct Per
//{
//	int age;
//
//};

#include<stdio.h>



//#include < stdio.h >
//struct S
//{
//	int a;
//	int b;
//};
//int main()
//{
//	struct S a, *p = &a;
//	a.a = 99;
//	printf("%d\n", (*p).a);
//	return 0;
//}

//struct stu
//{
//	int num;
//	char name[10];
//	int age;
//};
//
//
//void fun(struct stu *p)
//{
//	printf("%s\n", (*p).name);
//	return;
//}
//
//
//int main()
//{
//	struct stu students[3] = { { 9801, "zhang" ,20 },
//	{ 9802, "wang", 19 },
//	{ 9803, "zhao", 18 }
//	};
//	fun(students + 1);
//	return 0;
//}

//int fun(int n)
//{
//	return 2 * n - 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fun(n);
//	printf("%d", ret);
//	return 0;
//}
#include<stdio.h>

int main()
{
	int n = 20;
	printf("%d", 2 * n - 1);
	return 0;
}




