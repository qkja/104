#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

ListNode* ListCreate();
ListNode* cerateNode(LTDataType x);
void ListPushFront(ListNode* plist, LTDataType x);