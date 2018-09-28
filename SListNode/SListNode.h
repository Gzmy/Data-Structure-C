#pragma once
//单向无头不循环单链表

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef int DataType;

typedef struct SListNode
{
	struct SListNode *pNext;
	DataType data;
} SListNode;


SListNode *__CreatNewNode(DataType data);//申请空间存放新链表
void SListNodePrint(SListNode **ppfirst);//打印
void SListInit(SListNode **ppfirst);//初始化
void SListPushBack(SListNode **ppfirst, DataType data);//尾插
void SListPushFront(SListNode **ppfirst, DataType data);//头插
void SListPopBack(SListNode **ppfirst);//尾删
void SListPopFront(SListNode **ppfirst);//头删
SListNode *SListFind(SListNode *ppfirst, DataType data);//依照数据找结点
void SListInsert(SListNode **ppfirst, SListNode *pos, DataType data);//按给定结点插入
void SListErase(SListNode **ppfirst, SListNode *pos);//给定结点删除
void SListRemove(SListNode **ppfirst, DataType data);//按值删除
void SListremoveAll(SListNode **ppfirst, DataType data);//按值删所有
void SListDestroy(SListNode **ppfirst);//销毁


