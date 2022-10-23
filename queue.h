#pragma once
#include "node.h"

class Queue
{
public:
	Node* front, * rear;

	Queue();
	Queue(int *arr, int n);
	void Enqueue(int data);
	int Dequeue();
	int Count();
	bool isEmpty();
	void display();

	//~Queue();
};

