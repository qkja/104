#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>

int DigitSum(int n)
{
	if (n < 10)
		return n;
	return DigitSum(n / 10) + n % 10;
}

//递归方式实现打印一个整数的每一位
void printR(int n)
{
	if (n >= 10)
	{
		printR(n/10);
	}
	else
	{
		printf("%d", n);
	}

}
int main()
{
	printR(10);
	//printf("%d", printR(10));
	return 0;
}


//递归实现n的k次方
//int powerOfKChild(int n, int k)
//{
//	if (k == 0)
//		return 1;
//	return n * powerOfKChild(n, k - 1);
//}
//double powerOfK(int n, int k)
//{
//	if (k >= 0)
//	{
//		return powerOfKChild(n, k);
//	}
//	else
//	{
//		return 1.0/powerOfKChild(n, -k);
//	}
//}

//int main()
//{
//	printf("%lf", powerOfK(2, -2));
//	return 0;
//}


//int FibR(int n)
//{
//	if (n < 3)
//		return 1;
//	return FibR(n - 1) + FibR(n - 2);
//}
//int Fib(int n)
//{
//	if (n < 3)
//		return 1;
//	int left = 1;
//	int right = 1;
//	int sum = 0;
//	for (int i = 3; i <= n; i++)
//	{
//		sum = left + right;
//		left = right;
//		right = sum;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Fib(n));
//	printf("%d\n", FibR(n));
//	return 0;
//}