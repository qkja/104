#define _CRT_SECURE_NO_WARNINGS 1
#include "SqlList.h"

void test()
{
	SeqList seqList;
	SeqListInit(&seqList);
	SeqListPrint(&seqList);
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushFront(&seqList, 0);
	SeqListErase(&seqList, 4);
	SeqListPrint(&seqList);
}

int main()
{
	test();
	return 0;
}