#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

int main()
{
	MyHeap myHeap;
	InitMyHeap(&myHeap);
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		HeapPush(&myHeap, arr[i]);
	}
	//Display(&myHeap);
	/*int ret = HeapTop(&myHeap);
	printf("%d ", ret);*/

	while (!IsEmpty(&myHeap))
	{
		int ret = HeapTop(&myHeap);
		HeapPop(&myHeap);
		printf("%d ", ret);
	}

	//Display(&myHeap);

	return 0;
}