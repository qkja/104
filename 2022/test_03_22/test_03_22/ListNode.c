#define _CRT_SECURE_NO_WARNINGS 1
#include "ListNode.h"


void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->prev;
	prev->next = pos->next;
	pos->next->prev = prev;

	free(pos);
}

void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	if (pHead == pHead->next)
	{
		return;
	}
	ListErase(pHead->next);
	/*ListNode* cur = pHead->next;
	cur->next->prev = pHead;
	pHead->next = cur->next;
	free(cur);*/
}




ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


ListNode* BuyNode(LTDataType val)
{

	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	if (cur == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	cur->data = val;
	cur->next = NULL;
	cur->prev = NULL;
	return cur;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* node = BuyNode(x);
	prev->next = node;
	node->prev = prev;
	node->next = pos;
	pos->prev = node;
}


void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->next, x);

	/*ListNode* node = BuyNode(x);
	ListNode* cur = pHead->next;
	cur->prev = node;
	node->next = cur;
	node->prev = pHead;
	pHead->next = node;*/
}


void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	if (pHead == pHead->next)
	{
		return;
	}
	ListErase(pHead->prev);
	/*ListNode* tail = pHead->prev;
	ListNode* tailPrev = tail->prev;
	free(tail);
	tailPrev->next = pHead;
	pHead->prev = tailPrev;*/
}

ListNode* ListCreate()
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	if (cur == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	cur->data = 0;
	cur->next = cur;
	cur->prev = cur;
	return cur;
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListInsert(pHead, x);
	/*ListNode* tail = pHead->prev;
	ListNode* node = BuyNode(x);
	tail->next = node;
	node->prev = tail;
	node->next = pHead;
	pHead->prev = node;*/
}


void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	ListNode* curNext = cur->next;

	while (cur != pHead)
	{
		free(cur);
		cur = curNext;
		if (curNext != pHead)
		{
			curNext = curNext->next;
		}
	}

	free(pHead);

}

