#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

//向上调整 
static void swap(int* pa, int *pb)
{
	assert(pa);
	assert(pb);
	int ret = *pa;
	*pa = *pb;
	*pb = ret;
}

void adjustUp(HPDataTytpe* elem, int size)
{
	assert(elem);
	// 注意size是最后一个元素的下一个素
	int parent = (size - 2) / 2;
	int child = size - 1;
	//while(child>0)
	while (parent>=0)
	{
		if (elem[parent] >= elem[child])
			swap(&elem[parent], &elem[child]);
		else
			break;
		//if ()
		child = parent;
		parent = (child - 1) / 2;
	}
}

void HeapPush(Heap* php, HPDataTytpe val)
{
	assert(php);
	//判满 -- 这里就不简单的疯转成一个函数了
	if (php->capacity == php->szie)
	{
		size_t newSize = (php->capacity == 0) ? 4 : 2 * (php->capacity);
		HPDataTytpe* pCur = (HPDataTytpe*)realloc(php->elem, sizeof(HPDataTytpe)*newSize);
		assert(pCur);
		php->elem = pCur;
		php->capacity = newSize;
	}

	php->elem[php->szie++] = val;
	adjustUp(php->elem, php->szie); // 向上调整
}

// 初识化
void HeapInit(Heap* php)
{
	assert(php);
	php->elem = NULL;
	php->capacity = 0;
	php->szie = 0;
}

// 销毁堆
void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->elem);
	php->elem = NULL;
	php->capacity = 0;
	php->szie = 0;
}
