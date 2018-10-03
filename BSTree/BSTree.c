#include "BSTree.h"

int BSTreeSearch(BSTreeNode *root, Key key)
{
	//递归
	if(root == NULL)
		return -1;
	if(root->key == key)
		return 1;
	if(root->key > key)
		return BSTreeSearch(root->left, key);
	else
		return BSTreeSearch(root->right, key);

	//非递归
	//BSTreeNode *Node = root;
	//while(Node)
	//{
	//	if(Node->key == key)
	//		return 1;
	//	else if(Node->key > key)
	//		Node = Node->left;
	//	else
	//		Node = Node->right;
	//}

	//return -1;
}

int BSTreeInsert(BSTreeNode **root, Key key)
{
	//递归
	if(*root == NULL)
	{
		BSTreeNode *NewNode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
		NewNode->left = NewNode->right = NULL;
		NewNode->key = key;
		*root = NewNode;
		return 1;
	}
	
	if((*root)->key == key)
		return -1;

	if((*root)->key > key)
		return BSTreeInsert(&(*root)->left, key);//注意改root,不能创建局部变量来修改
	else
		return BSTreeInsert(&(*root)->right, key);


	//非递归
	//BSTreeNode *Node = *root;
	//BSTreeNode *parent = NULL;

	//while(Node)
	//{
	//	if(Node->key == key)
	//		return -1;

	//	parent = Node;
	//	if(Node->key > key)
	//		Node = Node->left;
	//	else
	//		Node = Node->right;
	//}

	//BSTreeNode *NewNode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	//NewNode->key = key;
	//NewNode->left = NULL;
	//NewNode->right = NULL;

	//if(parent == NULL)//根节点为空
	//{
	//	*root = NewNode;
	//	return 1;
	//}

	//if(parent->key > key)
	//	parent->left = NewNode;
	//else
	//	parent->right = NewNode;
	//return 1;
}

int BSTreeDel(BSTreeNode **root, Key key)
{
	//递归
	if(*root == NULL)
		return -1;

	if(key < (*root)->key)
		return BSTreeDel(&(*root)->left, key);
	else
		return BSTreeDel(&(*root)->right, key);

	BSTreeNode *Node = *root;
	if((*root)->left == NULL)
	{
		*root = Node->right;
		free(Node);
	}
	else if((*root)->right == NULL)
	{
		*root = Node->left;
		free(Node);
	}
	else
	{//替换法,左子树最大
		BSTreeNode *del = Node->left;
		BSTreeNode *delParent = Node;
		while(del->right != NULL)
		{
			delParent = del;
			del = del->right;
		}
		Node->key = del->key;
		if(delParent == Node)
			delParent->left = del->right;
		else
			delParent->right = del->right;
		free(del);
	}
	return 0;

	//非递归
	//BSTreeNode *Node = *root;
	//BSTreeNode *parent = NULL;
	//while(Node)
	//{
	//	if(Node->key == key)
	//	{
	//		//删除
	//		if(Node->left == NULL)
	//		{
	//			if(parent == NULL)
	//			{
	//				*root = Node->right;
	//				free(Node);
	//				return 1;
	//			}

	//			if(parent->left == NULL)
	//				parent->right = Node->right;
	//			else
	//				parent->left = Node->right;
	//			free(Node);
	//			return 1;
	//		}
	//		else if(Node->right == NULL)
	//		{
	//			if(parent == NULL)
	//			{
	//				*root = Node->left;
	//				free(Node);
	//				return 1;
	//			}

	//			if(parent->right == NULL)
	//				parent->left = Node->left;
	//			else
	//				parent->right = Node->left;
	//			free(Node);
	//			return 1;
	//		}
	//		else//左右都不为空,替换法,右子树中最小的
	//		{
	//			BSTreeNode *del = Node->right;
	//			BSTreeNode *delParent = Node;
	//			while(del->left != NULL)
	//			{
	//				delParent = del;
	//				del = del->left;
	//			}

	//			Node->key = del->key;

	//			if(delParent == Node)
	//				delParent->right = del->right;
	//			else
	//				delParent->left = del->right;
	//			free(del);
	//		}
	//	}

	//	parent = Node;
	//	else if(Node->key > key)
	//		Node = Node->left;
	//	else
	//		Node = Node->right;
	//}

	//return -1;
}




