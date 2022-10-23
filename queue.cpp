#include "queue.h"

Queue::Queue() {
	this->front = this->rear = NULL;
}


//Queue::Queue(int* arr, int n) {
//}

void Queue::Enqueue(int data) {
	Node* newNode = new Node(data);
	// if the queue is empty
	if (this->isEmpty()) {
		this->front = this->rear = newNode;
		return;
	}

	this->rear->next = newNode;
	this->rear = newNode;
}

int Queue::Dequeue() {
	// if empty list
	if (this->rear == NULL)
		return NULL;

	Node* tmp = this->front;
	this->front = this->front->next;

	// if there no node in queue
	if (this->front == NULL)
		this->rear = NULL;

	// storing dequeue node's data
	int res = tmp->data;
	delete tmp;

	return res;
}

int Queue::Count() {
	int count = 0;

	Node* tmp = this->front;
	// traverse all nodes (backward queue)
	while (tmp != NULL)
	{
		++count;
		tmp = tmp->next;
	}

	return count;
}

bool Queue::isEmpty() {
	return (this->rear == NULL && this->front == NULL) ? true : false;
}

void Queue::display() {
	if (this->isEmpty()) {
		std::cout << "Queue is empty !" << std::endl;
		return;
	}

	std::cout << "Queue [" << this->Count() <<"] = [";
	Node* tmp = this->front;

	// traverse all nodes
	while (tmp != NULL) {
		std::cout << " " << tmp->data;
		tmp = tmp->next;
	}
	std::cout << " ]" << std::endl;
}