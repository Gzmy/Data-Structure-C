#include "Interview.h"

void MinStackPrint(MinStack *ms)
{
	assert(ms);

	int i;
	printf("数据栈为");
	for(i = 0; i < (&(ms->data))->top; i++)
	{
		printf("%d, ", (&(ms->data))->array[i]);
	}
	printf("最小栈为");
	for(i = 0; i < (&(ms->Min))->top; i++)
	{
		printf("%d, ", (&(ms->Min))->array[i]);
	}
	printf("\n");
}

void MinStackInit(MinStack *ms)
{	
	assert(ms);

	StackInit(&(ms->data));
	StackInit(&(ms->Min));
}

void MinStackPush(MinStack *ms, MDataType data)
{
	assert(ms);
	MDataType top;	

	if(StackEmpty(&(ms->data)))
	{
		StackPush(&(ms->data), data);
		StackPush(&(ms->Min), data);
	}
	else
	{
		top = StackTop(&(ms->Min));
		if(data <= top)
		{
		StackPush(&(ms->data), data);
		StackPush(&(ms->Min), data);
		}
		else
		{
			StackPush(&(ms->data), data);
		}
	}
}

void MinStackPop(MinStack *ms)
{
	assert(ms);

	MDataType top1 = StackTop(&(ms->data));
	MDataType top2 = StackTop(&(ms->Min));

	if(top1 == top2)
	{
		StackPop(&(ms->data));
		StackPop(&(ms->Min));
	}
	else
	{
		StackPop(&(ms->data));
	}
}

MDataType MinStackTop(MinStack *ms)
{
	assert(ms);
	return StackTop(&(ms->data));
}

MDataType MinStackMin(MinStack *ms)
{
	assert(ms);
	return StackTop(&(ms->Min));
}

int MinStackEmpty(MinStack *ms)
{
	assert(ms);
	return 0 == (&(ms->data))->top;
}


void TStackToQueuePrint(TStackToQueue *ss)
{
	assert(ss);

	if(TStackToQueueEmpty(ss))
		return;

	/*
	 *仔细琢磨
	 */
	int i;
	for(i = (&ss->s2)->top-1; i > 0; i--)
	{
		printf("%d, ", (&ss->s2)->array[i]);
	}
	for(i = 0; i < (&ss->s1)->top; i++)
	{
		printf("%d, ", (&ss->s1)->array[i]);
	}
	printf("\n");
}

void TStackToQueueInit(TStackToQueue *ss)
{
	assert(ss);

	StackInit(&ss->s1);
	StackInit(&ss->s2);
}

void TStackToQueuePush(TStackToQueue *ss, TQDataType data)
{
	assert(ss);

	StackPush(&ss->s1, data);
}

void TStackToQueuePop(TStackToQueue *ss)
{
	assert(ss);
	if(TStackToQueueEmpty(ss))
		return;

	/*
	 *保持队列特性,使最先进的都在s2的top
	 */
	if(StackEmpty(&ss->s2))
	{
		while(!StackEmpty(&ss->s1))
		{
			StackPush(&ss->s2, StackTop(&ss->s1));
			StackPop(&ss->s1);
		}
	}

	StackPop(&ss->s2);
}

TQDataType TStackToQueueTop(TStackToQueue *ss)
{
	assert(ss);
	if(TStackToQueueEmpty(ss))
		return;

	if(StackEmpty(&ss->s2))
	{
		while(!StackEmpty(&ss->s1))
		{
			StackPush(&ss->s2, StackTop(&ss->s1));
			StackPop(&ss->s1);
		}
	}

	return StackTop(&ss->s2);
}

TQDataType TStackToQueueTail(TStackToQueue *ss)//队尾元素,是s1的栈顶
{
	assert(ss);
	if(TStackToQueueEmpty(ss))
		return;

	if(StackEmpty(&ss->s1))
	{
		while(!StackEmpty(&ss->s2))
		{
			StackPush(&ss->s1, StackTop(&ss->s2));
			StackPop(&ss->s2);
		}
	}

	return StackTop(&ss->s1);
}

int TStackToQueueEmpty(TStackToQueue *ss)
{
	assert(ss);

	if(StackEmpty(&ss->s1) && StackEmpty(&ss->s2))
		return 1;

	return 0;
}

int TStackToQueueSize(TStackToQueue *ss)
{
	return StackSize(&ss->s1) + StackSize(&ss->s2);
}


void TQueueToStackPrint(TQueueToStack *ss)
{
	
}

void TQueueToStackInit(TQueueToStack *ss)
{
	assert(ss);

	QueueInit(&ss->q1);
	QueueInit(&ss->q2);
}

void TQueueToStackPush(TQueueToStack *ss, TSDataType data)
{
	assert(ss);

	if(QueueEmpty(&ss->q1))
		QueuePush(&ss->q2, data);
	else
		QueuePush(&ss->q1, data);
}

void TQueueToStackPop(TQueueToStack *ss)
{
	assert(ss);

	if(!TQueueToStackEmpty(ss))
	{
		if(QueueSize(&ss->q1) >= 1)
		{
			while(QueueSize(&ss->q1) != 1)
			{
				QueuePush(&ss->q2, QueueTop(&ss->q1));
				QueuePop(&ss->q1);
			}
			QueuePop(&ss->q1);
		}
		else
		{
			while(QueueSize(&ss->q2) != 1)
			{
				QueuePush(&ss->q1, QueueTop(&ss->q2));
				QueuePop(&ss->q2);
			}
			QueuePop(&ss->q2);
		}
	}
}

TQDataType TQueueToStackTop(TQueueToStack *ss)
{
	assert(ss);

	if(QueueEmpty(&ss->q1))
		return QueueTop(&ss->q2);
	return QueueTop(&ss->q1);
}

TQDataType TQueueToStackTail(TQueueToStack *ss)
{
	assert(ss);

	if(QueueEmpty(&ss->q1))
		return QueueTail(&ss->q2);
	return QueueTail(&ss->q1);
}

int TQueueToStackEmpty(TQueueToStack *ss)
{
	assert(ss);
	if(QueueEmpty(&ss->q1) && QueueEmpty(&ss->q2))
		return 1;
	return 0;
}

int TQueueToStackSize(TQueueToStack *ss)
{
	assert(ss);
	return QueueSize(&ss->q1) + QueueSize(&ss->q2);
}


//four
int InOutIsVaild(DataType *InOrder, DataType *OutOrder, int size)
{
	Stack s;
	StackInit(&s);
	int index = 0;
	int outdex = 0;

	while(index < size)
	{
		if(InOrder[index] == OutOrder[outdex])
			index++,outdex++;
		else if(!StackEmpty(&s) && StackTop(&s) == OutOrder[outdex])
		{
			StackPop(&s);
			outdex++;
		}
		else
			StackPush(&s, InOrder[index++]);
	}

	while(!StackEmpty(&s))
	{
		if(StackTop(&s) == OutOrder[outdex])
		{
			StackPop(&s);
			outdex++;
		}
		else
			return 0;
	}

	return 1;
}

//five
void ShareStackPrint(ShareStack *ss)
{
	assert(ss);
	int i;
	printf("Stack1:");
	for(i = 0; i < ss->top1; i++)
	{
		printf("%d, ", ss->array[i]);
	}
	printf("Stack2:");
	for(i = MAX_SIZE_SHARE - 1; i > ss->top2; i--)
	{
		printf("%d, ", ss->array[i]);
	}
	printf("\n");
}

void ShareStackInit(ShareStack *ss)
{
	assert(ss);

	ss->top1 = 0;
	ss->top2 = MAX_SIZE_SHARE - 1;
}

void ShareStackPush(ShareStack *ss, DataType data, int which)
{
	assert(ss && (which == 1 || which == 0));

	if(which == 0)
	{
		if(ss->top1 <= ss->top2)
		{
			ss->array[ss->top1++] = data;
			return;
		}
		else
		{
			printf("Stack1 is full\n");
			return;
		}
	}
	else
	{
		if(ss->top1 <= ss->top2)
		{
			ss->array[ss->top2--] = data;
			return;
		}
		else
		{
			printf("Stack2 is full\n");
			return;
		}
	}
}

void ShareStackPop(ShareStack *ss, int which)
{
	assert(which == 1 || which == 0);

	if(which == 0)
	{
		if(ss->top1 == 0)
		{
			printf("Stack1 is free!\n");
			return;
		}
		ss->top1--;
		return;
	}
	else
	{
		if(ss->top2 == MAX_SIZE - 1)
		{
			printf("Stack2 is free!\n");
			return;
		}
		ss->top2++;
		return;
	}
}

int ShareStackEmpty(ShareStack *ss)
{
	assert(ss);

	if(ss->top1 == 0 && ss->top2 == MAX_SIZE - 1)
		return 1;

	return 0;
}

DataType ShareStackTop(ShareStack *ss, int which)
{
	assert(ss && (which==1 || which==0));

	if(which == 0)
		return ss->array[ss->top1 - 1];
	else
		return ss->array[ss->top2 + 1];
}

int ShareStackSize(ShareStack *ss)
{
	assert(ss);

	return ss->top1 + (MAX_SIZE_SHARE - 1 - ss->top2);
}

