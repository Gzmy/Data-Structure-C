#include "Queue.h"

void QueuePrint(Queue *pQueue)
{
	QNode *pNode;
	pNode = pQueue->pFront;

	while(pNode)
	{
		printf("%d->", pNode->data);
		pNode = pNode->pNext;
	}
	printf("NULL\n");
}

void QueueInit(Queue *pQueue)
{
	pQueue->pFront = pQueue->pRear = NULL;
	pQueue->size = 0;
}

void QueuePush(Queue *pQueue, QDataType data)
{
	QNode *pNewNode = (QNode*)malloc(sizeof(QNode));
	pNewNode->data = data;
	pNewNode->pNext = NULL;

	if(pQueue->pFront == NULL)
	{
		pQueue->pFront = pQueue->pRear = pNewNode;
		pQueue->size++;
		return;
	}

	pQueue->pRear->pNext = pNewNode;
	pQueue->pRear = pNewNode;
	pQueue->size++;
}

void QueuePop(Queue *pQueue)
{
	QNode *pDel;

	if(pQueue->pFront == NULL)
	{
		printf("表中无数据\n");
		return;
	}

	pDel = pQueue->pFront;
	pQueue->pFront = pDel->pNext;
	pQueue->size--;
	free(pDel);
}

QDataType QueueFront(Queue *pQueue)
{
	QNode *pNode = pQueue->pFront;
	assert(pQueue);
	assert(pNode);

	return pNode->data;
}

QDataType QueueTop(Queue *pQueue)
{
	QNode *pNode = pQueue->pFront;
	assert(pQueue);
	assert(pNode);

	return pNode->data;
}

int QueueIsEmpty(Queue *pQueue)
{
	return 0 == pQueue->size;
}

int QueueSize(Queue *pQueue)
{
	return pQueue->size;
}




