#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"   

void TestInsert()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);

	SeqListErase(&s, 0);
	SeqListPrint(&s);

	SeqListErase(&s, 1);
	SeqListPrint(&s);

	SeqListErase(&s, 1);
	SeqListPrint(&s);


}
int main()
{
	TestInsert();
	//TestPopFront();
	//TestPopBack();
	return 0;
}













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


//void TestPuskBack()
//{
//
//	SeqList s;
//	SeqListInit(&s);
//	SeqListPushBack(&s, 1);
//	SeqListPushBack(&s, 2);
//	SeqListPrint(&s);
//}
//
//void TestPopBack()
//{
//	SeqList s;
//	SeqListInit(&s);
//
//	SeqListPushBack(&s, 1);
//	SeqListPushBack(&s, 2);
//	SeqListPushBack(&s, 3);
//	SeqListPushBack(&s, 4);
//
//	SeqListPrint(&s);
//	SeqListPopBack(&s);
//	printf("===============\n");
//
//	SeqListPrint(&s);
//}

//void TestPushFront()
//{
//	SeqList s;
//	SeqListInit(&s);
//
//	SeqListPushBack(&s, 1);
//	SeqListPushBack(&s, 2);
//	SeqListPrint(&s);
//	SeqListPushFront(&s, 0);
//	SeqListPrint(&s);
//}

//void TestPushFront()
//{
//	SeqList s;
//	SeqListInit(&s);
//	SeqListPushFront(&s, 0);
//	SeqListPrint(&s);
//}

//void TestPopFront()
//{
//	SeqList s;
//	SeqListInit(&s);
//	SeqListPushBack(&s, 1);
//	SeqListPushBack(&s, 2);
//	SeqListPushBack(&s, 3);
//	SeqListPushBack(&s, 4);
//	for (int i = 0; i < 4; i++)
//	{
//		SeqListPopFront(&s);
//		SeqListPrint(&s);
//	}
//}

//void TestInsert()
//{
//	SeqList s;
//	SeqListInit(&s);
//	SeqListPushBack(&s, 1);
//	SeqListPushBack(&s, 2);
//	SeqListPushBack(&s, 3);
//	SeqListPrint(&s);
//	printf("---------------\n");
//	SeqListInsert(&s, 3, 4); // 尾插
//	SeqListPrint(&s);
//
//	SeqListInsert(&s, 0, 0); // 头插
//	SeqListPrint(&s);
//	SeqListInsert(&s, 2, -1);// 中间插入
//	SeqListPrint(&s);
//
//
//}


//int main()
//{
//	TestInsert();
//	//TestPopFront();
//	//TestPopBack();
//	return 0;
//}

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