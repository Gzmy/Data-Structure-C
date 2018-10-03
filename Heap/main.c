#include "Heap.h"

int main()
{
	Heap pH;
	int array[] = {53, 17, 78, 9, 45, 65, 87, 23, 31};
	int len = sizeof(array)/sizeof(array[0]);

	HeapInit(&pH, array, len);
	printf("%d\n", HeapTop(&pH));

	HeapRemove(&pH);
	printf("%d\n", HeapTop(&pH));

	HeapInsert(&pH, 100);
	printf("%d\n", HeapTop(&pH));
	return 0;
}
