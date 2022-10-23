#include "list.h"

List::List() {
	this->head = NULL;
}
List::List(std::vector<int> arr) {
	this->head = NULL;
	for (int i = 0; i < arr.size(); i++)
		this->addTail(arr[i]);
}

// Insert element
void List::addHead(int inData) {
	// create new node object
	Node* newNode = new Node(inData);
	
	newNode->next = this->head;
	head = newNode;
}


void List::addTail(int inData) {
	// create new node object
	Node* newNode = new Node(inData);

	// if the list is empty
	if (this->head == NULL) {
		head = newNode;
		return;
	}

	Node* curNode = this->head;

	// traverse to the tail node
	while (curNode->next != NULL)
		curNode = curNode->next;

	// add new node at the end of the list
	curNode->next = newNode;
}

bool List::addAfterIdx(int inData, int idx) {
	// if idx is out of range of list
	if (idx > this->countNode() - 1)
		return 0;

	Node* newNode = new Node(inData);

	// traverse to idx node
	int i = 0;
	Node* tmp = this->head;
	while (i != idx) {
		tmp = tmp->next;
		++i;
	}

	// add newNode after idx node
	newNode->next = tmp->next;
	tmp->next = newNode;
	return 1;
}

// remove
void List::removeHead(){
	if (this->head == NULL)
		return;

	Node* tmp = head;
	head = head->next;
	delete tmp;
}

void List::removeTail() {
	if (this->head == NULL)
		return;

	// if list has 1 node
	if (this->head->next == NULL)
	{
		this->removeHead();
		return;
	}

	Node* curNode = head;
	Node* pNode = NULL; // tmp2 for getting the previous node

	// traverse curNode to the last node;
	while (curNode->next != NULL) {
		pNode = curNode;
		curNode = curNode->next;
	}

	pNode->next = NULL; // second last node -> last node
	delete curNode; // delete tail
}

bool List::removeAtIdx(int idx) {
	if (idx > this->countNode() - 1)
		return 0;

	if (idx == 0) {
		this->removeHead();
		return 1;
	}

	// traverse to previous node of idx node (idx - 1)
	Node* curNode = this->head;
	int i = 0;

	while (i != idx - 1)
	{
		curNode = curNode->next;
		++i;
	}

	Node* delNode = curNode->next;
	curNode->next = curNode->next->next;
	
	delete delNode; // delete idx node

	return 1;
}

bool existData(std::vector<int> arr, int data) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == data)
			return 1;
	}
	return 0;
}

void List::removeDuplicate() {
	std::vector<int> uniqueArr;
	// get unique array
	Node* curNode = head;
	while (curNode != NULL) // traverse all nodes 
	{
		if (!existData(uniqueArr, curNode->data))
			uniqueArr.push_back(curNode->data);

		curNode = curNode->next;
	}

	// delete linked list
	this->removeAll();

	// create new unique data linked list
	for (int i = 0; i < uniqueArr.size(); i++)
		this->addTail(uniqueArr[i]);
}


void List::removeData(int delData) {
	if (head == NULL)
		return;
	// because curNode start from head->next, must check head first
	// if first node data == delData -> delete
	if (head->data == delData)
		this->removeHead();

	Node* curNode = head->next;
	Node* pNode = head;

	Node* tmp = NULL; // for delete node
	
	while (curNode != NULL) {
		if (curNode->data == delData) {
			tmp = curNode;
			pNode->next = tmp->next;
			curNode = tmp->next;
			
			// delete curNode
			delete tmp;
			tmp = NULL;
			
		}
		else {
			pNode = curNode;
			curNode = curNode->next;
		}
	}
}

void List::removeAll() {
	Node* tmp = NULL;
	while (this->head != NULL)
	{
		tmp = head;
		this->head = head->next;
		delete tmp;
	}

	// update head;
	this->head = NULL;
}

// count
int List::countNode() {
	Node* tmp = this->head;
	int count = 0;

	// traverse all node
	while (tmp != NULL)
	{
		tmp = tmp->next;
		++count;
	}

	return count;
}

// reverse
void List::reverse() {
	if (head == NULL)
		return;

	Node* curNode = this->head->next; // current node
	Node* pNode = this->head; // previous node

	// head -> tail
	this->head->next = NULL;

	Node* tmp = NULL; // for storing next node
	// traverse all nodes
	while (curNode != NULL)
	{
		// reverse
		tmp = curNode->next;
		curNode->next = pNode;
		// move to next nodes
		pNode = curNode;
		curNode = tmp;
	}

	// update head
	head = pNode;
}

// display
void List::display() {
	if (head == NULL) {
		std::cout << "List is empty ! " << std::endl;
		return;
	}

	std::cout << "List [" << this->countNode() << "]: [";
	Node* tmp = head;

	// traverse all nodes
	while (tmp != NULL)
	{
		std::cout << " " << tmp->data;
		tmp = tmp->next;
	}


	std::cout << " ]" << std::endl;
}

