#define _CRT_SECURE_NO_WARNINGS 1
#include"SLIist.h"

//void InitNode(SLTNode* ps)
//{
//	ps->data = 0;
//	ps->next = NULL;
//}

void SListPushBack(SLTNode** phead, SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;

	if (*phead == NULL)
	{
		*phead = newnode;
		return;
	}
	
	SLTNode* tail = *phead;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = newnode;
}


//void SListPushBack(SLTNode* phead)
//{
//}

//´òÓ¡
void SListPrint(SLTNode* phead)
{
	/*if (phead == NULL)
	{
		printf("¿ÕÁ´±í");
		return;
	}*/
	SLTNode* cur = phead;
	while (cur!=NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}