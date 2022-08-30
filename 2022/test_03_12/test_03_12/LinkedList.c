#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkedList.h"

SListNode* BuySListNode(SLTDateType val)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* node = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = node;
		return;
	}
	SListNode* cur = *pplist;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = node;
}

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* node = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = node;
		return;
	}
	node->next = *pplist;
	*pplist = node;
}

void SListPopBack(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		printf("¿ÕÁ´±í\n");
		exit(-1);
	}

	SListNode* cur = *pplist;
	if (cur->next == NULL)
	{
		*pplist = NULL;
	}
	while (cur->next != NULL && cur->next->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = NULL;
}

void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		printf("¿ÕÁ´±í\n");
		exit(-1);
	}
	SListNode* cur = *pplist;
	*pplist = cur->next;
	cur->next = NULL;
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	if (plist == NULL)
	{
		printf("¿ÕÁ´±í\n");
		exit(-1);
	}
	SListNode* cur = plist;
	while (cur!=NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListDestory(SListNode* plist)
{
	if (plist == NULL)
	{
		return;
	}

	plist->next = NULL;

}

