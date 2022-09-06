#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEAPTYPE  <      //  < 小堆   > 大堆

typedef int HPDataTytpe;

struct Heap
{
	HPDataTytpe* elem;
	size_t szie;
	size_t capacity;
};

typedef struct Heap Heap;

//初始化  堆
void HeapInit(Heap* php);

//销毁 堆
void HeapDestroy(Heap* php);

//数据入堆
void HeapPush(Heap* php, HPDataTytpe val);

//数据出队
void HeapPop(Heap* php);

//判断堆是不是 空
bool HeapEmpty(Heap* php);

//向上调整 
void adjustUp(HPDataTytpe* elem, int size);

//向下调整
void adjustDown(HPDataTytpe* elem, int size,size_t root);


HPDataTytpe HeapPeek(Heap* php);
//
void HeapSort(int* arr, int len);