//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//
//#include <stdbool.h>
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//#include <malloc.h>
//
//typedef int TypeData;
//
//typedef struct QueueNode
//{
//	TypeData val;
//	struct QueueNode* next;
//}QueueNode;
//
//typedef struct Queue
//{
//	QueueNode* head;
//	QueueNode* tail;
//}Queue;
//
//
//// 初始化队列 
//extern void QueueInit(Queue* pq);
//
//// 队尾入队列 
//extern void QueuePush(Queue* pq, TypeData data);
//
//// 队头出队列 
//extern void QueuePop(Queue* pq);
//
//// 获取队列头部元素 
//extern TypeData QueueFront(Queue* pq);
//
//// 获取队列队尾元素 
//extern TypeData QueueBack(Queue* pq);
//
//// 获取队列中有效元素个数 
//extern int QueueSize(Queue* pq);
//
//// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
//extern bool QueueEmpty(Queue* pq);
//
//// 销毁队列 
//extern void QueueDestroy(Queue* pq);
//
//
//
