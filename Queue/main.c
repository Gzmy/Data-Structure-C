/*hello user*/
#include "Queue.h"

int main()
{
	Queue q;
	int i;

	QueueInit(&q);

	QueuePush(&q, 0);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePrint(&q);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q);

	i = QueueIsEmpty(&q);
	printf("%d\n", i);

	i = QueueSize(&q);
	printf("%d\n", i);
	
	return 0;
}
