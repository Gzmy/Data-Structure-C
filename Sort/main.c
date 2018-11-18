#include "Sort.h"

int main()
{
    int i = 0;
    int array[] = {1, 232, 324, 4234, 1, 233};
    int len = sizeof(array)/sizeof(array[0]);

    //Insertsort(array, len);
    //Shellsort(array, len);
    //Selectsort(array, len);
    //Selectsort_op(array, len);
    //Heapsort(array, len);
    //Bubblesort(array, len);
    //Quicksort(array, 0, len);
    Mergesort(array, len);
    for(; i < len; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
