#include "sort.h"

int main()
{
	std::vector<int> vec;
	srand((unsigned int)time(NULL));

	for(int i = 0; i < 1000000; i++) {
		vec.push_back(rand());
	}

	//int array[] = {10, 5, 4, 1, 3, 2, 9, 6, 8};
	//int size = sizeof(array) / sizeof(array[0]);
	//std::vector<int> vec(array, array+sizeof(array)/sizeof(array[0]));
	
	clock_t start = clock();
	//mergeSort(vec);
	//insertSort(vec);
	//shellSort(vec);
	bubbleSort(vec);
	//heapSort(array, 10);
	//selectSort(vec);
	//quickSort(vec);
	clock_t end = clock();

	std::cout << "bubbleSort : " << end-start << std::endl;

	return 0;
}
