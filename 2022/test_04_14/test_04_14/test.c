#define _CRT_SECURE_NO_WARNINGS 1
//#include "Sort.h"
//
//
////int main()
////{
////	int arr[] = { 0,1,2,3 };
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	QuickSort(arr, sz);
////	for (int i = 0; i < sz; i++)
////	{
////		printf("%d ", arr[i]);
////	}
////	system("pause");
////	return 0;
////}
//
//#define CAP 1000000
//int main()
//{
//	srand((unsigned)time(NULL));
//	int* arr1 = (int*)malloc(sizeof(4) * CAP);
//	int* arr2 = (int*)malloc(sizeof(4) * CAP);
//	assert(arr1 && arr2);
//	for (int i = 0; i < CAP; i++)
//	{
//		int n = i;
//		arr1[i] = n;
//		arr2[i] = n;
//	}
//
//	int begin1 = clock();
//	QuickSort1(arr1, CAP);
//	int end1 = clock();
//
//	int begin2 = clock();
//	QuickSort(arr2, CAP);
//	int end2 = clock();
//	printf("没有优化 %d\n", end1 - begin1);
//	printf("优化    %d\n", end2 - begin2);
//	free(arr1);
//	free(arr2);
//	system("pause");
//	return 0;
//}
//
//
//

#include "Stack.h"

int main()
{
	int arr[] = { 44,3,21,1 };
	QuickSort(arr, 4);
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
