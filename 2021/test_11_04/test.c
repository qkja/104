#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
//
//int main()
//{
//	return 0;
//}
////我不用
//#include<stdio.h>

#include<stdio.h>

//int main()
//{
//	int count = 0;
//
//	for (int i = 1; i < 100; i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if (i / 10 == 9)
//			count++;
//	}
//
//	printf("%d\n", count);
//	return 0;
//}


//int main()
//{
//	int flg = 1;
//	double sum = 0.0;
//
//	for (int i = 1; i <= 100; i++)
//	{
//		sum = sum + flg*(1.0 / i);
//		flg = -flg;
//	}
//	
//	printf("%lf", sum);
//	return 0;
//}

//int fun()
//{
//	return;
//}

//int main()
//{
//	/*int c = fun();
//	printf("%d\n", c);
//	int a = 0;
//	int b = 0;
//	printf(" %p\n", &a);
//	printf(" %p\n", &b);*/
//	return 0;
//}

//
//int main()
//{
//	int a[][3] = { {0,,2},{},{3,4,5} };
//	return 0'
//}

#include<stdio.h>

//初始化为0
void Init(int arr[], int x)
{
	for (int i = 0; i < x; i++)
	{
		arr[i] = 0;
    }
}

//打印
void Print(const int arr[], int x)
{
	for (int i = 0; i < x; i++)
	{
		printf("%d ", arr[i]);
	}
}

//逆置
void Reverse(int arr[], int x)
{
	int left = 0;
	int right = x - 1;
	int temp = 0;
	while (left<right)
	{
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}

int main()
{
	int arr[10];
	int sz = sizeof(arr) / sizeof(arr[0]);

	Init(arr, sz);
	Print(arr,sz);
	
	Reverse(arr, sz);
	printf("\n");
	Print(arr, sz);

	return 0;
}

//int main()
//{
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 ,-1,-2};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < sz - 1; i++)
//	{
//		int temp = 0;
//		for (int j = 0; j < sz - 1 -i ; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr1[10] = { 1,1,1,1,1,1,1,1,1,1 };
//	int arr2[10] = { 2,2,2,2,2,2,2,2,2,2 };
//
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int temp = 0;
//
//	for (int i = 0; i < sz; i++)
//	{
//		temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//
//	printf("\n");
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//
//	return 0;
//}




