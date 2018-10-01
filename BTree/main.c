/*hello user*/
#include "BTree.h"

int main()
{
	char *s = "ABD###CE##F";
	BTreeNode *pRoot = CreateTree(&s);

	PreOrder(pRoot);
	printf("\n");
	InOrder(pRoot);
	printf("\n");
	PostOrder(pRoot);
	printf("\n");

	return 0;
}
