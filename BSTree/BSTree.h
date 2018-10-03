#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int Key;

typedef struct BSTreeNode
{
	Key key;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
} BSTreeNode;

int BSTreeSearch(BSTreeNode *root, Key key);
int BSTreeInsert(BSTreeNode **root, Key key);
int BSTreeDel(BSTreeNode **root, Key key);
