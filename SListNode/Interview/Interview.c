#include "Interview.h"

void SListInit(SListNode **pFirst)
{
	*pFirst = NULL;
}

void SListPushBack(SListNode **pFirst, DataType data)
{
	SListNode *pNewNode = (SListNode *)malloc(sizeof(SListNode));
	assert(pNewNode);
	pNewNode->data = data;
	pNewNode->pNext = NULL;
	SListNode *pNode;

	if(*pFirst == NULL)
	{
		*pFirst = pNewNode;
		return;
	}

	for(pNode = *pFirst; pNode->pNext != NULL; pNode = pNode->pNext)
	{
	}

	pNode->pNext = pNewNode;
}

void SListNodePrint(SListNode **pFirst)
{
	SListNode *pNode = *pFirst;
	for(; pNode != NULL; pNode = pNode->pNext)
	{
		printf("%d->", pNode->data);
	}
	printf("NULL\n");
}

void ReversePrint(SListNode *pFirst)
{
	assert(pFirst);
	//SListNode *pEnd = NULL;
	//SListNode *pCur = NULL;

	//while(pEnd != pFirst)
	//{
	//	pCur = pFirst;
	//	while(pCur->pNext != pEnd)
	//	{
	//		pCur = pCur->pNext;
	//	}
	//	pEnd = pCur;
	//	printf("%d->", pCur->data);
	//}
	//printf("\n");

	SListNode *pNode = pFirst;

	if(pNode->pNext)
		ReversePrint(pNode->pNext);
	
	printf("%d->", pNode->data);
}

SListNode *ReverseList(SListNode *pFirst)
{
	assert(pFirst);
	SListNode *pResult = NULL;
	SListNode *pDel;
	SListNode *pNode = pFirst;

	while(pNode)
	{
		//头删
		pDel = pNode;
		pNode = pNode->pNext;
		//头插
		pDel->pNext = pResult;
		pResult = pDel;
	}

	return pResult;
}

void RemoveNodeNotTail(SListNode *pos)
{
	assert(pos);
	SListNode *pNode = pos->pNext;

	pos->data = pNode->data;
	pos->pNext = pNode->pNext;

	free(pNode);
}

void InsertNoHead(SListNode *pos, int data)
{	
	SListNode *pNewNode = (SListNode *)malloc(sizeof(SListNode));
	assert(pNewNode);

	pNewNode->data = pos->data;
	pNewNode->pNext = pos->pNext;

	pos->data = data;
	pos->pNext = pNewNode;
}

SListNode *JocephCircle(SListNode *pFirst, int k)
{
	SListNode *pNode = pFirst;
	SListNode *pCur = NULL;
	SListNode *pDel;
	int i;
	
	//制环
	while(pNode->pNext)
	{
		pNode = pNode->pNext;
	}
	pNode->pNext = pFirst;
	pNode = pFirst;

	while(pNode->pNext != pNode)
	{
		//找到要删结点
		for(i = 0; i < k - 1; i++)
		{
			pCur = pNode;
			pNode = pNode->pNext;
		}

		pDel = pNode;
		pNode = pNode->pNext;
		pCur->pNext = pNode;
		free(pDel);
	}

	return pNode;
}

static void swap(DataType *a, DataType *b)
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(SListNode *pFirst)
{
	SListNode *pCur = NULL;
	SListNode *pEnd = NULL;
	SListNode *pNext = NULL;

	while(pEnd != pFirst)
	{
		pCur = pFirst;
		pNext = pCur->pNext;
		while(pNext != pEnd)
		{
			if(pCur->data > pNext->data)
				swap(&(pCur->data), &(pNext->data));
			pCur = pNext;
			pNext = pCur->pNext;
		}

		pEnd = pCur;
	}
}

static SListNode *MyPushBack(SListNode **p1, SListNode **p2)
{
	SListNode *pNode = *p1;

	while(pNode->pNext)
	{
		pNode = pNode->pNext;
	}
	pNode->pNext = *p2;

	return *p1;
}

SListNode *MergeOrderedList(SListNode *p1First, SListNode *p2First)
{
	assert(p1First && p2First);
	SListNode *p1 = p1First;
	SListNode *p2 = p2First;
	SListNode *pNode = NULL;
	SListNode *pCur;

	while(p1 != NULL && p2 != NULL)
	{
		if(p1->data < p2->data)
		{
			if(pNode == NULL)
			{
				pNode =p1;
				pCur = pNode;
				p1 = p1->pNext;
			}
			else
			{
				pNode->pNext = p1;
				pNode = p1;
				p1 = p1->pNext;
			}
		}
		else
		{
			if(pNode == NULL)
			{
				pNode = p2;
				pCur = pNode;
				p2 = p2->pNext;
			}
			else
			{
				pNode->pNext = p2;
				pNode = p2;
				p2 = p2->pNext;
			}
		}
	}

	if(p1 == NULL)
		pNode->pNext = p2;
	else if(p2 == NULL)
		pNode->pNext = p1;
	else if(p1 == NULL && p2 == NULL)
		return pNode;

	return pCur;
	//SListNode *p1 = p1First;
	//SListNode *p2 = p2First;
	//SListNode *Result = NULL;
	//SListNode *pNode;

	//if(p1 == NULL)
	//	return p2;
	//if(p2 == NULL)
	//	return p1;
	//if(p1 == NULL && p2 == NULL)
	//	return NULL;

	//if(p1->data > p2->data)
	//{
	//	pNode = p2;
	//	p2 = p2->pNext;
	//	pNode->pNext = NULL;
	//	Result = pNode;
	//}
	//else
	//{
	//	pNode = p1;
	//	p1 = p1->pNext;
	//	pNode->pNext = NULL;
	//	Result = pNode;
	//}

	//while((p1 != NULL) && (p2 != NULL))
	//{
	//	if(p1->data > p2->data)
	//	{
	//		//头删
	//		pNode = p2;
	//		p2 = p2->pNext;
	//		pNode->pNext = NULL;

	//		//尾插
	//		Result = MyPushBack(&Result, &pNode);
	//	}
	//	else
	//	{
	//		pNode = p1;
	//		p1 = p1->pNext;
	//		pNode->pNext = NULL;

	//		Result = MyPushBack(&Result, &pNode);
	//	}
	//}

	//if(p1 == NULL)
	//	Result = MyPushBack(&Result, &p2);
	//if(p2 == NULL)
	//	Result = MyPushBack(&Result, &p1);

	//return Result;
}

SListNode *FindMid(SListNode *pFirst)
{
	SListNode *pNode = pFirst;
	SListNode *pTNode = pFirst;
	SListNode *pCur;

	while(pTNode)
	{
		pCur = pTNode->pNext;
		if(pCur == NULL)
			break;

		pTNode = pCur->pNext;
		if(pTNode == NULL)
			break;

		pNode = pNode->pNext;
	}

	return pNode;
}

SListNode *FindK(SListNode *pFirst, int k)
{
	SListNode *pNode = pFirst;
	SListNode *pCur = pFirst;

	while(--k)//先自减,在使用
	{
		pCur = pCur->pNext;
	}

	while(pCur->pNext)
	{
		pNode = pNode->pNext;
		pCur = pCur->pNext;
	}
	return pNode;
}

void RemoveK(SListNode *pFirst, int k)
{
	SListNode *pNode = pFirst;
	SListNode *pCur = pFirst;
	SListNode *pDel;

	while(--k)
	{
		pCur = pCur->pNext;
	}

	while(pCur->pNext)
	{
		pDel = pNode;
		pNode = pNode->pNext;
		pCur = pCur->pNext;
	}

	pDel->pNext = pNode->pNext;
	free(pNode);
}


