#include "searching.h"

int linearSearch(int* arr, int size, int value) {
	for (int i = 0; i < size; i++)
		if (arr[i] == value) return i;

	return -1;
}

int sentinelLinearSearch(int* arr, int n, int value) {
	int last = arr[n - 1];
	arr[n - 1] = value;

	int i = 0;
	while (arr[i] != value)
		i++;

	arr[n - 1] = last;

	if (i < n - 1 || arr[n - 1] == value)
		return i;

	return -1;
}

int binarySearch(int* arr, int size, int value) {
	int l, r, m;
	l = 0; r = size - 1;

	while (l <= r) {
		m = l + (r - l) / 2;

		if (arr[m] > value)
			r = m - 1;
		else if (arr[m] < value)
			l = m + 1;
		else // arr[m] == value
			return m;

	}

	return -1;
}

int recursiveBinarySearch(int* arr, int left, int right, int value) {
	// only 1 element remains
	if (left == right)
	{
		if (arr[left] == value)
			return left;
		else 
			return -1;
	}

	int mid = left + (right - left) / 2;

	if (arr[mid] == value)
		return mid;
	else if (arr[mid] > value)
		recursiveBinarySearch(arr, left, mid - 1, value);
	else if (arr[mid] < value)
		recursiveBinarySearch(arr, mid + 1, right, value);

}