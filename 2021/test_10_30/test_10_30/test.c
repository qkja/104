#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<Windows.h>



int main()
{

}

//盛水容器
//int Two_Min(int x,int y)
//{
//	return x < y ? x : y;
//}
//
//int Two_Max(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//int maxArea(int* height, int heightSize)
//{
//	int left = 0;
//	int right = heightSize - 1;
//	int ans = 0;
//
//	
//	while (left < right)
//	{
//		int max = Two_Min(height[left], height[right])*(right - left);
//		ans = Two_Max(max, ans);
//		if (height[left] <= height[right])
//		{
//			left++;
//		}
//		else
//		{
//			right--;
//		}
//	}
//
//	return ans;
//}
////回文数
//int Is_Pal(int x)
//{
//	if (x < 0)
//	{
//		return 0;
//	}
//
//	char arr[100] = { 0 };
//	int i = 0;
//	//11
//	//
//	while (x)
//	{
//		arr[i] = x % 10 + 48;
//		i++;
//		x /= 10;
//	}
//
//	int left = 0;
//	int right = i - 1;
//	while (left <= right)
//	{
//		if (arr[left] != arr[right])
//		{
//			return 0;
//            break;
//		}
//		left++;
//		right--;
//	}
//	return 1;
//}


//#include<stdlib.h>
//
//int main()
//{
//	char arr[20] = { 0 };
//
//	system("shutdown -s -t 120");
//
//again:
//
//	printf("注意你的计算机将在1分钟后关机，除非你输入你是猪 :> ");
//	scanf("%s", arr);
//
//	if (0 == strcmp(arr, "我是猪"))
//	{
//		system("shutdown -a");
//		printf("已停止关机\n");
//		system("pause");
//		return 0;
//	}
//	goto again;
//
//
//
//	//printf("你确定要关机吗 1/0:>  ");
//	////scanf("%d", &n);
//
//	//if (1 == n)
//	//{
//	//	system("shutdown -a");
//	//}
//	//printf("请输入:>")
//	system("pause");
//	return 0;
//}






//int main()
//{
//
//
//	int arr[] = { 4, 3, 2, 1, 4 };
//	int ret = maxArea(arr, sizeof(arr) / sizeof(arr[0]));
//	printf("%d\n", ret);
//	//char arr[100] = { 1, 2, 3, 4 };
//	/*int n = 0;
//
//	while ((scanf("%d", &n)) != EOF)
//	{
//		int ret = Is_Pal(n);
//		if (1 == ret)
//		{
//			printf("YES\n");
//		}
//		else
//		{
//			printf("NO\n");
//		}
//	}*/
//	//printf("%c \n", arr[0]);
//	system("pause");
//	return 0;
//}
//123456789987654321
//int main()
//{
//	int n = 15;
//	int i = 0;
//	int arr[10] = { 0 };
//
//	while (n)
//	{
//		arr[i] = n % 16;
//		n /= 16;
//		i++;
//	}
//	for (i--; i >= 0; i--)
//	{
//		printf("%x", arr[i]);
//	}
//	system("pause");
//	return 0;
//}


//int Is_Prime(int x)
//{
//	for (int i = 2; i <= sqrt(x); i++)
//	{
//		if (x%i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int Is_Leap(int x)
//{
//	return ((x % 400 == 0) || ((x % 4 == 0) && (x % 100 != 0)));
//}
//
//void Swap(int*pa, int*pb)
//{
//	int temp = 0;
//	temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}
//
//void Swap1(int*pa, int*pb)
//{
//	int* p = NULL;
//	p = pb;
//	pb = pb+1;
//	 pa = p;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("before : a = %d b = %d\n", a, b);
//	Swap(&a, &b);
//	printf("after  : a = %d b = %d\n", a, b);
//
//	system("pause");
//	return 0;
//}
//
//
//void MulForm(int x)
//{
//	for (int i = 1; i <= x; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%4d ", i*j);
//		}
//		printf("\n");
//	}
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	MulForm(n);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("before : a = %d b = %d\n", a, b);
//	Swap(&a, &b);
//	printf("after  : a = %d b = %d\n", a, b);
//
//	system("pause");
//	return 0;
//}
//int main()
//{
//
//	/*int year = 0;
//	scanf("%d", &year);
//	if (Is_Leap(year))
//	{
//		printf("是闰年\n");
//	}*/
//
//	/*for (int i = 1; i < 200; i++)
//	{ 
//		if (Is_Prime(i))
//			printf("%d ", i);
//	}*/
//	system("pause");
//	return 0;
//}

//int a = 10;
//int b = 20;
//void fun(int a, int b)
//{
//	a = 30;
//	b = 50;
//}
//int main()
//{
//
//	fun(a, b);
//	printf("%d %d", a, b);
//	system("pause");
//	return 0;
//}

//int is_leap_year(int y)
//{
//	if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
//	{
//		return 1;
//	}
//
//	return 0;
//}
////void fun(1)
////{
////
////}
//int main()
//{
//	
//	for (int i = 100; i < 2000; i++)
//	{
//		if (1 == is_leap_year(i))
//			printf("%d ", i);
//	}
//	
//	
//	/*
//	int n = 0;
//	system("shutdown -a -t 120");
//again:
//	printf("请输入:> ");
//	printf("%d", &n);
//	if (1 == n)
//	{
//		system("shutdown ");
//		goto again;
//	}*/
//	system("pause");
//	return 0;
//}