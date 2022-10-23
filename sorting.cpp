#include "sorting.h"

// > --> swap
void bubble_sort(int* arr, int n) {
	// i is the number of elements in sorted sub array
	// j traverse through unsorted sub array and swap
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
	}
}

// min --> move to beg
void selection_sort(int* arr, int n) {
	// i is the first idx of unsorted sub array
	// j traverse unsorted sub array to find min_idx -> swap (min_idx, i)
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++) {
		// find min
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(&arr[i], &arr[min_idx]);
	}
}


void insertion_sort(int* arr, int n) {
	int i, j, key;
	// first array element is considered a sorted array
	for (i = 1; i < n; i++) {
		key = arr[i]; // get the first element of unsorted array
		j = i - 1; // the last element of the sorted array
		// traverse back the sorted array to find a position for key
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		// put key in its proper position in sorted sub array 
		arr[j + 1] = key;
	}
}

void mergeSort(int* arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void merge(int* arr, int l, int m, int r) {
	// nl, nl is size of left and right array
	// i, j, k use respectively for traversing left, right and merging array
	int nl, nr, i, j, k;
	nl = m - l + 1; // + 1 because sub left array includes middle element
	nr = r - m;

	// create left and right sub array
	int* lArr = new int[nl];
	int* rArr = new int[nr];
	//int lArr[nl], rArr[nr];
	for (i = 0; i < nl; i++)
		lArr[i] = arr[l + i];
	for (j = 0; j < nr; j++)
		rArr[j] = arr[m + 1 + j];

	i = 0; j = 0; k = l;
	// arrange and merge 
	while (i < nl && j < nr) {
		if (lArr[i] <= rArr[j]) {
			arr[k] = lArr[i];
			i++;
		}
		else {
			arr[k] = rArr[j];
			j++;
		}
		k++;
	}

	// get the remains of left, right sub array 
	while (i < nl)
	{
		arr[k] = lArr[i];
		i++; k++;
	}

	while (j < nr) {
		arr[k] = rArr[j];
		j++; k++;
	}
	delete[] lArr;
	delete[] rArr;
}

// QUICK SORT

void quickSort(int* arr, int low, int high) {
	// one element sub array is considered sorted
	// if sub array has at least two element
	if (low < high) {
		int pivot = partition(arr, low, high);

		// pivot is considered sorted
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

int partition(int* arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1, j;

	for (j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[j], &arr[i]);
		}
	}

	swap(&arr[i + 1], &arr[high]);

	return i + 1;
}