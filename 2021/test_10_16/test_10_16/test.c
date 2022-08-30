#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

int main()
{






	/*int n = 0;
	scanf("%d", &n);
	int arr[50] = { 0 };
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int a = 0;
	scanf("%d", &a);
	int j = 0;
	int i = 0;
	for (i = 0; i<n; i++)
	{
		if (a == arr[i])
		{
			j = i;
		}
	}
	for (i = j; i<n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	for (int i = 0; i<n - 1; i++)
	{
		printf("%d ", arr[i]);
	}*/
/*

		int n = 0;
		scanf("%d", &n);
		int a = 0;
		int b = 0;
		int arr[50] = { 0 };
		for (int i = 0; i<n; i++)
		{
			scanf("%d", &arr[i]);
			if (i>0)
			{
				if (arr[i] >= arr[i - 1])
				{
					a++;
				}
				else if (arr[i]<arr[i - 1])
				{
					b++;
				}
			}
		}
		if ((a == n - 1) || (b == n - 1))
		{
			printf("sorted\n");
		}
		else
		{
			printf("unsorted\n");
		}*/
	
/*
	int n = 0;
	int sum = 0;
	int num = 0;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf("%d ", &num);
		sum += num;
	}
	printf("%d", sum);*/
		/*short n = 0;
		short m = 0;
		int sum = 0;
		int arr[10][10] = { 0 };
		scanf("%d %d", &n, &m);
		for (short i = 0; i<n; i++)
		{
			for (short j = 0; j<m; j++)
			{
				scanf("%d", &arr[i][j]);
				if (arr[i][j]>0)
				{
					sum += arr[i][j];
				}
			}
		}
		printf("%d\n", sum);*/
		
	

	//int arr[100] = { 0 };
	//int n = 0;
	//int i = 0;
	//int count = 0;
	//scanf("%d", &n);
	////5
	//// 0 1 2 3 4
	//// 0 2 3 4 5
	//for (i = 1; i<n; i++)
	//{
	//	arr[i] = i + 1;
	//}
	//for (i = 2; i<n; i++)
	//{
	//	for (int j = 2; j<arr[i]; j++)
	//	{
	//		if (arr[i] % j == 0)
	//		{
	//			arr[i] = 0;
	//		}
	//	}
	//}
	//for (int j = 1; j<n; j++)
	//{
	//	if (arr[j] != 0)
	//	{
	//		printf("%d ", arr[j]);
	//	}
	//	else
	//	{
	//		count++;
	//	}
	//}
	//printf("\n%d\n", count);
 //   int count = 0;
	//for (int i = 1; i<2020; i++)
	//{
	//	int n = i;
	//    while (n>0)
	//	{
	//		if (n % 10 == 9)
	//		{	
	//			count++;
	//			break;
	//		}
	//		n /= 10;
	//     }
	//}
	////int n = 1990;
	//
	//
	//printf("%d", count);
	/*int num = 0;
	scanf("%d", &num);
	short arr[51] = { 0 };
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &arr[i]);
	}

	int input = 0;
	scanf("%d", &input);
	int i = 1;
	while (i <= num+1)
	{
		if (arr[i]<input)
		{
			arr[i - 1] = arr[i];
		}
		if (arr[i] >= input);
		{
			arr[i - 1] = input;
			break;
		}
		i++;
	}
	for (int j = 0; j <= num; j++)
	{
		printf("%d ", arr[j]);
	}*/
	system("pause");
	return 0;
}