#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkedList.h"

void test()
{
	SListNode* pHead = NULL;
	SListPushBack(&pHead, 0);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 3);
	SListNode* node = SListFind(pHead, 3);
	printf("%d\n", node->data);
	printf("%p\n", node);

	/*SListPopFront(&pHead);
	SListPopFront(&pHead);*/

	/*SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushFront(&pHead, -1);*/
	SListPrint(pHead);
}
void func(int* p)
{
	free(p);
}

int main()
{
	//test();
	int* a = (int*)malloc(4);
	func(a);
	*a = 10;
	printf("%d", *a);
	system("pause");
	return 0;
}