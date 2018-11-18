#include "Sort.h"

//插入排序
void Insertsort(int array[], int size)
{
    int i = 1;
    for(; i < size; i++){
        int key = array[i]; //i是待插入的
        int end = i - 1;    //前面的元素是排好序的

        while(end >= 0 && key < array[end]){
            array[end+1] = array[end];
            end--;
        }
        array[end+1] = key;
    }
}

//二分查找
void InsertsortBinarySearch(int *array, int size)
{
    int i, j;
    int key;

    for(i = 1; i < size; i++){
        key = array[i];

        size_t left = 0, right = 1;
        while(left < right){
            size_t mid = left + (right-left)/2;
            if(key < array[mid]){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }

        for(j = i; j > left; j--){
            array[j] = array[j-1];
        }
        array[left] = key;
    }
}

//希尔排序
//gap /= 2
//gap 奇数
//gap 素数
//gap = gap/3 + 1;*****效果较好
void Shellsort(int array[], int size)
{
    int gap = size;
    while(gap > 1){
        gap = gap/3 + 1;
        int i = gap;
        for(; i < size; i++){
            int key = array[i];
            int end = i - gap;
            while(end >= 0 && key < array[end]){
                array[end+gap] = array[end];
                end -= gap;
            }
            array[end+gap] = key; 
        }
        //gap--;
    }
}

//选择排序

static void Swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void Selectsort(int array[], int size)
{
    int i = 0;
    for(; i < size-1; i++){
        int j = 1;
        int maxPos = 0;
        for(; j < size-i; j++){
            if(array[j] > array[maxPos]){
                maxPos = j;
            }
        }

        if(maxPos == size-i-1){
            continue;
        }
        Swap(&array[size-1-i], &array[maxPos]);
    }
}

//优化，一次性找最大最小
void Selectsort_op(int *array, int size)
{
    int begin = 0, end = size-1;
    while(begin < end){
        int minPos = begin;
        int maxPos = begin;

        //找最大最小元素的位置
        int i = begin + 1;
        while(i <= end){
            if(array[i] > array[maxPos]){
                maxPos = i;
            }
            else if(array[i] < array[minPos]){
                minPos = i;
            }
            i++;
        }
        if(maxPos != end){
            Swap(&array[maxPos], &array[end]);
        }
        //最小元素在end位置，重新标记minPos
        if(minPos == end){
            minPos = maxPos;
        }
        if(minPos != begin){
            Swap(&array[minPos], &array[begin]);
        }

        begin++, end--;
    }
}

//堆排序

//向下调整
static void HeapAdjust(int *array, int size, int par)
{
    //child默认，标记左孩子
    int child = (par << 1) + 1;

    while(child < size){
        //找左右中最大的，child标记
        if(child+1 < size && array[child] < array[child+1]){
            child += 1;
        }

        //检测最大的孩子是否比双亲大
        if(array[child] > array[par]){
            Swap(&array[child], &array[par]);
            par = child;
            child = (par << 1) + 1;
        }
        else{
            return;
        }
    }
}

void Heapsort(int *array, int size)
{
    //1、建堆 -- 升序：大堆， 降序：小堆
    int root = ((size-2)>>1);
    for(; root >= 0; root--){
        HeapAdjust(array, size, root); //建堆
    }
    //2、排序--删除
    int end = size-1;
    while(end){
        Swap(&array[0], &array[end]);
        HeapAdjust(array, end, 0);
        end--;
    }
}

//冒泡排序
void Bubblesort(int array[], int size)
{
    int i, j;
    for(i = 0; i < size - 1; i++){
        int isChange = 0;
        for(j = 0; j < size-i-1; j++){
            if(array[j] > array[j+1]){
                isChange = 1;
                Swap(array+j, array+j+1);
            }
        }
        if(!isChange){
            return;
        }
    }
}

//快排

static int partion1(int *array, int left, int right)
{
    //找基准值
    int key = array[right-1];
    int begin = left, end = right - 1;

    while(begin < end){
        //从左向右走找比基准值大的元素
        while(begin < end && array[begin] <= key){
            begin++;
        }
        //从右往左走找比基准值小的元素
        while(begin < end && array[end] >= key){
            end--;
        }

        if(begin < end){
            Swap(array+begin, array+end);
        }
    }

    if(begin != right-1)
        Swap(array+begin, array+right-1);
    return begin;
}

static partion2(int *array, int left, int right)
{
    int key = array[right-1];
    int begin = left, end = right-1;

    while(begin < end){
        while(begin < end && array[begin] <= key){
            begin++;
        }

        if(begin < end){
            array[end] = array[begin];
            end--;
        }

        while(begin < end && array[end] >= key){
            end--;
        }

        if(begin < end){
            array[begin] = array[end];
            begin++;
        }
    }
    array[begin] = key;
    return begin;
}

void Quicksort(int *array, int left, int right)
{
    //左闭右开区间
    if(right - left > 1){
        int mid = partion2(array, left, right);
        Quicksort(array, left, mid);
        Quicksort(array, mid+1, right);
    }
}


//归并排序

void Merge(int *array, int left, int mid, int right, int extra[])
{
    int left_index = left;
    int right_index = mid;
    int extra_index = left;

    while(left_index < mid && right_index < right){
        if(array[left_index] <= array[right_index]){
            extra[extra_index++] = array[left_index++];
        }
        else{
            extra[extra_index++] = array[right_index++];
        }
    }

    while(left_index < mid){
        extra[extra_index++] = array[left_index++];
    }
    while(right_index < right){
        extra[extra_index++] = array[right_index++];
    }
    int i = 0;
    for(i = left; i < right; i++){
        array[i] = extra[i];
    }
}

void __Mergesort(int array[], int left, int right, int extra[])
{
    if(left + 1 == right){
        return;
    }
    if(left >= right){
        return;
    }

    int mid = left + (right-left)/2;
    __Mergesort(array, left, mid, extra);
    __Mergesort(array, mid, right, extra);

    Merge(array, left, mid, right, extra);
}

void Mergesort(int array[], int size)
{
    int *extra = (int *)malloc(sizeof(int) * size);
    __Mergesort(array, 0, size, extra);
    free(extra);
}
