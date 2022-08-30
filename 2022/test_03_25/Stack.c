#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

TypeData pop(Stack* ps)
{
	assert(ps);
	if (IsEmpty(ps))
	{
		printf("已经空了\n");
		return 0;
	}
	return ps->elem[--(ps->tail)];
}

TypeData peek(Stack* ps)
{
	assert(ps);
	if (IsEmpty(ps))
	{
		printf("已经空了\n");
		return 0;
	}
	return ps->elem[ps->tail - 1];
}

int size(Stack* ps)
{
	assert(ps);
	return ps->tail;
}

void InitStack(Stack* ps)
{
	assert(ps);
	ps->elem = NULL;
	ps->capacity = 0;
	ps->tail = 0;
}

void DestroyStack(Stack* ps)
{
	assert(ps);
	free(ps->elem);
	ps->elem = NULL;
	ps->capacity = 0;
	ps->tail = 0;
}

bool isFull(Stack* ps) 
{
	assert(ps);
	return ps->capacity == ps->tail;
}

void push(Stack* ps, TypeData val)
{
	assert(ps);
	if (isFull(ps))
	{
		TypeData* newElem = (TypeData*)realloc(ps->elem, (ps->capacity + 3)*sizeof(TypeData));
		if (newElem == NULL)
		{
			printf("%s\n", strerror(errno));
		}
		ps->elem = newElem;
		ps->capacity += 3;
	}
	ps->elem[ps->tail++] = val;
}

bool IsEmpty(Stack* ps)
{
	assert(ps);
	return ps->tail == 0;
}