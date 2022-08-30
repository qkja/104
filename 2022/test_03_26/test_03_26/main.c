////#define _CRT_SECURE_NO_WARNINGS 1
////#pragma once
////
//#include <stdbool.h>
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//#include <malloc.h>
//
//typedef int TypeData;
//struct Stack
//{
//	TypeData* elem; //数组
//	int capacity;   //数组的容量
//	int tail;       //栈顶
//};
//typedef struct Stack Stack;
////bool IsEmpty(Stack* ps)
////{
////	assert(ps);
////	return ps->tail == 0;
////}
////
////TypeData pop(Stack* ps) //出栈
////{
////	assert(ps);
////	assert(!IsEmpty(ps));
////	return ps->elem[--(ps->tail)];
////}
////
////TypeData peek(Stack* ps) //数据
////{
////	assert(ps);
////	assert(!IsEmpty(ps));
////	return ps->elem[ps->tail - 1];
////}
////
////
////void InitStack(Stack* ps)
////{
////	assert(ps);
////	ps->elem = NULL;
////	ps->capacity = 0;
////	ps->tail = 0;
////}
////
////
//void DestroyStack(Stack* ps)
//{
//	assert(ps);
//	free(ps->elem);
//	ps->elem = NULL;
//	ps->capacity = 0;
//	ps->tail = 0;
//}
//
//
//bool isFull(Stack* ps)
//{
//	assert(ps);
//	return ps->capacity == ps->tail;
//}
//void push(Stack* ps, TypeData val)  //入栈
//{
//	assert(ps);
//	if (isFull(ps))
//	{
//		TypeData* newElem = (TypeData*)realloc(ps->elem, ps->capacity + 3);
//
//		ps->elem = newElem;
//		ps->capacity += 3;
//	}
//	ps->elem[ps->tail++] = val;
//}
//
//
//typedef struct {
//	Stack s1;//这个进
//	Stack s2;//这个出
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//	MyQueue* myQueue = (MyQueue*)malloc(sizeof(MyQueue));
//	InitStack(&myQueue->s1);
//	InitStack(&myQueue->s2);
//	return myQueue;
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//
//	return IsEmpty(&obj->s1);
//}
//void myQueuePush(MyQueue* obj, int x) {
//	assert(obj);
//	push(&obj->s1, x);
//}
//
//int myQueuePop(MyQueue* obj) {
//	if (myQueueEmpty(obj))
//	{
//		return -1;
//	}
//	int ret = -1;
//	while (!IsEmpty(&obj->s1))
//	{
//		ret = pop(&obj->s1);
//		if (!IsEmpty(&obj->s1))
//		{
//			push(&obj->s2, ret);
//		}
//	}
//	int x = 0;
//	while (!IsEmpty(&obj->s2))
//	{
//		push(&obj->s1, pop(&obj->s2));
//	}
//	return ret;
//}
//
//int myQueuePeek(MyQueue* obj) {
//
//	if (myQueueEmpty(obj))
//	{
//		return -1;
//	}
//	int ret = -1;
//	while (!IsEmpty(&obj->s1))
//	{
//		ret = pop(&obj->s1);
//		push(&obj->s2, ret);
//
//	}
//	int x = 0;
//	while (!IsEmpty(&obj->s2))
//	{
//		push(&obj->s1, pop(&obj->s2));
//	}
//	return ret;
//}
//
//
//
//void myQueueFree(MyQueue* obj) {
//	DestroyStack(&obj->s1);
//	DestroyStack(&obj->s2);
//	free(obj);
//}
//
//int main()
//{
//	int arr[] = { 12, 3 };
//	free(arr);
//	/*Stack s;
//	Stack* stack = &s;
//	InitStack(stack);
//	push(stack, 1);
//	DestroyStack(stack);*/
//
//	//MyQueue* q = myQueueCreate();
//	//myQueuePush(q, 1);
//	//myQueuePush(q, 2);
//
//	//printf("%d\n", myQueuePeek(q));//1
//	//printf("%d\n", myQueuePop(q));//1
//
//	//myQueueFree(q);
//	//printf("%d\n", myQueuePeek(q));//2
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////
////typedef int TypeData;
////
////typedef struct QueueNode
////{
////	TypeData val;
////	struct QueueNode* next;
////}QueueNode;
////
////typedef struct Queue
////{
////	QueueNode* head;
////	QueueNode* tail;
////}Queue;
////
////void QueueInit(Queue* pq)
////{
////	assert(pq);
////	pq->head = NULL;
////	pq->tail = NULL;
////}
////
////void QueuePush(Queue* pq, TypeData x)
////{
////	assert(pq);
////	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
////	assert(node);
////	node->val = x;
////	node->next = NULL;
////
////	if (pq->head == NULL)
////	{
////		pq->head = node;
////		pq->tail = pq->head;
////		return;
////	}
////	pq->tail->next = node;
////	pq->tail = pq->tail->next;
////}
////
////TypeData QueueFront(Queue* pq)
////{
////	assert(pq);
////	assert(pq->head);
////	return pq->head->val;
////}
////
////void QueuePop(Queue* pq)
////{
////	assert(pq);
////	assert(pq->head && pq->tail);
////	if (pq->head->next == NULL)
////	{
////		free(pq->head);
////		pq->head = NULL;
////		pq->tail = NULL;
////		return;
////	}
////	QueueNode* headNext = pq->head->next;
////	free(pq->head);
////	pq->head = headNext;
////	// if(pq->head == NULL)
////	// {
////	//     pq->tail = NULL;
////	// }
////}
////
////bool QueueEmpty(Queue* pq)
////{
////	assert(pq);
////	return pq->head == NULL;
////}
////
////void QueueDestroy(Queue* pq)
////{
////	assert(pq);
////
////	QueueNode* cur = pq->head;
////	while (cur != NULL)
////	{
////		QueueNode* next = cur->next;
////		free(cur);
////		cur = next;
////	}
////	//第二件事  销毁队列
////	pq->head = NULL;
////	pq->tail = NULL;
////	free(pq);
////}
////
////typedef struct {
////	Queue* q1;
////	Queue* q2;
////} MyStack;
////
////
////MyStack* myStackCreate() {
////	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
////	assert(obj);
////	obj->q1 = (Queue*)malloc(sizeof(Queue));
////	obj->q2 = (Queue*)malloc(sizeof(Queue));
////	QueueInit(obj->q1);
////	QueueInit(obj->q2);
////	return obj;
////}
////
////void myStackPush(MyStack* obj, int x) {
////
////	assert(obj);
////	if (!QueueEmpty(obj->q1))
////	{
////		QueuePush(obj->q1, x);
////	}
////	else
////	{
////		QueuePush(obj->q2, x);
////	}
////}
////
////int myStackPop(MyStack* obj) {
////	assert(obj);
////	TypeData val = 0;
////	if (!QueueEmpty(obj->q1))
////	{
////		while (!QueueEmpty(obj->q1))
////		{
////			val = QueueFront(obj->q1);
////			QueuePop(obj->q1);
////			if (!QueueEmpty(obj->q1))
////			{
////				QueuePush(obj->q2, val);
////			}
////		}
////		return val;
////	}
////	if (!QueueEmpty(obj->q2))
////	{
////		while (!QueueEmpty(obj->q2))
////		{
////			val = QueueFront(obj->q2);
////			QueuePop(obj->q2);
////			if (!QueueEmpty(obj->q2))
////			{
////				QueuePush(obj->q1, val);
////			}
////		}
////		return val;
////	}
////
////	return val;
////}
////
////int myStackTop(MyStack* obj) {
////	assert(obj);
////	TypeData val = 0;
////	if (!QueueEmpty(obj->q1))
////	{
////		while (!QueueEmpty(obj->q1))
////		{
////			val = QueueFront(obj->q1);
////			QueuePop(obj->q1);
////
////			QueuePush(obj->q2, val);
////		}
////		return val;
////	}
////	if (!QueueEmpty(obj->q2))
////	{
////		while (!QueueEmpty(obj->q2))
////		{
////			val = QueueFront(obj->q2);
////			QueuePop(obj->q2);
////			QueuePush(obj->q1, val);
////		}
////		return val;
////	}
////	return val;
////}
////
////bool myStackEmpty(MyStack* obj) {
////	return QueueEmpty(obj->q1) && QueueEmpty(obj->q2);
////}
////
////void myStackFree(MyStack* obj) {
////	assert(obj);
////	QueueDestroy(obj->q1);
////	QueueDestroy(obj->q2);
////	free(obj);
////}
////
////int main()
////{
////	
////	MyStack* s = myStackCreate();
////	myStackPush(s, 1);
////	myStackPush(s, 2);
////	//printf("%d\n", myStackTop(s));
////	
////	printf("%d\n", myStackPop(s)); //2
////	myStackPush(s, 3);
////	myStackPush(s, 4);
////	myStackPush(s, 5);
////	myStackPush(s, 6);
////	printf("%d\n", myStackPop(s)); //3
////	printf("%d\n", myStackPop(s)); //1
////	printf("%d\n", myStackEmpty(s));
////	/*myStackFree(s);
////	printf("%d\n", myStackPop(s));*/
////	return 0;
////}
//
//#pragma once
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <assert.h>
//
////struct Stack
////{
////	int a[N];
////	int top; // 栈顶的位置
////};
//
//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* a;
//	int top;		// 栈顶的位置
//	int capacity;	// 容量
//}ST;
//
//
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//void StackDestory(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	// 
//	if (ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		ps->a = (STDataType*)realloc(ps->a, newCapacity* sizeof(STDataType));
//		if (ps->a == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//
//		ps->capacity = newCapacity;
//	}
//
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//int main()
//{
//	ST s;
//	ST* ps = &s;
//	StackInit(ps);
//	//StackPush(ps, 1);
//	StackDestory(ps);
//	return 0;
//}




