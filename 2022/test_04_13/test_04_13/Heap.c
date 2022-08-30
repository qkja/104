#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void HeapInit(Heap* php)
{
	assert(php);
	php->elem = NULL;
	php->capacity = 0;
	php->szie = 0;
}

void swap(HPDataTytpe* pa, HPDataTytpe*pb)
{
	assert(pa&&pb);
	HPDataTytpe ret = *pa;
	*pa = *pb;
	*pb = ret;
}

void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->elem);
	php->elem = NULL;
	php->capacity = 0;
	php->szie = 0;
}

void adjustUp(HPDataTytpe* elem, int size)
{
	assert(elem);
	int child = size - 1;
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (elem[child] HEAPTYPE elem[parent])
		{
			swap(&elem[child], &elem[parent]);
		} 
		else
		{
			break;
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}

void HeapPush(Heap* php, HPDataTytpe val)
{
	assert(php);
	if (php->capacity == php->szie)
	{
		size_t newSize = (php->capacity == 0) ? 4 : 2 * (php->capacity);
		HPDataTytpe* pCur = (HPDataTytpe*)realloc(php->elem, sizeof(HPDataTytpe)*newSize);
		assert(pCur);
		php->elem = pCur;
		php->capacity = newSize;
	}

	php->elem[php->szie++] = val;
	adjustUp(php->elem, php->szie);
}

bool HeapEmpty(Heap* php)
{
	assert(php);
	return php->szie == 0;
}

HPDataTytpe HeapPeek(Heap* php)
{
	assert(php);
	if (HeapEmpty(php))
	{
		return -1;
	}
	return php->elem[0];
}

void HeapPop(Heap* php)
{
	assert(php);
	if (HeapEmpty(php))
	{
		return;
	}
	//交换 堆顶  和  堆 尾
	swap(&(php->elem[0]), &(php->elem[php->szie - 1]));
	php->szie--;
	//向下调整
	adjustDown(php->elem, php->szie, 0);

}

void adjustDown(HPDataTytpe* elem, int size,size_t root)
{
	assert(elem);
	int parent = root;
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && elem[child + 1] HEAPTYPE elem[child])
		{
			child++;
		}
		if (elem[child] HEAPTYPE elem[parent])
		{
			swap(&elem[child], &elem[parent]);
		}
		else
		{
			break;
		}
		parent = child;
		child = 2 * parent + 1;
	}
}

//数组 建堆

void HeapSort(int* arr,int len)
{
	assert(arr);
	for (int parent = (len - 1 - 1) / 2; parent >= 0; parent--)
	{
		//叶子不需要 调
		adjustDown(arr, len, parent);
	}
	//堆排序
	for (int i = len; i > 0;)
	{
		//交换
		int ret = arr[0];
		arr[0] = arr[i - 1];
		arr[i - 1] = ret;
		i--;
		adjustDown(arr, i, 0);
	}

}

//void HeapSort(int* arr, int len)
//{
//	assert(arr);
//	//建堆
//	for (int i = 1; i < len; i++)
//	{
//		adjustUp(arr, i+1);
//	}
//
//
//	//堆排序
//	for (int i = len; i > 0;)
//	{
//		//交换
//		int ret = arr[0];
//		arr[0] = arr[i - 1];
//		arr[i - 1] = ret;
//		i--;
//		adjustDown(arr, i, 0);
//	}
//}
