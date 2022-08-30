#define _CRT_SECURE_NO_WARNINGS 1


#include "../../Heap/Heap/heap.h"


int main()
{
	MyHeap myHeap;
	InitMyHeap(&myHeap);
	HeapPush(&myHeap, 1);
	HeapPush(&myHeap, 2);
	HeapPush(&myHeap, 3);
	Display(&myHeap);
	return 0;
}