#include"SeqList.h"

int main()
{
	SeqList s;
	SeqListinit(&s);

	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqPrint(&s);
	SeqListPushFront(&s, 101);
	SeqListPushFront(&s, 102);
	SeqListPushFront(&s, 103);
	SeqListPushFront(&s, 104);
	SeqPrint(&s);
	SeqListInsert(&s, 2, 110);
	SeqPrint(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqPrint(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqPrint(&s);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqPrint(&s);
	SeqListErase(&s, 2);
	SeqPrint(&s);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqPrint(&s);
	SeqListRemove(&s, 3);	
	SeqPrint(&s);
	SeqListRemoveAll(&s, 2);
	SeqPrint(&s);

	return 0;
}
