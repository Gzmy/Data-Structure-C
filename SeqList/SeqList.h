#pragma once
//静态顺序表操作
#define MAX_SIZE 1000
#include <stdio.h>
#include <assert.h>

typedef int DataType;

typedef struct SeqList
{
	DataType array[MAX_SIZE];
	int size;
}SeqList;

//SeqList s;
void SeqPrint(SeqList *pSL);//打印顺序表
void SeqListinit(SeqList *pSL);//初始化
void SeqListPushBack(SeqList *pSL, DataType data);//尾部插入
void SeqListPushFront(SeqList *pSL, DataType data);//头插
void SeqListInsert(SeqList *pSL, int pos, DataType data);//指定处插入,此处pos是逻辑顺序
void SeqListPopBack(SeqList *pSL);//尾删
void SeqListPopFront(SeqList *pSL);//头删
void SeqListErase(SeqList *pSL, int pos);//按下标删除
void SeqListRemove(SeqList *pSL, DataType data);//删除第一个遇到的值
void SeqListRemoveAll(SeqList *pSL, DataType data);//删除所有值
void SeqListClear(SeqList *pSL);
int SeqListFind(SeqList *pSL, DataType data);//返回下标
int SeqListEmpty(SeqList *pSL);//是否为空表
int SeqListSize(SeqList *pSL);//返回表的大小
void SeqListSort(SeqList *pSL);//选择排序




