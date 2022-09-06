#define _CRT_SECURE_NO_WARNINGS 1
#include "SqlList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < (int)ps->size; i++)
	{
		printf("%d->", ps->a[i]);
	}
	printf("NULL\n");
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void IsFull(SeqList* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		SLDateType* elem = (SLDateType*)realloc(ps->a, sizeof(SLDateType)*(ps->capacity + 3));
		if (elem == NULL)
		{
			printf("relloc fail\n");
			exit(-1);
		}
		ps->a = elem;
		ps->capacity += 3;
	}
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	IsFull(ps);

	ps->a[ps->size++] = x;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	IsFull(ps);
	for (int i = (int)ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

int IsEmpty(SeqList* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		return 0;
	}
	return 1;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	if (IsEmpty(ps) == 0)
	{
		printf("¿ÕË³Ðò±í\n");
		return;
	}

	ps->size--;

	for (int i = 0; i < (int)ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (IsEmpty(ps) == 0)
	{
		printf("¿ÕË³Ðò±í\n");
		return;
	}

	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	if (IsEmpty(ps) == 0)
	{
		return -1;
	}
	for (int i = 0; i < (int)ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	assert(pos <= ps->size);

	IsFull(ps);
	for (int i = (int)ps->size; i > (int)pos; i--)
	{
		ps->a[i] = ps->a[i - 1];

	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(pos < ps->size);
	ps->size--;
	for (int i = (int)pos; i < (int)ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
}