#include "Heap.h"

void HeapAdjustDown(int array[], size_t size, size_t root)
{
    size_t big;
    while(1){
        size_t left = root*2 + 1;
        size_t right = root*2 + 2;

        if(left >= size){
            return;
        }

        if(right >= size || array[left] >= array[right]){
            big = left;
        }else{
            big = right;
        }

        if(array[root] >= array[big]){
            return;
        }else{
            int tmp = array[root];
            array[root] = array[big];
            array[big] = tmp;
        }

        root = big;
    }
}

void HeapAdjustUp(int array[], size_t size, size_t child)
{
    while(1){
        if(child == 0){
            return;
        }

        size_t parent = (child-1)/2;

        if(array[child] <= array[parent]){
            continue;
        }

        int tmp = array[child];
        array[child] = array[parent];
        array[parent] = tmp;

        child = parent;
    }
}

void CreatHeap(int array[], size_t size)
{
    int i;
    for(i = (size-2)/2; i >= 0; i--){
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
    if(ph->size == MAX_SIZE){
        printf("Heap is full");
        return;
    }

    ph->array[ph->size] = data;
    ph->size++;
    HeapAdjustUp(ph->array, ph->size, ph->size-1);
}

void HeapRemove(Heap *ph)
{
    assert(ph);
    ph->array[0] = ph->array[ph->size-1];
    ph->size--;

    HeapAdjustDown(ph->array, ph->size, 0);
}

int  HeapTop(Heap *ph)
{
    return ph->array[0];
}

