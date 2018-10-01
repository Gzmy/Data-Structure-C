#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef char DataType;

#define MAX(m, n) ((m) > (n) ? (m) : (n))

typedef struct BTreeNode
{
	DataType data;
	struct BTreeNode *pLeft;
	struct BTreeNode *pRight;
}BTreeNode;


//typedef void * DataType;
//typedef struct Node
//{
//	DataType data;
//	struct Node *Next;
//
//}







BTreeNode *CreateTree(char **str);//创建一个二叉树
void PreOrder(BTreeNode *pRoot);//先序输出二叉树
void InOrder(BTreeNode *pRoot);//中序输出二叉树
void PostOrder(BTreeNode *pRoot);//后序输出二叉树
int NodeSizeTravel(BTreeNode *pRoot, int n);//
int NodeSizeSubproblem(BTreeNode *pRoot);
int LeafSizeTravel(BTreeNode *pRoot, int n);
int LeafSizeSubproblem(BTreeNode *pRoot);
int GetKLevelSize(BTreeNode *pRoot, int k);//树的第k层结点个数
BTreeNode *Find(BTreeNode *pRoot, DataType data);//查找第一个遇到的data结点,找到返回地址,找不到返回NULL
int GetHight(BTreeNode *pRoot);//树的高度
