#include "heap.hpp"

int main()
{
	Heap heap;
	heap.HeapPush(3);
	heap.HeapPush(5);
	heap.HeapPush(6);
	heap.HeapPush(10);
	heap.HeapPush(0);

	int len = heap.HeapSize();
	for (int i = 0; i < len; i++)
	{

		printf("%d ", heap.HeapTop());
		heap.HeapPop();
	}
	return 0;
}