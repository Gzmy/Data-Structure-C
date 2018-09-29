#include"Stack.h"

void StackPrint(Stack *s)
{
	int i = 0;
	for(i; i < s->top; i++)
	{
		printf("%d", s->array[i]);
	}
	printf("\n");
}

void StackInit(Stack *s)
{
	assert(s);
	s->top = 0;
}

void StackPush(Stack *s, DataType data)
{
	assert(s);
	if(s->top == MAX_SIZE)
	{
		printf("Stack is full\n");
		return;
	}

	s->array[s->top] = data;
	s->top++;
}

int StackEmpty(Stack *s)
{
	assert(s);

	return 0 == s->top;
}

void StackPop(Stack *s)
{
	assert(s);
	if(StackEmpty(s))
	{
		printf("Stack is full\n");
		return;
	}

	s->top--;
}

DataType StackTop(Stack *s)
{
	assert(s);

	return s->array[s->top-1];
}

int StackSize(Stack *s)
{
	assert(s);

	return s->top;
}

int IsEmpty(Stack *s)
{
	assert(s);

	return 0 == s->top;
}

