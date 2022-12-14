#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int TypeData;

struct ListNode
{
	TypeData data;
	struct ListNode* next;
};

//˫??????
struct DoubleListNode
{
	TypeData data;
	struct DoubleListNode* next;
	struct DoubleListNode* prev;
};

typedef struct ListNode STLNode;
typedef struct DoubleListNode DSTLNode;

//??ʼ??
extern void InitNode(DSTLNode** head);
extern DSTLNode* InitNode2(DSTLNode* head);

//ɾ??
extern void ListDestory(DSTLNode* head);

extern DSTLNode* ByListNode(TypeData x);

//β??
extern void PushBackNode(DSTLNode* head, TypeData x);
//??ӡ
extern void display(DSTLNode* head);
//ͷ??
extern void PushFirst(DSTLNode* head, TypeData x);
//ͷɾ
extern void PopFront(DSTLNode* head);
//βɾ
extern void PopBack(DSTLNode* head);
