#include "stack.h"

Stack::Stack() {
	this->top = NULL;

}

void Stack::Push(int data) {
	Node* newNode = new Node(data);
	
	if (this->isEmpty()) {
		this->top = newNode;
		return;
	}

	newNode->next = this->top;
	this->top = newNode;
}

int Stack::Pop() {
	if (this->isEmpty())
		return -1;

	// updata top
	Node* popNode = this->top;
	this->top = this->top->next;
	
	// get pop value
	int popData = popNode->data;
	
	// delete pop node
	delete popNode;

	return popData;
}

int Stack::Count() {
	Node* curNode = this->top;
	int count = 0;

	// traversing all nodes
	while (curNode != NULL) {
		++count;
		curNode = curNode->next;
	}

	return count;
}

bool Stack::isEmpty() {
	return (this->top == NULL) ? true : false;
}

void Stack::Display() {
	if (this->isEmpty()){
		std::cout << "Stack is empty !" << std::endl;
		return;
	}

	Node* curNode = this->top;
	std::cout << "Stack ["<<this->Count() << "] = [";
	while (curNode != NULL) {
		std::cout << " "<< curNode->data;
		curNode = curNode->next;
	}
	std::cout << " ]" << std::endl;
}
