#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *Chinese;
	char *English;
} Impty;

typedef struct TransNode
{
	Impty key;
	struct TransNode *left;
	struct TransNode *right;
} TransNode;

int TransSearch(TransNode *root, char *English);
int TransInsert(TransNode **root, Impty key);
