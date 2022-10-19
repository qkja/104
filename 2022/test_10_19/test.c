#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"                                                                                                                                                                                                                                                                                                                                                   
//int main()
//{
//	SeqList s;
//	SeqListInit(&s);
//	return 0;
//}
//void f(int b)
//{
//	b = 20;
//}
//int main()
//{
//	int a = 0;
//	f(a);
//	printf("%d", a);
//	return 0;
//}
//void TestInit()
//{
//
//	SeqList s;
//	SeqListInit(&s);
//}






void TestPuskBack()
{

	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPrint(&s);
}

void TestPopBack()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);

	SeqListPrint(&s);
	SeqListPopBack(&s);
	printf("===============\n");

	SeqListPrint(&s);
}

int main()
{
	TestPopBack();
	return 0;
}

//int main()
//{
//	int arr[10] = { 0 };
//	arr[11] = 1;
//	printf("%d", arr[11]);
//	return 0;
//}

//int main()
//{
//	TestPuskBack();
//	return 0;
//}