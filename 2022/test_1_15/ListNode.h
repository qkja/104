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

//Ë«ÏòÁ´±í
struct DoubleListNode
{
	TypeData data;
	struct DoubleListNode* next;
	struct DoubleListNode* prev;
};

typedef struct ListNode STLNode;
typedef struct DoubleListNode DSTLNode;

//³õÊ¼»¯
extern void InitNode(DSTLNode** head);
extern DSTLNode* InitNode2(DSTLNode* head);

//É¾³ý
extern void ListDestory(DSTLNode* head);

extern DSTLNode* ByListNode(TypeData x);

//Î²²å
extern void PushBackNode(DSTLNode* head, TypeData x);
//´òÓ¡
extern void display(DSTLNode* head);
//Í·²å
extern void PushFirst(DSTLNode* head, TypeData x);
//Í·É¾
extern void PopFront(DSTLNode* head);
//Î²É¾
extern void PopBack(DSTLNode* head);
