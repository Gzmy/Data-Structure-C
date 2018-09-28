#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DataType;

typedef struct SListNode
{
	struct SListNode *pNext;
	DataType data;
}SListNode;

void SListInit(SListNode **pFirst);
void SListPushBack(SListNode **pFirst, DataType data);
void SListNodePrint(SListNode **pFirst);
void ReversePrint(SListNode *pFirst);//倒叙打印单链表
SListNode *ReverseList(SListNode *pFirst);//逆置单链表
void RemoveNodeNotTail(SListNode *pos);//删除非尾无头链表
void InsertNoHead(SListNode *pos, int data);//无头链表前插入
SListNode *JocephCircle(SListNode *pFirst, int k);//约瑟夫环
void BubbleSort(SListNode *pFirst);//冒泡排序,不改变链表顺序,直交换数据
SListNode *MergeOrderedList(SListNode *p1First, SListNode *p2First);//合并两个有序链表
SListNode *FindMid(SListNode *pFirst);//遍历一次找到中间结点
SListNode *FindK(SListNode *pFirst, int k);//遍历一次,找到倒数第k个结点(k从1开始)
void RemoveK(SListNode *pFirst, int k);//遍历一次,删除倒数第k个结点(k从1开始)
