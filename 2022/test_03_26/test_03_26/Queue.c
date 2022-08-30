//#define _CRT_SECURE_NO_WARNINGS 1
//#include "Queue.h"
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
//void QueuePush(Queue* pq, TypeData x)
//{
//	assert(pq);
//	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
//	if (node == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	node->val = x;
//	node->next = NULL;
//	if (pq->head == NULL)
//	{
//		pq->head = node;
//		pq->tail = pq->head;
//		return;
//	}
//	pq->tail->next = node;
//	pq->tail = pq->tail->next;
//}
//
//TypeData QueueFront(Queue* pq)
//{
//	assert(pq);
//	if (QueueEmpty(pq))
//	{
//		return -1;
//	}
//	return pq->head->val;
//}
//
//TypeData QueueBack(Queue* pq)
//{
//	assert(pq);
//	if (QueueEmpty(pq))
//	{
//		return -1;
//	}
//	return pq->tail->val;
//}
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head && pq->tail);
//	if (pq->head->next == NULL)
//	{
//		free(pq->head);
//		pq->head = NULL;
//		pq->tail = NULL;
//		return;
//	}
//	QueueNode* headNext = pq->head->next;
//	free(pq->head);
//	pq->head = headNext;
//	 if(pq->head == NULL)
//	 {
//	     pq->tail = NULL;
//	 }
//}
//
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head == NULL;
//}
//
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	QueueNode* cur = pq->head;
//	int count = 0;
//	while (cur != NULL)
//	{
//		count++;
//		cur = cur->next;
//	}
//	return count;
//}
//
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//
//	QueueNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		QueueNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = NULL;
//	pq->tail = NULL;
//	
//}