#pragma once
#include "node.h"

class Stack
{
private:
	Node* top;
public:
	Stack();
	void Push(int data);
	int Pop();
	int Count();
	bool isEmpty();
	void Display();
};

