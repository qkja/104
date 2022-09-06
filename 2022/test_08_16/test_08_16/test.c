#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//#include <math.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 1; i < n+1; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%-2d*%2d = %-2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int binarySearch(int* arr,int length, int key)
//{
//	assert(arr);
//	int left = 0;
//	int right = length;
//	int mid = 0;
//	while (left < right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] == key)
//		{
//			return mid;
//		}
//		else if (arr[mid] > key)
//		{
//			right = mid;
//		}
//		else
//		{
//			left = mid + 1;
//		}
//	}
//	return -1;
//}
//int Fun(int n)
//{
//	if (n == 5)
//		return 2;
//	else
//		return 2 * Fun(n + 1);
//}
//int main()
//{
//	printf("%d", Fun(2));
//	/*int arr[11] = { 1,1,2,3,4,5,6,7,8,9,10};
//	int key = 10;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int ret = binarySearch(arr, len, key);
//	if (ret!= -1)
//	{
//		printf("找到了,下标是 %d\n",ret);
//	}
//	else
//	{
//		printf("找不到\n");
//	}*/
//	return 0;
//}





//int isHaveNine(int n)
//{
//	while (n)
//	{
//		int ret = n % 10;
//		if (ret == 9)
//		{
//			return 1;
//		}
//		n = n / 10;
//	}
//	return 0;
//}
//int main()
//{
//	int count = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		if (isHaveNine(i))
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//void swap(int* pa, int* pb)
//{
//	int ret = *pa;
//	*pa = *pb;
//	*pb = ret;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	swap(&a, &b);
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	return 0;
//}
//int isLeapYear(int year)
//{
//	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (isLeapYear(year))
//	{
//		printf("%d 是 闰年\n", year);
//	}
//	return 0;
//}
#include <stdio.h>
#include <assert.h>
#include <math.h>

int isPrimeNumber(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	for (int i = 100; i <= 200; i++)
	{
		if (isPrimeNumber(i) == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}