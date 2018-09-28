#include "SListNode.h"

int main()
{
	SListNode *pf, *pNode;
	SListInit(&pf);

	SListPushBack(&pf, 1);
	SListPushBack(&pf, 0);
	SListPushBack(&pf, 1);
	SListPushBack(&pf, 1);
	SListPushBack(&pf, 2);
	SListPushBack(&pf, 1);
	SListPushBack(&pf, 3);
	SListPushBack(&pf, 1);
	SListPushBack(&pf, 1);
	SListPushBack(&pf, 4);
	SListNodePrint(&pf);

	SListPushFront(&pf, 100);
	SListPushFront(&pf, 101);
	SListPushBack(&pf, 1);
	SListPushFront(&pf, 102);
	SListPushBack(&pf, 1);
	SListPushFront(&pf, 103);
	SListPushBack(&pf, 1);
	SListPushFront(&pf, 104);
	SListNodePrint(&pf);

	SListPopBack(&pf);
	SListPopBack(&pf);
	SListPushBack(&pf, 1);
	SListNodePrint(&pf);

	SListPopFront(&pf);
	SListPopFront(&pf);
	SListPushBack(&pf, 1);
	SListNodePrint(&pf);

	SListRemove(&pf, 100);
	SListPushBack(&pf, 1);
	SListNodePrint(&pf);

	SListPushBack(&pf, 1);
	SListPushBack(&pf, 1);
	SListremoveAll(&pf, 1);
	SListNodePrint(&pf);

	//SListPushBack(&pf, 1);
	//pNode = SListFind(pf, 1);
	//SListInsert(&pf, pNode, 1000);
	//SListNodePrint(&pf);

	SListPushBack(&pf, 1);
	pNode = SListFind(pf, 1);
	SListErase(&pf, pNode);
	SListNodePrint(&pf);

	return 0;
}
