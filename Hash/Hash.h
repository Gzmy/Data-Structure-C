//毕散列的哈希表不能直接删除,标记状态将其删除
//哈希表是不会满的

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int KeyType;

typedef size_t(*HashFuncType)(KeyType key, size_t capacity);//函数指针
//C语言不支持下面这种写法
//typedef size-t(*)(KeyType key, size_t capacity) HashFunType;

typedef enum State
{
	EMPTY,//空
	EXIST,//已占用
	DELETE//已删除
} State;

typedef struct ItemType
{
	KeyType key;
	State state;
} ItemType;

typedef struct HashTable
{
	ItemType *array;
	size_t size;
	size_t capacity;
	HashFuncType hash;
} HashTable;

typedef struct SListNode
{
	KeyType key;
	struct SListNode *pNext;
} SListNode;

typedef struct 
{
	SListNode **buf;
	size_t size;//实际大小
	size_t capacity;//容量
	HashFuncType hash;
} HashOpen;

//闭散列
void HashTableInit(HashTable *pHT, size_t capacity, HashFuncType hash);
size_t mod(KeyType key, size_t capacity);
void HashTableDestroy(HashTable *pHT);
size_t HashSearch(HashTable *pHT, KeyType key);
size_t HashRemove(HashTable *pHT, KeyType key);
int HashInsert(HashTable *pHT, KeyType key);

//开散列
void HashOpenInit(HashOpen *pO, size_t capacity, HashFuncType hash);
void HashOpenDestroy(HashOpen *pO);
int HashOpenSearch(HashOpen *pO, KeyType key);
int HashOpenRemove(HashOpen *pO, KeyType key);
int HashOpenInsert(HashOpen *pO, KeyType key);
