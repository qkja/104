#define _CRT_SECURE_NO_WARNINGS 1
#include "DSTList.h"

ListNode* ListCreate()
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	assert(cur);
	cur->data = 0;
	cur->next = cur;
	cur->prev = cur;
	return cur;
}

ListNode* cerateNode(LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	assert(cur);
	cur->data = x;
	cur->next = NULL;
	cur->prev = NULL;
	return cur;
}

void ListPushFront(ListNode* plist, LTDataType x)
{
	ListNode* cur = cerateNode(x);
	cur->prev = plist;
	cur->next = plist->next;
	cur->next->prev = cur;
}

