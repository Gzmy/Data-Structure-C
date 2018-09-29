#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
//队列操作(无头)

typedef int QDataType;

typedef struct QNode
{
	QDataType data;
	struct QNode *pNext;
}QNode;

typedef struct Queue
{
	QNode *pFront;
	QNode *pRear;
	int size;
}Queue;

void QueuePrint(Queue *pQueue);//打印
void QueueInit(Queue *pQueue);//初始化
void QueuePush(Queue *pQueue, QDataType data);//尾插
void QueuePop(Queue *pQueue);//头删
QDataType QueueFront(Queue *pQueue);//返回头结点数据
QDataType QueueTop(Queue *pQueue);//返回队首元素
QDataType QueueTail(Queue *pQueue);
int QueueEmpty(Queue *pQueue);//是否为空
int QueueSize(Queue *pQueue);//队列个数



