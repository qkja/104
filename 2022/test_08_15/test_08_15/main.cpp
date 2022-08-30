#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//bool isPrimeNumber(int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int cout = 0;
//	for (int i = 2; i <= n; i++)
//	{
//		if (isPrimeNumber(i))
//			cout++;
//	}
//	printf("%d\n", cout);
//	return 0;
//}
//int numOfDigits(int n)
//{
//	if (n == 0)
//		return 1;
//	int count = 0;
//	while (n)
//	{
//		n = n / 10;
//		++count;
//	}
//	return count;
//}
//bool isAutonomicNumber(int n)
//{
//	if (n == 0)
//		return true;
//	int ret = n * n;
//	int count = numOfDigits(n);
//	int sum = 1;
//	while (count--)
//	{
//		sum *= 10;
//	}
//	return ret %  sum == n;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int count = 0;
//	for (int i = 0; i <= n; i++)
//	{
//		if (isAutonomicNumber(i))
//		{
//			count++;
//			cout << i*i << " " << i << endl;;
//		}
//	}
//	cout << count;
//	return 0;
//}

//#include <stdio.h>
//void fun(char **p)
//{
//	int i;
//	for (i = 0; i < 4; i++)
//		printf("%s", p[i]);
//} 
//int main()
//{
//	char *s[6] = { "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX" };
//	fun(s);
//	printf("\n");
//	return 0;
//}

//int main()
//{
//	for (int i = 1; i < 10; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%-2d*%2d = %-2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int max = arr[0];
//	for (int i = 0; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	return 0;
//}
// / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 бнбн + 1 / 99 - 1 / 100 

//int main()
//{
//	double sum = 0.0;
//	int flag = 1;
//	for (int i = 1; i <= 100; i++)
//	{
//		sum = sum + flag*(1.0 / i);
//		flag = -flag;
//	}
//	printf("%lf", sum);
//	return 0;
//}

