#include "trans.h"

int main()
{
	TransNode *Tr;
	Impty key;
	key.Chinese = "你好";
	key.English = "hello";
	printf("%d\n", TransSearch(Tr, "hello"));
	printf("%d\n", TransInsert(&Tr, key));
	printf("%d\n", TransSearch(Tr, "hello"));
	return 0;
}
