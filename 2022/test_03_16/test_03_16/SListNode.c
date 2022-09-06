#define _CRT_SECURE_NO_WARNINGS 1

#include "SListNode.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* ret = (SListNode*)malloc(sizeof(SListNode));
	if (ret == NULL)
	{
		printf("%s\n", strerror(errno));
		return NULL;
	}
	ret->data = x;
	ret->next = NULL;
	return ret;
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* ret = BuySListNode(x);
	if (ret == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}

	if (*pplist == NULL)
	{
		*pplist = ret;
		return;
	}
	SListNode* cur = *pplist;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = ret;
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

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* ret = BuySListNode(x);
	if (ret == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}

	if (*pplist == NULL)
	{
		*pplist = ret;
		return;
	}

	SListNode* cur = *pplist;

	ret->next = cur;
	*pplist = ret;
}

void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	SListNode* cur = *pplist;

	if (cur->next == NULL)
	{
		free(cur);
		*pplist = NULL;
		return;
	}
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* cur = *pplist;
	*pplist = cur->next;
	cur->next = NULL;
	free(cur);
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* ret = BuySListNode(x);
	SListNode* curHelp = pos->next;
	pos->next = ret;
	ret->next = curHelp;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	SListNode* cur = pos->next;
	pos->next = cur->next;
	cur->next = NULL;
	free(cur);
}

void SListDestory(SListNode* plist)
{
	if (plist == NULL)
	{
		return;
	}
	SListNode* cur = plist;
	while (cur != NULL)
	{
		SListNode* ret = cur;
		cur = cur->next;
		free(ret);
		ret = NULL;
	}

}