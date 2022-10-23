#pragma once
#include <iostream>
#include <vector>
#include "node.h"

// SINGLE LINKED LIST DATA STRUCTURE
class List
{
	Node* head;
public:
	// constructor
	List();
	List(std::vector<int> arr);

	// find element


	// Insert element
	void addHead(int inData);
	void addTail(int inData);
	bool addAfterIdx(int inData, int idx); // idx out of range -> return 0
	
	// remove
	void removeHead();
	void removeTail();
	bool removeAtIdx(int idx); // idx out of range -> return 0;
	void removeDuplicate();
	void removeData(int delData); 
	void removeAll();


	// count
	int countNode();

	// reverse
	void reverse();

	// display
	void display();

	//~List();
};

