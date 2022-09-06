#define _CRT_SECURE_NO_WARNINGS 1
#include "ListNode.h"

void test1()
{
	ListNode* pHead = NULL;
	pHead = ListCreate();
	//ListDestory(pHead);
	
	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPopBack(pHead);
	//ListPopBack(pHead);
	//ListPopBack(pHead);
	/*ListPopFront(pHead);
	ListPopFront(pHead);
	ListPopFront(pHead);*/

	//ListPopFront(pHead);
	//ListPushFront(pHead, 0);

	//ListNode* ret = ListFind(pHead, 3);
	//if (ret != NULL)
	//{
	//	ListErase(ret);
	//	//printf("11111\n");
	//}
	//else
	//{
	//	printf("0000\n");
	//}


	//ListPopFront(pHead);
	//ListPopFront(pHead);

	//ListPopFront(pHead);

	/*ListPushFront(pHead, 0);
	ListPushFront(pHead, -1);
	ListPushFront(pHead, -2);*/
	/*ListPopBack(pHead);
	ListPopBack(pHead);
	ListPopBack(pHead);*/
	ListPrint(pHead);
}

int main()
{
	test1();
	system("pause");
	return 0;
}