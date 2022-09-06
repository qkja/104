#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
typedef struct
{
	int a;
}a;

void test1()
{
	Stack a = { 0 };
	Stack* stack = &a;
	peek(stack);
	/*if (IsEmpty(stack))
	{
		printf("hello,Пе");
	}*/
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	
	/*printf("%d\n", peek(stack));
	printf("%d\n", peek(stack));*/

	printf("%d\n", size(stack)); 
	printf("%d\n", pop(stack));

	printf("%d\n", size(stack));
	printf("%d\n", pop(stack));

	printf("%d\n", size(stack));
	printf("%d\n", pop(stack));

	printf("%d\n", size(stack));
	printf("%d\n", pop(stack));
	//if (!IsEmpty(stack))
	//{
	//	printf("hello,Пе");
	//}
}

int main()
{
	test1();
	return 0;
}
//MyCircularQueue* myCircularQueueCreate(int k)
//{
//	MyCircularQueue* ps = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	ps->elem = (int*)malloc(sizeof(int) * (k + 1));
//	ps->cap = k + 1;
//	ps->front = 0;
//	ps->back = 0;
//}

