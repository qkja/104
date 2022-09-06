#define _CRT_SECURE_NO_WARNINGS 1

#include "SListNode.h"

void test1()
{
	//不要头节点
	SListNode* pHead = NULL;
	SListPrint(pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPrint(pHead);
}

void test2()
{
	SListNode* pHead = NULL;
	SListPushFront(&pHead, 0);
	SListPushFront(&pHead, -1);

	SListPushBack(&pHead, 1);
	SListPrint(pHead);
}
void test3()
{
	SListNode* pHead = NULL;
	SListPushBack(&pHead, 1);
	//SListPushBack(&pHead, 2);
	SListPopBack(&pHead);
	SListPushBack(&pHead, 1);
	SListPrint(pHead);
}

void test4()
{
	SListNode* pHead = NULL;
	SListPushBack(&pHead, 1);
	/*SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);*/
	SListPopFront(&pHead);
	SListPrint(pHead);
}
void test5()
{
	SListNode* pHead = NULL;
	SListPushBack(&pHead, 0);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListNode* ret = SListFind(pHead,3);
	if (ret != NULL)
	{
		printf("%d\n", ret->data);
	}
}

void test6()
{
	SListNode* pHead = NULL;
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPrint(pHead);
	SListInsertAfter(SListFind(pHead, 1),4);
	SListPrint(pHead);
}

void test7()
{
	SListNode* pHead = NULL;
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListEraseAfter(SListFind(pHead, 1));
	SListPrint(pHead);
	SListDestory(pHead);
}

//int main()
//{
//	test7();
//	/*test4();*/
//	//test3();
//	//test2();
//	//test1();
//	system("pause");
//	return 0;
//}


struct ListNode 
{
	int val;
    struct ListNode * next;
};


struct ListNode* removeElements(struct ListNode* head, int val)
{
	assert(head);
	struct ListNode* prev = head;
	struct ListNode* cur = head -> next;
	while (cur != NULL) 
	{
		if (cur->val != val) 
		{
			prev = cur;
			cur = cur->next;
		}
		else 
		{
			prev->next = cur->next;
			cur = cur->next;
		}
	}

	//while (cur != NULL)
	//{


	//	/*while (cur!=NULL && cur->val == val)
	//	{
	//		cur = cur->next;
	//	}
	//	prev->next = cur;
	//	prev = cur;
	//	if (cur != NULL)
	//	{
	//		cur = cur->next;
	//	}*/
	//}

	if (head->val == val)
	{
		head = head->next;
	}
	return head;
}

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* prev = head->next;
	struct ListNode* cur = head->next;
	head->next = NULL;
	while (cur != NULL)
	{
		cur = cur->next;
		prev->next = head;
		head = prev;
		prev = cur;
	}

	return head;
}

struct ListNode* middleNode(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL&&fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}