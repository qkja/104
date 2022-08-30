#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
//enum S
//{
//	a,
//	b,
//	c,
//	d,
//
//};


#include<stdio.h>

int main()
{
	int n = 0;
	int m = 0;
	int a = 0;
	int b = 0;
	scanf("%d %d", &n, &m);
	short arr[10][10] = { 0 };
	short max = arr[0][0];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j]>max)
			{
				a = i;
				b = j;
			}
		}

	}
	printf("%d %d", a + 1, b + 1);
/*
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int arr[100] = { 0 };
	for (int i = 0; i<n*m; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i<n*m; i++)
	{
		printf("%d ", arr[i]);
		if ((i + 1) % m == 0)
		{
			printf("\n");
		}
	}*/
	/*int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int arr[10][10] = { 0 };
	int arr1[10][10] = { 0 };
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			arr1[j][i] = arr[i][j];
		}
	}
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}*/
	system("pause");
	return 0;

}
//int main()
//{
//
//
//
//
//	
//	/*printf("%d", strlen("\050"));
//
//	printf("\a");
//	sleep(1000);
//	printf("\a");
//	printf("\a");
//	printf("\a");
//	printf("\a");
//	printf("\a");
//*/
//
//
//
//
//
//
//	/*char arr[] = "abcd";
//	printf("%s", arr);*/
//	//printf("%d", a);
//	//printf("%d", b);
//
//	//printf("%d", c);
//	//printf("%d", d);
//	//printf("%d", a);
//
//
//
//
//	//作用域
//
//	//全局变量
//    
//	//int num1 = 0;
//	//int num2 = 0;
//	////int sum = 0;
//	//scanf("%d %d", &num1, &num2);
//	//int sum = num1 + num2;
//	//printf("%d\n", sum);
//	system("pause");
//	//system("pause");
//
//	return 0;
//}


