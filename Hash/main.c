#include "Hash.h"

int main()
{
	HashOpen pO;
	HashOpenInit(&pO, 7, mod);
	printf("%d\n", HashOpenInsert(&pO, 0));
	printf("%d\n", HashOpenInsert(&pO, 1));
	printf("%d\n", HashOpenInsert(&pO, 3));
	printf("%d\n", HashOpenInsert(&pO, 6));
	printf("%d\n", HashOpenInsert(&pO, 11));

	printf("%d\n", HashOpenRemove(&pO, 5));
	printf("%d\n", HashOpenRemove(&pO, 6));

	printf("%d\n", HashOpenSearch(&pO, 17));
	printf("%d\n", HashOpenSearch(&pO, 6));
	printf("%d\n", HashOpenSearch(&pO, 11));

	//HashTable ht;
	//HashTableInit(&ht, 7, mod);

	//printf("%d\n", HashInsert(&ht, 0));
	//printf("%d\n", HashInsert(&ht, 1));
	//printf("%d\n", HashInsert(&ht, 7));
	//printf("%d\n", HashInsert(&ht, 4));
	//printf("%d\n", HashInsert(&ht, 5));

	//printf("%d\n", HashRemove(&ht, 5));
	//printf("%d\n", HashRemove(&ht, 10));
	//printf("%d\n", HashRemove(&ht, 0));
	return 0;
}
