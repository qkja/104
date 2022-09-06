#define _CRT_SECURE_NO_WARNINGS 1
#include"SLIist.h"

void test()
{
	SLTNode* plist = NULL;
	SListPrint(plist);
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
}

int main()
{
	test();
	return 0;
}