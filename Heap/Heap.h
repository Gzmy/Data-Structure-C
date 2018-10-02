#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define MAX_SIZE 100

typedef struct Heap
{
	int array[MAX_SIZE];
	int size;
} Heap;

void HeapAdjustDown(int array[], size_t size, size_t root);
void HeapAdjustUp(int array[], size_t size, size_t child);
void CreatHeap(int array[], size_t size);
void HeapInit(Heap *ph, int array[], int size);
void HeapInsert(Heap *ph, int data);
void HeapRemove(Heap *ph);
int  HeapTop(Heap *ph);
