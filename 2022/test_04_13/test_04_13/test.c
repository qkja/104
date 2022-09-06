#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

//int main()
//{
//	Heap heap;
//	HeapInit(&heap);
//	HeapPush(&heap, 3);
//	HeapPush(&heap, 5);
//	HeapPush(&heap, 6);
//	HeapPush(&heap, 10);
//	HeapPush(&heap, 0);
//	HeapPop(&heap);
//	for (int i = 0; i < (int)heap.szie; i++)
//	{
//		printf("%d ", heap.elem[i]);
//	}
//	HeapDestroy(&heap);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 4, 2, 7, 8, 5, 1, 0, 6 };
//	HeapSort(arr, 8);
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	//Heap heap;
//	/*HeapInit(&heap);
//	HeapPush(&heap, 8);
//	HeapPush(&heap, 1);
//	HeapPush(&heap, 2);
//	HeapPush(&heap, 3);
//	HeapPush(&heap, 3);
//	HeapPush(&heap, 0);
//	HeapPop(&heap);
//	for (int i = 0; i < (int)heap.szie; i++)
//	{
//		printf("%d ", heap.elem[i]);
//	}*/
//	return 0;
//}
int* TopK(int* arr, int len, int k)
{
	assert(arr);
	int* p = (int*)malloc(sizeof(int)*k);
	assert(p);

	Heap heap;
	HeapInit(&heap);
	for (int i = 0; i < k; i++)
	{
		HeapPush(&heap, arr[i]);
	}
	for (int i = k; i < len; i++)
	{
		int ret = HeapPeek(&heap);
		if (arr[i] > ret)
		{
			HeapPop(&heap);
			HeapPush(&heap, arr[i]);
		}
	}
	int i = 0;
	while (!HeapEmpty(&heap))
	{

		p[i++] = HeapPeek(&heap);
		HeapPop(&heap);

	}
	HeapDestroy(&heap);
	return p;
}
int main()
{
	int arr[] = { 3, 4, 2, 6, 12, 5, 6, 7, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	int* pa = TopK(arr, sz,k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", pa[i]);
	}
	//int sz = sizeof(arr) / sizeof(arr[0]);
	////HeapSort(arr, sz);
	//for (int i = 0; i < sz; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	return 0;
}