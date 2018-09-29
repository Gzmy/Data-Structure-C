#pragma once
#include "Stack.h"
#include "Queue.h"

//第一题
typedef int MDataType;

typedef struct MinStack
{
	Stack data;
	Stack Min;
} MinStack;

void MinStackPrint(MinStack *ms);
void MinStackInit(MinStack *ms);
void MinStackPush(MinStack *ms, MDataType data);
void MinStackPop(MinStack *ms);
MDataType MinStackTop(MinStack *ms);
MDataType MinStackMin(MinStack *ms);
int MinStackEmpty(MinStack *ms);

//第二题
typedef int TQDataType;

typedef struct TStackToQueue
{
	Stack s1;
	Stack s2;
} TStackToQueue;

void TStackToQueuePrint(TStackToQueue *ss);
void TStackToQueueInit(TStackToQueue *ss);
void TStackToQueuePush(TStackToQueue *ss, TQDataType data);
void TStackToQueuePop(TStackToQueue *ss);
TQDataType TStackToQueueTop(TStackToQueue *ss);
TQDataType TStackToQueueTail(TStackToQueue *ss);
int TStackToQueueEmpty(TStackToQueue *ss);
int TStackToQueueSize(TStackToQueue *ss);

//第三题
typedef int TSDataType;

typedef struct TQueueToStack
{
	Queue q1;
	Queue q2;
} TQueueToStack;

void TQueueToStackPrint(TQueueToStack *ss);
void TQueueToStackInit(TQueueToStack *ss);
void TQueueToStackPush(TQueueToStack *ss, TSDataType data);
void TQueueToStackPop(TQueueToStack *ss);
TQDataType TQueueToStackTop(TQueueToStack *ss);
TQDataType TQueueToStackTail(TQueueToStack *ss);
int TQueueToStackEmpty(TQueueToStack *ss);
int TQueueToStackSize(TQueueToStack *ss);

//第四题
int InOutIsVaild(DataType *InOrder, DataType *OutOrder, int size);

//第五题
//一个数组实现两个栈

#define MAX_SIZE_SHARE 20

typedef struct ShareStack
{
	DataType array[MAX_SIZE_SHARE];
	int top1;
	int top2;
} ShareStack;

void ShareStackPrint(ShareStack *ss);
void ShareStackInit(ShareStack *ss);
void ShareStackPush(ShareStack *ss, DataType data, int which);
void ShareStackPop(ShareStack *ss, int which);
int ShareStackEmpty(ShareStack *ss);
DataType ShareStackTop(ShareStack *ss, int which);
int ShareStackSize(ShareStack *ss);

