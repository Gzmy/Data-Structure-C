#include "trans.h"

int TransSearch(TransNode *root, char *English)
{
	//if(root == NULL)
	//	return -1;
	//TransNode *Node = root;
	//while(Node)
	//{
	//	if(strcmp(English, Node->key.English) == 0)
	//		return 0;
	//	if(strcmp(English, Node->key.English) > 0)
	//		Node = Node->right;
	//	else
	//		Node = Node->left;
	//}
	//return -1;
	
	if(root == NULL)
		return -1;
	if(strcmp(English, root->key.English) == 0)
		return 0;
	if(strcmp(English, root->key.English) > 0)
		return TransSearch(root->right, English);
	else
		return TransSearch(root->left, English);
}

int TransInsert(TransNode **root, Impty key)
{
	TransNode *Node = *root;
	TransNode *par = NULL;
	
	while(Node)
	{
		if(strcmp(Node->key.English, key.English) == 0)
			return -1;

		par = Node;
		if(strcmp(Node->key.English, key.English) > 0)
			Node = Node->left;
		else
			Node = Node->right;
	}

	TransNode *NewNode = (TransNode *)malloc(sizeof(TransNode));
	NewNode->key = key;
	NewNode->left = NewNode->right = NULL;

	if(par == NULL)
	{
		*root = NewNode;
		return 0;
	}

	if(strcmp(par->key.English, key.English) > 0)
		par->left = NewNode;
	else
		par->right = NewNode;
	return 0;
	//if(*root == NULL)
	//{
	//	TransNode *NewNode = (TransNode *)malloc(sizeof(TransNode));
	//	NewNode->key = key;
	//	NewNode->left = NewNode->right = NULL;
	//	*root = NewNode;
	//	return 0;
	//}

	//if(strcmp((*root)->key.English, key.English) == 0)
	//	return -1;
	//if(strcmp((*root)->key.English, key.English) > 0)
	//	TransInsert(&(*root)->left, key);
	//else
	//	TransInsert(&(*root)->right, key);
}

