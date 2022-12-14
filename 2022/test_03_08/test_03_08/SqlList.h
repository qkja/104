#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;

//??ʼ??
void SeqListInit(SeqList* ps);

//????
void SeqListDestory(SeqList* ps);

//??ӡ
void SeqListPrint(SeqList* ps);

//β??
void SeqListPushBack(SeqList* ps, SLDateType x);

//ͷ??
void SeqListPushFront(SeqList* ps, SLDateType x);

//ͷɾ
void SeqListPopFront(SeqList* ps);

//βɾ
void SeqListPopBack(SeqList* ps);

// ˳????????
int SeqListFind(SeqList* ps, SLDateType x);

// ˳??????posλ?ò???x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);

// ˳????ɾ??posλ?õ?ֵ
void SeqListErase(SeqList* ps, size_t pos);
