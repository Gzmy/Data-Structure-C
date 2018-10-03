#include "BSTree.h"

int main()
{
	BSTreeNode *b;
	printf("%d\n", BSTreeInsert(&b, 0));
	printf("%d\n", BSTreeInsert(&b, 1));
	printf("%d\n", BSTreeInsert(&b, 4));
	printf("%d\n", BSTreeInsert(&b, 6));
	printf("%d\n", BSTreeInsert(&b, 3));
	return 0;
}
