#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
////创建一个整形数组，完成对数组的操作
////
////实现函数init() 初始化数组为全0
////实现print()  打印数组的每个元素
////实现reverse()  函数完成数组元素的逆置
//#include <assert.h>
//void reverse(int* p, int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		int ret = *(p + left);
//		*(p + left) = *(p + right);
//		*(p + right) = ret;
//		left++;
//		right--;
//	}
//}
//
//void print(int* p, int len)
//{
//	assert(p);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//
//}
//void init(int* p, int len)
//{
//	assert(p);
//	for (int i = 0; i < len; i++)
//	{
//		*(p + i) = 0;
//	}
//}

#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
void print(int* p, int len)
{
	assert(p);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");

}
void bubbleSort(int arr[], int len)
{
	assert(arr);
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				int ret = arr[i];
				arr[i] = arr[j];
				arr[j] = ret;
			}
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		int ret = rand() % 100;
		arr[i] = ret;
	}
	print(arr, sz);

	bubbleSort(arr, sz);
	print(arr, sz);

	return 0;
}


//int main()
//{
//	int arr[3] = { 1,2,3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//
//	reverse(arr, sz);
//	print(arr, sz);
//
//	init(arr, sz);
//	print(arr, sz);
//	return 0;
//}


//int main()
//{
//	const int a = 3;
//	int* p = &a;
//	*p = 4;
//	printf("%d", a);
//	printf("%d", *p);
//	return 0;
//}

//void swapArr(int* p1, int* p2,int len)
//{
//    if (p1 == NULL || p2 == NULL)
//        return;
//    while (len--)
//    {
//        int ret = *p1;
//        *p1 = *p2;
//        *p2 = ret;
//        p1++;
//        p2++;
//    }
//}
//int main()
//{
//    int arr1[] = { 1,2,3,4,5 };
//    int arr2[] = { 6,7,8,9,10 };
//    int sz = sizeof(arr1) / sizeof(arr1[0]);
//    swapArr(arr1, arr2,sz);
//    for (int i = 0; i < sz; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < sz; i++)
//    {
//        printf("%d ", arr2[i]);
//    }
//    return 0;
//}

//int main()
//{
//    //int a[][3] = { {0,2},{},{3,4,5} };
//    /*int arr[] = { 1,2,(3,4),5 };
//    printf("%d\n", sizeof(arr));*/
//    return 0;
//}
//void reverse_string(char* string)
//{
//
//}
//
//void print(int n)
//{
//	if (n < 10)
//	{
//		printf("%d ", n);
//		return;
//	}
//	print(n / 10);
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}
//int main()
//{
//	char* p = "aaaa";
//	printf("%d\n", myStrlen(p));
//	printf("%d\n", myStrlenR(p));
//	return 0;
//}

//int myStrlenR(char* p)
//{
//	if (*p == '\0')
//		return 0;
//	return 1+ myStrlenR(++p);
//}
//
//int myStrlen(char* p)
//{
//	int count = 0;
//	while (*p++)
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char* p = "aaaa";
//	printf("%d\n", myStrlen(p));
//	printf("%d\n", myStrlenR(p));
//	return 0;
//}
