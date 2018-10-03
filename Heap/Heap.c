#include "Heap.h"

void HeapAdjustDown(int array[], size_t size, size_t root)
{
	size_t Big;

	while(1)
	{
		size_t left = root*2 + 1;
		size_t right = root*2 + 2;
		if(left >= size)//越界
			return;

		if(right >= size || array[left] >= array[right])//只有左或者左大于右
			Big = left;
		else
			Big = right;

		if(array[root] >= array[Big])
			return;
		else
		{
			int tmp = array[root];
			array[root] = array[Big];
			array[Big] = tmp;
		}
		root = Big;
	}
}

void HeapAdjustUp(int array[], size_t size, size_t child)
{
	while(1)
	{
		if(child == 0)
			return;

		size_t parent = (child-1)/2;

		if(array[parent] >= array[child])
			return;

		int tmp = array[parent];
		array[parent] = array[child];
		array[child] = tmp;

		child = parent;
	}
}

void CreatHeap(int array[], size_t size)
{
	int i;
	for(i = (size-2)/2; i >= 0; i--)
	{
		HeapAdjustDown(array, size, i);
	}
}

void HeapInit(Heap *ph, int array[], int size)
{
	assert(ph && size <= MAX_SIZE);
	ph->size = size;
	memcpy(ph->array, array, size*sizeof(int));
	CreatHeap(ph->array, ph->size);
}

void HeapInsert(Heap *ph, int data)
{
	assert(ph);
	if(ph->size == MAX_SIZE)
	{
		printf("表满\n");
		return;
	}
	ph->array[ph->size] = data;
	ph->size++;
	HeapAdjustUp(ph->array, ph->size, ph->size-1);
}

void HeapRemove(Heap *ph)
{
	assert(ph);
	ph->array[0] = ph->array[ph->size - 1];
	ph->size--;

	HeapAdjustDown(ph->array, ph->size, 0);
}

int HeapTop(Heap *ph)
{
	assert(ph);
	return ph->array[0];
}
