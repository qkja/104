#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef int TypeData;

struct Stack
{
	TypeData* elem; //数组
	int capacity;   //数组的容量
	int tail;       //栈顶
};

typedef struct Stack Stack;

//初始化
extern void InitStack(Stack* ps);

//push
extern void push(Stack* ps, TypeData val);

extern TypeData pop(Stack* ps);

extern TypeData peek(Stack* ps);

extern bool IsEmpty(Stack* ps);

extern void DestroyStack(Stack* ps);

extern int size(Stack* ps);



