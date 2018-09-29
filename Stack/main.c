#include "Stack.h"

int main()
{
	Stack s;

	StackInit(&s);
	StackPush(&s, 0);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPrint(&s);

	StackPop(&s);
	StackPrint(&s);
	return 0;
}

