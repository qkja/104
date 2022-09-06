#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};

//重置节点
void init(struct Node* node)
{
	node->data = 0;
	node->next = NULL;
}

//头插

void addFirst()
{
	;
}

//尾插

//反转列表
struct Node* ReverseList(struct Node* pHead) 
{
	// write code here
	//第一步 ： 判断野指针
	if (pHead == NULL)
	{
		printf("是空节点\n");
		return NULL;
	}
	struct Node* cur = pHead->next;
	struct Node* helper = NULL;
	pHead->next = NULL;
	while (cur != NULL)
	{
		helper = cur->next;
		cur->next = pHead;
		pHead = cur;
		cur = helper;
	}
	return pHead;
}

//打印单链表
void display(struct Node* pHead)
{
	if (pHead == NULL)
	{
		printf("是空节点\n");
		return;
	}
	struct Node* cur = pHead;

	while (cur->next != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

//得到链表的长度
int listSize(struct Node* node)
{
	int count = 0;
	if (node == NULL)
	{
		return count;
	}
	struct Node* cur = node;
	while (cur!= NULL)
	{
		cur = cur->next;
		count++;
	}
	return count;
}

//反向打印链表
int* printListFromTailToHead(struct Node* listNode, int* returnSize) {
	// write code here

	int count = listSize(listNode);
	if (0 == count)
	{
		return NULL;
	}
	struct Node* cur = listNode;
	//count = listSize(listNode);
	int* p = (int*)malloc(count * sizeof(int));
	ReverseList(listNode);
	for (int i = 0; i < count; i++)
	{
		p[i] = cur->data;
		cur = cur->next;
	}
	ReverseList(listNode);
	*returnSize = count;
	return p;
}

//合并两个排序的链表

struct Node* Merge(struct Node* pHead1, struct Node* pHead2) {
	// write code here
	if (pHead1 == NULL || pHead2 == NULL)
	{
		if (pHead1 == NULL && pHead2 == NULL)
		{
			return NULL;
		}
		if (pHead1 == NULL)
		{
			return pHead2;
		}
		if (pHead2 == NULL)
		{
			return pHead1;
		}
	}
	struct Node* newHead = NULL;
	struct Node* cur = newHead;
	while (pHead1 != NULL && pHead2 != NULL)
	{
		if (pHead1->data < pHead2->data)
		{
			cur->next = pHead1;
			cur = cur->next;
			pHead1 = pHead1->next;
		}
		else
		{
			cur->next = pHead1;
			cur = cur->next;
			pHead2 = pHead2->next;
		}
		//cur->next = NULL;
	}
	if (pHead1 == NULL)
	{
		cur->next = pHead2;
	}
	if (pHead2 == NULL)
	{
		cur->next = pHead1;
	}
	return newHead->next;
}