#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

int main()
{
	printf("------------------\n");
	Heap heap;
	printf("------------------\n");
	HeapInit(&heap);
	HeapPush(&heap, 3);
	HeapPush(&heap, 5);
	HeapPush(&heap, 6);
	HeapPush(&heap, 10);
	HeapPush(&heap, 3);

	for (int i = 0; i < (int)heap.szie; i++)
	{
		printf("%d ", heap.elem[i]);
	}
	return 0;
}