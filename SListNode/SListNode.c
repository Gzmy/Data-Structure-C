#include "SListNode.h"

SListNode *__CreatNewNode(DataType data)
{
	SListNode *pNewNode = (SListNode *)malloc(sizeof(SListNode));

	if(!pNewNode)
	{
		printf("内存申请失败\n");
		return NULL;
	}

	pNewNode->data = data;
	pNewNode->pNext = NULL;

	return pNewNode;
}

void SListNodePrint(SListNode **ppfirst)
{
	assert(ppfirst);
	SListNode *pNode = *ppfirst;

	while(pNode)
	{
		printf("%d->", pNode->data);
		pNode = pNode->pNext;
	}

	printf("NULL\n");
}

void SListInit(SListNode **ppfirst)
{
	*ppfirst = NULL;
}

void SListPushBack(SListNode **ppfirst, DataType data)
{
	assert(ppfirst);
	SListNode *pNode = *ppfirst;
	SListNode *pNewNode = __CreatNewNode(data);
	assert(pNewNode);

	if(*ppfirst == NULL)
	{
		*ppfirst = pNewNode;
		return;
	}

	while(pNode->pNext)
	{
		pNode = pNode->pNext;
	}

	pNode->pNext = pNewNode;
}

void SListPushFront(SListNode **ppfirst, DataType data)
{
	assert(ppfirst);
	SListNode *pNode = *ppfirst;
	SListNode *pNewNode = __CreatNewNode(data);

	pNewNode->pNext = *ppfirst;
	*ppfirst = pNewNode;
}

void SListPopBack(SListNode **ppfirst)
{
	assert(ppfirst);
	SListNode *pNode = *ppfirst;
	SListNode *pDel;

	if((*ppfirst)->pNext == NULL)
	{
		free(ppfirst);
		*ppfirst = NULL;
		return;
	}

	while(pNode->pNext->pNext)
	{
		pNode = pNode->pNext;
	}

	pDel = pNode->pNext;
	pNode->pNext = NULL;
	free(pDel);
}

void SListPopFront(SListNode **ppfirst)
{
	assert(ppfirst);
	SListNode *pDel;

	if(*ppfirst == NULL)
		return;

	pDel = *ppfirst;
	*ppfirst = pDel->pNext;
	free(pDel);
}

SListNode *SListFind(SListNode *ppfirst, DataType data)
{
	assert(ppfirst);
	SListNode *pNode = ppfirst;

	while(pNode)
	{
		if(pNode->data == data)
		{
			return pNode;
		}
		pNode = pNode->pNext;
	}

	return NULL;
}

void SListInsert(SListNode **ppfirst, SListNode *pos, DataType data)
{
	assert(ppfirst && pos);
	SListNode *pNode = *ppfirst;
	SListNode *pNewNode = __CreatNewNode(data);

	if(*ppfirst == pos)
	{
		pNewNode->pNext = pos;
		*ppfirst = pNewNode;
		return;
	}

	while(pNode->pNext != pos)
	{
		pNode = pNode->pNext;
	}
	pNode->pNext = pNewNode;
	pNewNode->pNext = pos;
}

void SListErase(SListNode **ppfirst, SListNode *pos)
{
	assert(ppfirst && pos);
	SListNode *pNode = *ppfirst;
	SListNode *pDel;

	if(pNode == pos)
	{
		SListPopFront(ppfirst);
		return;
	}

	while(pNode->pNext != pos)
	{
		pNode = pNode->pNext;
	}
	pNode->pNext = pos->pNext;
	free(pos);
}
void SListRemove(SListNode **ppfirst, DataType data)
{
	assert(ppfirst);
	SListNode *pNode = *ppfirst;
	SListNode *pFound = SListFind(pNode, data);
	assert(pFound);

	SListErase(ppfirst, pFound);
}

void SListremoveAll(SListNode **ppfirst, DataType data)
{
	assert(ppfirst);
	SListNode *pNode = *ppfirst;
	SListNode *pG;

	while(pNode->data == data)
	{
		*ppfirst = pNode->pNext;
		free(pNode);
		pNode = *ppfirst;
		if(pNode == NULL)
			return;
	}

	while(pNode->pNext)
	{
		pG = pNode->pNext;
		if(pG->data == data)
		{
			pNode->pNext = pG->pNext;
			free(pG);
		}
		else
		{
			pNode = pNode->pNext;
		}
	}
}

void SListDestroy(SListNode **ppfirst)
{
	assert(ppfirst);
	SListNode *pNode, *pG;
	for(pNode = *ppfirst; pNode != NULL;)
	{
		pG = pNode;
		pNode = pNode->pNext;
		free(pG);
	}
}


