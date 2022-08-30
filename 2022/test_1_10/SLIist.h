#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SLTDataType;

struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
};

typedef struct SListNode SLTNode;

extern void SListPushBack(SLTNode** pphead, SLTDataType x);
extern void SListPrint(SLTNode* phead);