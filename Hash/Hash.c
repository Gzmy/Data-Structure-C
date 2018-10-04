#include "Hash.h"

//闭散列
void HashTableInit(HashTable *pHT, size_t capacity, HashFuncType hash)
{
	pHT->array = (ItemType *)malloc(sizeof(ItemType) * capacity);
	pHT->capacity = capacity;
	pHT->size = 0;
	int i;
	for(i = 0; i < capacity; i++)
	{
		pHT->array[i].state = EMPTY;
	}
	pHT->hash = hash;
}

size_t mod(KeyType key, size_t capacity)
{
	return key % capacity;
}

void HashTableDestroy(HashTable *pHT)
{
	free(pHT->array);
	pHT->size = 0;
	pHT->capacity = 0;
	pHT->hash = NULL;
}

size_t HashSearch(HashTable *pHT, KeyType key)
{
	size_t index = mod(key, pHT->capacity);
	while(1)
	{
		if(pHT->array[index].state == EMPTY)
			return 0;//没找到
		if(pHT->array[index].key == key && pHT->array[index].state == EXIST)
			return index;

		//线性探测
		index = (index+1) % pHT->capacity;
		//二次探测
		//index = (index * index) % pHT->capacity; 
	}
}

size_t HashRemove(HashTable *pHT, KeyType key)
{
	size_t index = mod(key, pHT->capacity);
	while(1)
	{
		if(pHT->array[index].state == EMPTY)
			return 0;
		if(pHT->array[index].key == key && pHT->array[index].state == EXIST)
		{
			pHT->array[index].state = DELETE;
			pHT->size--;
			return index;
		}

		index = (index + 1) % pHT->capacity;
	}
}

static void ExpandIfRequired(HashTable *pHT)
{
	if(pHT->size * 10/ pHT->capacity < 8)//所占空间比例达到百分之八十不扩容
		return;

	int i;
	HashTable tmp;
	HashTableInit(&tmp, pHT->capacity*2, pHT->hash);
	for(i = 0; i < pHT->capacity; i++)//遍历整个pHT
	{
		if(pHT->array[i].state == EXIST)
			HashInsert(&tmp, pHT->array[i].key);
	}

	free(pHT->array);//释放掉原来pHT的array
	pHT->array = tmp.array;//将tmp的array挂载到pHT上
	pHT->capacity = tmp.capacity;//pHT的总大小发生变化
	//pHT的size和hash和原来保持一致
	//tmp函数调用栈结束自动释放
}

int HashInsert(HashTable *pHT, KeyType key)
{
	if(HashSearch(pHT, key) != 0)
		return 0;//哈希表中有已经有相同元素

	ExpandIfRequired(pHT);

	size_t index = mod(key, pHT->capacity);
	while(1)
	{
		if(pHT->array[index].state != EXIST)
			break;

		index = (index + 1) % pHT->capacity;
	}

	pHT->array[index].key = key;
	pHT->array[index].state = EXIST;
	pHT->size++;

	return index;
}

//闭散列

void HashOpenInit(HashOpen *pO, size_t capacity, HashFuncType hash)
{
	pO->buf = (SListNode **)malloc(sizeof(SListNode *) * capacity);
	pO->size = 0;
	pO->capacity = capacity;
	pO->hash = hash;

	//初始化数组
	memset(pO->buf, 0, sizeof(SListNode *) * capacity);
}

static void SListNodeRemove(SListNode **pfirst)
{
	SListNode *Node, *Del;
	for(Node = *pfirst; Node != NULL;)
	{
		Del = Node;
		Node = Node->pNext;
		free(Del);
	}
}

void HashOpenDestroy(HashOpen *pO)
{
	int i;
	for(i = 0; i < pO->capacity; i++)
	{
		SListNodeRemove(pO->buf + i);
	}
	
	free(pO->buf);
}

int HashOpenSearch(HashOpen *pO, KeyType key)
{
	size_t index = mod(key, pO->capacity);
	SListNode *Node = NULL;

	for(Node = pO->buf[index]; Node != NULL; Node = Node->pNext)
	{
		if(Node->key == key)
			return 0;
	}

	return -1;
}

int HashOpenRemove(HashOpen *pO, KeyType key)
{
	size_t index = mod(key, pO->capacity);
	SListNode *Node = NULL;
	SListNode *par = NULL;
	SListNode **cur = pO->buf+index;

	for(Node = pO->buf[index]; Node != NULL; Node = Node->pNext)
	{
		//二级指针
		if(Node->key == key)
		{
			(*cur)->pNext = Node->pNext;
			pO->size++;
			free(Node);
			return 0;
		}
		cur = &(Node->pNext);
	}
	//for(Node = pO->buf[index]; Node != NULL; Node = Node->pNext)
	//{
	//	if(Node->key == key)
	//	{
	//		if(par == NULL)
	//		{
	//			pO->buf[index] = Node->pNext;
	//		}
	//		else
	//		{
	//			par->pNext = Node->pNext;
	//		}

	//		free(Node);
	//		pO->size++;
	//		return 0;
	//	}

	//	par = Node;
	//}

	return -1;
}

static void ExpandIfRequiredOpen(HashOpen *pO)
{
	if(pO->size * 10/ pO->capacity < 8)
		return;

	HashOpen tmp;
	HashOpenInit(&tmp, pO->capacity * 2, mod);

	size_t i;
	for(i = 0; i < pO->capacity; i++)
	{
		SListNode *Node;
		for(Node = pO->buf[i]; Node != NULL; Node = Node->pNext)
			HashOpenInsert(&tmp, Node->key);
	}

	free(pO->buf);
	pO->buf = tmp.buf;
	pO->capacity = tmp.capacity;
}

int HashOpenInsert(HashOpen *pO, KeyType key)
{
	ExpandIfRequiredOpen(pO);
	size_t index = mod(key, pO->capacity);
	if(!HashOpenSearch(pO, key))
		return -1;
	
	SListNode *NewNode = (SListNode *)malloc(sizeof(SListNode));
	NewNode->key = key;
	NewNode->pNext = pO->buf[index];
	pO->buf[index] = NewNode;
	pO->size++;
	return 0;
}

