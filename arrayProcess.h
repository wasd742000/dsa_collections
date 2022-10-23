#pragma once
#include <random>
#include <iostream>
using namespace std;

void swap(int* p1, int* p2);
int* inputArray(int);
void printArray(int*, int);
int getRandomNumber(int min, int max);
int* getRandomArray(int size, int min, int max);
void dellocateArray(int*& a);

int findMax(int*, int);
int findMin(int*, int);
bool isAscending(int*, int);
bool isDescending(int*, int);
void reverseArray(int* &, int); // without using a sub array