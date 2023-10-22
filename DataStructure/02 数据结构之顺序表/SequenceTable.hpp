#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int SLDataType;
// ˳���Ķ�̬�洢
typedef struct SeqList
{
	SLDataType* array; // ָ��̬���ٵ�����
	size_t size; // ��Ч���ݸ���
	size_t capicity; // �����ռ�Ĵ�С
} SeqList;

// ������ɾ��Ľӿ�
// ˳����ʼ��
void SeqListInit(SeqList* psl, size_t capacity);
// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* psl);
// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x);
// ˳���βɾ
int SeqListEmpty(SeqList* psl);
void SeqListPopBack(SeqList* psl);
// ˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x);
// ˳���ͷɾ
void SeqListPopFront(SeqList* psl);
// ˳������
int SeqListFind(SeqList* psl, SLDataType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, size_t pos);
// ˳�������
void SeqListDestory(SeqList* psl);
// ˳����ӡ
void SeqListPrint(SeqList* psl);

//// ������ɾ��Ľӿ�
// ˳����ʼ��
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

// ���ռ䣬������ˣ���������
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
// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	if (psl == NULL)
		return;
	CheckCapacity(psl);
	psl->array[psl->size++] = x;
}

// ˳���βɾ
void SeqListPopBack(SeqList* psl)
{
	if (SeqListEmpty(psl) == 0)
		return;
	psl->size--;
}
// ˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	SeqListInsert(psl, 0, x);
}
// ˳���ͷɾ
void SeqListPopFront(SeqList* psl)
{
	SeqListErase(psl, 0);
}
// ˳������
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
// ˳�����posλ�ò���x
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
// ˳���ɾ��posλ�õ�ֵ
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
// ˳�������
void SeqListDestory(SeqList* psl)
{
	if (psl == NULL)
		return;
	psl->capicity = 0;
	psl->size = 0;
	free(psl->array);
}
// ˳����ӡ
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