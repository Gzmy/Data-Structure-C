#include"SeqList.h"

void SeqPrint(SeqList *pSL)
{
	int i = 0;
	for (i; i < pSL->size; i++)
	{
		printf("%d, ", pSL->array[i]);
	}

	printf("\n");
}

void SeqListinit(SeqList *pSL)
{
	assert(pSL);
	pSL->size = 0;
}

void SeqListPushBack(SeqList *pSL, DataType data)
{
	assert(pSL);

	if (pSL->size == MAX_SIZE)
	{
		printf("表满\n");
		return;
	}

	pSL->array[pSL->size] = data;
	pSL->size++;
}

void SeqListPushFront(SeqList *pSL, DataType data)
{
	assert(pSL);

	if (pSL->size == MAX_SIZE)
	{
		printf("表满\n");
		return;
	}

	int i = pSL->size;
	for (i; i > 0; i--)
	{
		pSL->array[i] = pSL->array[i - 1];
	}
	pSL->array[i] = data;

	pSL->size++;
}

void SeqListInsert(SeqList *pSL, int pos, DataType data)
{
	assert(pSL);

	if (pSL->size == MAX_SIZE)
	{
		printf("表满\n");
		return;
	}

	int i = pSL->size;
	for (i; i > pSL->size - pos - 1; i--)
	{
		pSL->array[i] = pSL->array[i - 1];
	}
	pSL->array[i] = data;

	pSL->size++;
}

void SeqListPopBack(SeqList *pSL)
{
	assert(pSL);

	pSL->size--;
}

void SeqListPopFront(SeqList *pSL)
{
	assert(pSL);

	int i = 0;
	for (i; i < pSL->size - 1; i++)
	{
		pSL->array[i] = pSL->array[i + 1];
	}
	pSL->size--;
}

void SeqListErase(SeqList *pSL, int pos)
{
	assert(pSL);

	int i = 0;
	for (i; i < pSL->size - pos; i++)
	{
		pSL->array[pos + i] = pSL->array[pos + 1 + i];
	}
	pSL->size--;
}

void SeqListRemove(SeqList *pSL, DataType data)
{
	assert(pSL);

	int i = 0;
	for (i; i < pSL->size; i++)
	{
		if (pSL->array[i] == data)
		{
			SeqListErase(pSL, i);
			return;
		}
	}

	printf("顺序表中没有给定数据\n");
}

void SeqListRemoveAll(SeqList *pSL, DataType data)
{
	assert(pSL);
	
	int i, j;
	int count = 0;

	for (i = 0, j = 0; i < pSL->size; i++)
	{
		if (pSL->array[i] == data)
			continue;
		else
		{
			pSL->array[j] = pSL->array[i];
			j++, count++;
		}
	}

	pSL->size = count;
}

void SeqListClear(SeqList *pSL)//顺序表清零
{
	assert(pSL);
	pSL->size = 0;
}

int SeqListFind(SeqList *pSL, DataType data)
{
	assert(pSL);

	int i = 0;
	for (i; i < pSL->size; i++)
	{
		if (pSL->array[i] == data)
		{
			return i;
		}
	}
}

int SeqListEmpty(SeqList *pSL)
{
	assert(pSL);

	if (pSL->size == 0)
		return 1;
	else
		return 0;
}

int SeqListSize(SeqList *pSL)
{
	return pSL->size;
}

void swap(DataType *p, DataType *q)
{
	DataType tmp = *p;
	*p = *q;
	*q = tmp;
}

void SeqListSort(SeqList *pSL)
{
	assert(pSL);

	int mindex, maxdex;
	int start, end;
	int i;

	for (start = 0, end = pSL->size - 1; start <= end; start++, end--)
	{
		maxdex = start;
		mindex = start;
		for (i = start; i <= end; i++)
		{
			if (pSL->array[i] < pSL->array[mindex])
				mindex = i;
			else if (pSL->array[i] > pSL->array[maxdex])
				maxdex = i;
		}
		swap(pSL->array + start, pSL->array + mindex);
		if (maxdex == start)
			maxdex = mindex;
		swap(pSL->array + end, pSL->array + maxdex);
	}
}








