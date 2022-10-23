#pragma once
#include "arrayProcess.h"

void bubble_sort(int* arr, int n);
void selection_sort(int* arr, int n);
void insertion_sort(int* arr, int n);
void mergeSort(int* arr, int l, int r);
void merge(int* arr, int l, int m, int r);

void quickSort(int* arr, int low, int high);
int partition(int* arr, int low, int high);