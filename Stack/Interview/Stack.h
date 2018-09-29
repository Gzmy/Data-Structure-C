#pragma once
//栈操作,顺序表
#include <assert.h>
#include <stdio.h>

#define MAX_SIZE 100
typedef int DataType;
//typedef char DataType;

typedef struct Stack
{
	DataType array[MAX_SIZE];
	int top;
}Stack;


void StackPrint(Stack *s);//打印
void StackInit(Stack *s);//初始化
void StackPush(Stack *s, DataType data);//进栈
int StackEmpty(Stack *s);//判断是否为空
void StackPop(Stack *s);//出栈
DataType StackTop(Stack *s);//返回栈顶元素
int StackSize(Stack *s);//返回栈的数据个数
int IsEmpty(Stack *s);//是否为空

