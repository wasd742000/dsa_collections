#include "arrayProcess.h"

void swap(int* p1, int* p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int getRandomNumber(int min, int max)
{
	random_device rd; // obtain a random number from hardware
	mt19937 gen(rd()); // seed the generator
	uniform_int_distribution<> distr(min, max); // define the range

	return distr(gen); // generate numbers
}

int* getRandomArray(int size, int min, int max) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = getRandomNumber(min, max);
	return arr;
}

int* inputArray(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "arr[" << i << "]" << " = ";
		cin >> arr[i];
	}

	return arr;
}

void printArray(int* arr, int size)
{
	cout << "arr = [";
	for (int i = 0; i < size; i++) {
		cout << " " << arr[i];
	}
	cout << " ]" << endl;
}

void dellocateArray(int*& a) {
	delete [] a;
	a = NULL;
}

int findMax(int* arr, int n) {
	int idx = 0;
	for (int i = 1; i < n; i++)
		if (arr[i] > arr[idx])
			idx = i;
	
	return idx;
}

int findMin(int* arr, int n) {
	int idx = 0;
	for (int i = 1; i < n; i++)
		if (arr[i] < arr[idx])
			idx = i;

	return idx;
}

bool isAscending(int* arr, int n) {
	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			return 0;

	return 1;
}

bool isDescending(int* arr, int n) {
	for (int i = 0; i < n - 1; i++)
		if (arr[i] < arr[i + 1])
			return 0;

	return 1;
}

// without using sub array
void reverseArray(int* &arr, int n) {
	for (int i = 0; i < n/2; i++)
		swap(&arr[i], &arr[n - 1 - i]);
}

