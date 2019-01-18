#include "sort.h"

void insertSort(std::vector<int>& vec) {
	if(vec.empty()) {
		return;
	}

	for(size_t i = 1; i < vec.size(); i++) {
		int end = i-1;
		int key = vec[i];
		while(end >= 0 && key < vec[end]) {
			vec[end+1] = vec[end];
			end--;
		}
		vec[end+1] = key;
	}
}

void shellSort(std::vector<int>& vec) {
	if(vec.empty()) {
		return;
	}

	int gap = 3;
	while(gap--) {
		for(size_t i = gap; i < vec.size(); i++) {
			int end = i-gap;
			int key = vec[i];
			while(end >= 0 && key < vec[end]) {
				vec[end+gap] = vec[end];
				end -= gap;
			}
			vec[end+gap] = key;
		}
	}
}

static void swap(int *left, int *right) {
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

void bubbleSort(std::vector<int>& vec) {
	if(vec.empty()) {
		return;
	}

	for(size_t i = 0; i < vec.size()-1; i++) {
		for(size_t j = i+1; j < vec.size(); j++) {
			if(vec[i] > vec[j]) {
				swap(&vec[i], &vec[j]);
			}
		}
	}
}

static void adJustDown(int *array, int size, int par) {

	int index = par*2 + 1;
	while(index < size) {
		if(index+1 < size && array[index+1] > array[index]) {
			index += 1;
		}

		if(array[par] >= array[index]) {
			break;
		} else {
			swap(array+par, array+index);
			par = index;
			index = par*2 + 1;
		}

	}
}

void heapSort(int *array, int size) {
	if(array == NULL) {
		return;
	}

	for(int i = (size-2)/2; i >= 0; i--) {
		adJustDown(array, size, i);
	}

	int end = size-1;
	while(end > 0) {
		swap(array+0, array+end);
		adJustDown(array, end, 0);
		end--;
	}
}

void selectSort(std::vector<int>& vec) {
	if(vec.empty()) {
		return;
	}

	int minPos = 0;
	int maxPos = vec.size()-1;

	while(minPos < maxPos) {
		int minIndex = minPos;
		int maxIndex = minPos;

		for(int i = minPos; i <= maxPos; i++) {
			if(vec[i] < vec[minIndex]) {
				minIndex = i;
			}

			if(vec[i] > vec[maxIndex]) {
				maxIndex = i;
			}
		}

		swap(&vec[minIndex], &vec[minPos]);
		if(minPos == maxIndex) {
			maxIndex = minIndex;
		}
		swap(&vec[maxPos], &vec[maxIndex]);

		minPos++, maxPos--;
	}
}

static int partion1(std::vector<int> &vec, int left, int right) {
	int begin = left, end = right;

	while(begin < end) {
		while(begin < end && vec[begin] <= vec[right]) {
			begin++;
		}

		while(begin < end && vec[end] >= vec[right]) {
			end--;
		}

		swap(&vec[begin], &vec[end]);
	}
	swap(&vec[begin], &vec[right]);
	return begin;
}

static int partion2(std::vector<int> &vec, int left, int right) {
	int key = vec[right];
	int begin = left, end = right;

	while(begin < end) {
		while(begin < end && vec[begin] <= key) {
			begin++;
		}
		vec[end] = vec[begin];

		while(begin < end && vec[end] >= key) {
			end--;
		}
		vec[begin] = vec[end];
	}

	vec[begin] = key;
	return begin;
}

static int partion3(std::vector<int> &vec, int left, int right) {
	int fast = left, slow = left;
	while(fast < right) {
		if(vec[fast] <= vec[right]) {
			swap(&vec[slow], &vec[fast]);
			slow++;
		}
		fast++;
	}

	swap(&vec[right], &vec[slow]);
	return slow;
}

void _quickSort(std::vector<int>& vec, int left, int right) {
	if(left == right || left > right) {
		return;
	}

	int index = partion3(vec, left, right);
	_quickSort(vec, index+1, right);
	_quickSort(vec, left, index-1);
}

void quickSort(std::vector<int>& vec) {
	if(vec.empty()) {
		return;
	}
	_quickSort(vec, 0, vec.size()-1);
}

static void merge(std::vector<int> &vec, int left, int mid, int right, int *tmp) {
	int left_index = left;
	int right_index = mid;
	int tmp_index = left;

	while(left_index < mid && right_index < right) {
		if(vec[left_index] <= vec[right_index]) {
			tmp[tmp_index++] = vec[left_index++];
		} else {
			tmp[tmp_index++] = vec[right_index++];
		}
	}

	while(left_index < mid) {
		tmp[tmp_index++] = vec[left_index++];
	}

	while(right_index < right) {
		tmp[tmp_index++] = vec[right_index++];
	}

	for(int i = left; i < right; i++) {
		vec[i] = tmp[i];
	}
}

void _mergeSort(std::vector<int> &vec, int left, int right, int *tmp) {
	if(left+1 == right || left == right) {
		return;
	}

	int mid = left + (right-left)/2;
	_mergeSort(vec, left, mid, tmp);
	_mergeSort(vec, mid, right, tmp);

	merge(vec, left, mid, right, tmp);
}

void mergeSort(std::vector<int> &vec) { //[)
	if(vec.empty()) {
		return;
	}

	int *tmp = new int[vec.size()];
	_mergeSort(vec, 0, vec.size(), tmp);
	delete[] tmp;
}

