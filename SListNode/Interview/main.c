#include "Interview.h"

int main()
{
	SListNode *ps, *pf, *pps;
	SListInit(&ps);
	SListPushBack(&ps, 1);
	SListPushBack(&ps, 1);
	SListPushBack(&ps, 3);
	SListPushBack(&ps, 5);
	SListPushBack(&ps, 7);
	SListPushBack(&ps, 9);
	SListNodePrint(&ps);

	//SListInit(&pps);
	//SListPushBack(&pps, 1);
	//SListPushBack(&pps, 2);
	//SListPushBack(&pps, 4);
	//SListPushBack(&pps, 6);
	//SListPushBack(&pps, 10);
	//SListPushBack(&pps, 12);
	//SListNodePrint(&pps);

	//pf = MergeOrderedList(ps, pps);
	//SListNodePrint(&pf);
	//pf = FindK(ps, 1);
	//printf("%d\n", pf->data);

	pf = RemoveK(ps, 6);
	SListNodePrint(&pf);
	return 0;
}
