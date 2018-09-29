#include "Interview.h"

int main()
{
	//MinStack ms;
	//MDataType tmp;

	//MinStackInit(&ms);

	//MinStackPush(&ms, 2);
	//MinStackPush(&ms, 4);
	//MinStackPush(&ms, 3);
	//MinStackPush(&ms, 1);
	//MinStackPush(&ms, 5);
	//MinStackPrint(&ms);

	//tmp = MinStackMin(&ms);
	//printf("MinData = %d\n", tmp);

	//tmp = MinStackTop(&ms);
	//printf("TopData = %d\n", tmp);
	
	//TStackToQueue ss;
	//TQDataType tmp;
	//TStackToQueueInit(&ss);
	//
	//TStackToQueuePush(&ss, 0);
	//TStackToQueuePush(&ss, 1);
	//TStackToQueuePush(&ss, 2);
	//TStackToQueuePush(&ss, 3);
	//TStackToQueuePush(&ss, 4);
	//TStackToQueuePush(&ss, 5);
	//TStackToQueuePrint(&ss);

	//TStackToQueuePop(&ss);
	//TStackToQueuePush(&ss, 6);
	//TStackToQueuePrint(&ss);

	//tmp = TStackToQueueTop(&ss);
	//printf("%d\n", tmp);

	//tmp = TStackToQueueTail(&ss);
	//printf("%d\n", tmp);
	
	//TQueueToStack qq;
	//TSDataType tmp;
	//
	//TQueueToStackInit(&qq);
	//TQueueToStackPush(&qq, 0);
	//TQueueToStackPush(&qq, 1);
	//TQueueToStackPush(&qq, 2);
	//TQueueToStackPush(&qq, 3);
	//TQueueToStackPush(&qq, 4);
	//TQueueToStackPush(&qq, 5);
	//TQueueToStackPrint(&qq);

	//TQueueToStackPop(&qq);
	//TQueueToStackPrint(&qq);

	//tmp = TQueueToStackTop(&qq);
	//printf("%d\n", tmp);

	//tmp = TQueueToStackTail(&qq);
	//printf("%d\n", tmp);

	//int i;
	//int in[5] = {1, 2, 3, 4, 5};
	//int out[5] = {3, 4, 2, 5, 1};
	//i = InOutIsVaild(in, out, 5);
	//printf("%d\n", i);
	
	ShareStack ss;
	ShareStackInit(&ss);
	ShareStackPush(&ss, 0, 0);
	ShareStackPush(&ss, 1, 0);
	ShareStackPush(&ss, 2, 0);
	ShareStackPush(&ss, 3, 0);
	ShareStackPush(&ss, 4, 0);
	ShareStackPush(&ss, 4, 1);
	ShareStackPush(&ss, 3, 1);
	ShareStackPush(&ss, 2, 1);
	ShareStackPush(&ss, 1, 1);
	ShareStackPush(&ss, 0, 1);
	ShareStackPrint(&ss);

	ShareStackPop(&ss, 0);
	ShareStackPop(&ss, 1);
	ShareStackPop(&ss, 1);
	ShareStackPrint(&ss);

	int tmp;
	tmp = ShareStackEmpty(&ss);
	printf("Empty %d\n", tmp);

	tmp = ShareStackTop(&ss, 0);
	printf("top1 = %d\n", tmp);

	tmp = ShareStackTop(&ss, 1);
	printf("top2 = %d\n", tmp);

	tmp = ShareStackSize(&ss);
	printf("StackSize = %d\n", tmp);
	return 0;
}
