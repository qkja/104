#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <stdio.h>

int main()
{

	int n = 9;
	float* pFloat = (float*)&n;
	printf("n的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);
	*pFloat = 9.0;
	printf("num的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);
	return 0;
}


//int main()
//{
//
//    int i = -20;
//    unsigned  int  j = 10;
//    printf("%d\n", i + j);
//  
//    return 0;
//}





//int main()
//{
//
//    int i = -20;
//    unsigned  int  j = 10;
//    printf("%d\n", i + j);
//   /* char a = -128;
//    printf("%u\n", a);*/
//    return 0;
//}

//int main()
//{
//
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	/*int a = -1;*/
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	int arr[10] = { 0 };
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int m = 0;
//	scanf("%d", &m);
//	//int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (m == arr[i])
//		{
//			arr[i] = 0;
//			/*for (int j = i; j < n-1; j++)
//			{
//				arr[j] = arr[j + 1];
//			}
//			count++;*/
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		if(arr[i] != 0)
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	int arr1[10][10] = { 0 };
//	int arr2[10][10] = { 0 };
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf("%d", &arr1[i][j]);
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			arr2[j][i] = arr1[i][j];
//		}
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%d ",arr2[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int de = n / 12;
//    int m = de*4;
//    printf("%d", m);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int arr[100] = { 0 };
//	scanf("%d", &n);
//	int k = 0;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &k);
//		arr[k] = k;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%d ", arr[i]);
//		}
//		
//	}
//	return 0;
//}

//int main()
//{
//
//
//	float n = 9.0;
//	printf("%d", n);
//
//	/*int n = 9;
//	float* p = (float*)&n;
//	printf("%d\n", n);
//	printf("%f\n", *p);
//
//
//	*p = 9.0;
//	printf("%d\n", n);
//	printf("%f\n", *p);
//	float m = 0.0;
//	float* pm = &m;
//	*pm = 9.0;
//	printf("%d", *pm);*/
//	//printf("%lf", 2E1);
//	return 0;
//}

//int main()
//{
//	int a = -20;
//	unsigned int b = 10;
//	printf("%d", a + b);
//	//char a = 128;
//	//00000000 00000000  00000000 01111111
//	//
//	//       11111111111111111111111110000001
//	//      
//	//printf("%u", a);
//	return 0;
//}