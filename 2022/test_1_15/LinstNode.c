#define _CRT_SECURE_NO_WARNINGS 1

#include"ListNode.h"

//初始化

DSTLNode* InitNode2(DSTLNode* head)
{
	head = ByListNode(0);
	head->next = head;
	head->prev = head;
	return head;
}

void InitNode(DSTLNode** pphead)
{
	/*head->next = NULL;
	head->prev = NULL;*/
	/**pphead = ByListNode(0);
	*pphead->next = *pphead;
	*pphead->prev = *pphead;*/
	*pphead = ByListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}

void ListDestory(DSTLNode* head)
{

}

DSTLNode* ByListNode(TypeData x)
{
	DSTLNode* cur = (DSTLNode*)malloc(sizeof(DSTLNode));
	if (cur != NULL)
	{
		cur->data = x;
		cur->next = NULL;
		cur->prev = NULL;
	}
	return cur;
}

void PushBackNode(DSTLNode* head, TypeData x)
{
	DSTLNode* newnode = ByListNode(x);
	head->prev->next = newnode;
	newnode->prev = head->prev;
	newnode->next = head;
	head->prev = newnode;
}

void display(DSTLNode* head)
{
	//DSTLNode* cur = head;
	/*if (head->next == head)
	{
		printf("空节点\n");
		return;
	}*/
	DSTLNode* cur = head->next;
	while (cur!= head)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//头插

void PushFirst(DSTLNode* head, TypeData x)
{
	DSTLNode* newnode = ByListNode(x);
	newnode->next = head->next;
	newnode->prev = head;
	head->next = newnode;
}

void PopFront(DSTLNode* head)
{
	DSTLNode* first = head->next;
	head->next->next->prev = head;
	head->next = head->next->next;
	/*free(first);
	first = NULL;*/
	if (first != head)
	{
		free(first);
		first = NULL;
	}
}

void PopBack(DSTLNode* head)
{
	assert(head);
	assert(head->next!=head);
	DSTLNode* tail = head->prev;
	DSTLNode* second = tail->prev;
	second->next = head;
	head->prev = second;
	/*free(tail);
	tail = NULL;*/
}