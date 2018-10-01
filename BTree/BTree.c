#include "BTree.h"

BTreeNode *CreateTree(char **str)
{
	assert(str);

	if(**str == 0)
		return NULL;
	if(**str == '#')
	{
		(*str)++;
		return NULL;
	}

	BTreeNode *pRoot = (BTreeNode *)malloc(sizeof(BTreeNode));
	pRoot->data = **str;
	(*str)++;
	pRoot->pLeft = CreateTree(str);
	pRoot->pRight = CreateTree(str);

	return pRoot;
}

void PreOrder(BTreeNode *pRoot)
{
	if(pRoot == NULL)
	{
		return;
	}

	printf("%c", pRoot->data);
	PreOrder(pRoot->pLeft);
	PreOrder(pRoot->pRight);
}

void InOrder(BTreeNode *pRoot)
{
	if(pRoot == NULL)
	{
		return;
	}

	InOrder(pRoot->pLeft);
	printf("%c", pRoot->data);
	InOrder(pRoot->pRight);
}

void PostOrder(BTreeNode *pRoot)
{
	if(pRoot == NULL)
	{
		return;
	}

	PostOrder(pRoot->pLeft);
	PostOrder(pRoot->pRight);
	printf("%c", pRoot->data);
}

int NodeSizeTravel(BTreeNode *pRoot, int n)//根节点时n等于0,可以计算总的结点个数
{
	if(pRoot == NULL)
		return n;

	n++;

	n = NodeSizeTravel(pRoot->pLeft, n);
	n = NodeSizeTravel(pRoot->pRight, n);

	return n;
}

int NodeSizeSubproblem(BTreeNode *pRoot)//结点个数
{
	if(pRoot == NULL)
		return 0;

	return NodeSizeSubproblem(pRoot->pLeft) + 
		NodeSizeSubproblem(pRoot->pRight) + 
		1;
}

int LeafSizeTravel(BTreeNode *pRoot, int n)
{
	if(pRoot == NULL)
		return 0;
}

int LeafSizeSubproblem(BTreeNode *pRoot)//叶子结点个数
{
	if(pRoot == NULL)
		return 0;
	
	if(pRoot->pLeft == NULL && pRoot->pRight)
		return 1;

	return LeafSizeSubproblem(pRoot->pLeft) + LeafSizeSubproblem(pRoot->pRight);
}

int GetKLevelSize(BTreeNode *pRoot, int k)//树的第K层的结点个数
{
	assert(k >= 1);

	if(pRoot == NULL)
		return 0;
	if(k == 1)
		return 1;

	return GetKLevelSize(pRoot->pLeft, k - 1) +
		GetKLevelSize(pRoot->pRight, k - 1);
}

BTreeNode *Find(BTreeNode *pRoot, DataType data)
{
	if(pRoot == NULL)
		return NULL;

	if(pRoot->data == data)
		return pRoot;

	BTreeNode *pFound = Find(pRoot->pLeft, data);
	if(pFound != NULL)
		return pFound;

	pFound = Find(pRoot->pRight, data);
	if(pFound == NULL)
		return pFound;
	else
		return NULL;
}

int GetHight(BTreeNode *pRoot)
{
	if(pRoot == NULL)
		return 0;
	if(pRoot->pLeft == NULL && pRoot->pRight == NULL)
		return 1;

	int m = GetHight(pRoot->pLeft);
	int n = GetHight(pRoot->pRight);

	return MAX(m, n) + 1;
}

//层序遍历
//void LevelOrder(BTreeNode *root)
//{
//	BTreeNode *node;
//	Queue q;
//	QueueInit(&q);
//
//	if(root == NULL)
//		return;
//
//	QueuePush(&q, root);//入队的是结点地址,不是结点指向的data
//	while(!QueueEmpty(&s))
//	{
//		node = QueueFront(&q);
//		QueuePop(&s);
//		printf("%s ", node->data);
//		if(node->pLeft != NULL)
//			QueuePush(&q, node->pLeft);
//		if(node->pRight != NULL)
//			QueuePush(&q, node->pRight);
//	}
//}
//
////判断是不是完全二叉树
//int IsFullTree(BTreeNode *root)
//{
//	BTreeNode *node;
//	Queue q;
//	QueueInit(&q);
//
//	if(root == NULL)
//	{
//		//空树是完全二叉树
//		return 1;
//	}
//
//	QueuePush(&q, root);
//	while(1)
//	{
//		node = QueueFront(&q);
//		QueuePop(&q);
//		if(node == NULL)
//			break;
//
//		QueuePush(&q, node->pLeft);
//		QueuePush(&q, node->pRight);
//	}
//
//	while(!QueueEmpty(&q))
//	{
//		node = QueueFront(&q);
//		QueuePop(&q);
//		if(node != NULL)//只要队列不为空,就是不完全的
//			return 0;
//	}
//
//	return 1;
//}
//
//
////非递归前中后序遍历二叉树
//
//void PreOrderLop(BTreeNode *root)
//{
//	BTreeNode *node = root;
//	BTreeNode *top;
//	Stack s;
//	s.top = 0;
//
//	while(node != NULL || s.top > 0)
//	{
//		while(node != NULL)
//		{
//			printf("%s ", node->data);
//			s.array[s.top++] = node;
//			node = node->pLeft;
//		}
//
//		//处理元素
//		//栈中的元素都没有被处理
//		top = s.array[s.top - 1];
//
//		s.top--;//出栈
//		
//		//处理右子树
//		node = top->pRight;
//	}
//}
//
//
//void InOrderLop(BTreeNode *root)
//{
//	BTreeNode *node = root;
//	BTreeNode *top;
//	Stack s;
//	s.top = 0;
//
//	while(node != NULL || s.top > 0)
//	{
//		while(node != NULL)
//		{
//			s.array[s.top++] = node;
//			node = node->pLeft;
//		}
//
//		//处理栈中元素
//		top = s.array[s.top - 1];
//		s.top--;
//		printf("%c ", top->data);
//		node = top->pRight;
//	}
//}
//
//
//
////后序
//void PostOrderLop(BTreeNode *root)
//{
//	while(node != NULL || s.top > 0)
//	{
//		while(node != NULL)
//		{
//			s.array[s.top++] = node;
//			node = node->pLeft;
//		}
//
//		//处理栈中元素
//		top = s.array[s.top - 1];
//		if(top->pright == NULL || top->pRight == past)
//		{
//			s.top--;
//			printf("%c ", top->data);
//			last = top;
//		}
//		else	
//			node = top->pRight;
//	}
//}
