#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int SLDataType;
// 顺序表的动态存储
typedef struct SeqList
{
	SLDataType* array; // 指向动态开辟的数组
	size_t size; // 有效数据个数
	size_t capicity; // 容量空间的大小
} SeqList;

// 基本增删查改接口
// 顺序表初始化
void SeqListInit(SeqList* psl, size_t capacity);
// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* psl);
// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x);
// 顺序表尾删
int SeqListEmpty(SeqList* psl);
void SeqListPopBack(SeqList* psl);
// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x);
// 顺序表头删
void SeqListPopFront(SeqList* psl);
// 顺序表查找
int SeqListFind(SeqList* psl, SLDataType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos);
// 顺序表销毁
void SeqListDestory(SeqList* psl);
// 顺序表打印
void SeqListPrint(SeqList* psl);

//// 基本增删查改接口
// 顺序表初始化
void SeqListInit(SeqList* psl, size_t capacity)
{
	if (psl == NULL)
		return;
	SLDataType* tmp = (SLDataType*)malloc(capacity * sizeof(SLDataType));
	if (tmp == NULL)
		return;
	psl->array = tmp;
	psl->capicity = capacity;
}

// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* psl)
{
	if (psl == NULL)
		return;
	if (psl->size == psl->capicity)
	{
		size_t newCap = psl->capicity == 0 ? 4 : 2 * psl->capicity;
		SLDataType* tmp = (SLDataType*)malloc(newCap * sizeof(SLDataType));
		if (tmp == NULL)
			return;
		for (int i = 0; i < psl->size; ++i)
			tmp[i] = psl->array[i];
		free(psl->array);
		psl->array = tmp;
		psl->capicity = newCap;
	}
}
int SeqListEmpty(SeqList* psl)
{
	if (psl == NULL)
		return 0;
	return psl->size > 0;
}
// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	if (psl == NULL)
		return;
	CheckCapacity(psl);
	psl->array[psl->size++] = x;
}

// 顺序表尾删
void SeqListPopBack(SeqList* psl)
{
	if (SeqListEmpty(psl) == 0)
		return;
	psl->size--;
}
// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	SeqListInsert(psl, 0, x);
}
// 顺序表头删
void SeqListPopFront(SeqList* psl)
{
	SeqListErase(psl, 0);
}
// 顺序表查找
int SeqListFind(SeqList* psl, SLDataType x)
{
	if (psl == NULL)
		return -1;
	for (int i = 0; i < psl->size; ++i)
	{
		if (x == psl->array[i])
			return i;
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	if (pos <0 || pos > psl->size)
		return;
	CheckCapacity(psl);
	int i = psl->size;
	while (i > pos)
	{
		psl->array[i] = psl->array[i - 1];
		i--;
	}
	psl->array[i] = x;
	psl->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos)
{
	if (pos <0 || pos >= psl->size)
		return;
	if(psl->size == 0)
		return;
	int i = pos;
	while (i < psl->size-1)
	{
		psl->array[i] = psl->array[i + 1];
		i++;
	}
	psl->size--;
}
// 顺序表销毁
void SeqListDestory(SeqList* psl)
{
	if (psl == NULL)
		return;
	psl->capicity = 0;
	psl->size = 0;
	free(psl->array);
}
// 顺序表打印
void SeqListPrint(SeqList* psl)
{
	if (psl == NULL)
		return;
	for (int i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}