#include <math.h>
#include <stack>
#include <chrono>
#include "arrayProcess.h"
#include "sorting.h"
#include "searching.h"
#include "list.h"
#include "queue.h"
#include "stack.h"
#include "tree.h"
#include "string"
#include <sstream> // stringstream

using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
	stringstream ss;
	int n;
	char c;
	vector<int> res;

	// if its not the end of string stream
	while (!ss.eof()) {
		ss >> n;
		ss >> c;
		res.push_back(n);
		cout << n << c << endl;
	}

	return res;
}

int main() {
	AVL myAVL;
	myAVL.Insert(90);
	myAVL.Insert(100);
	myAVL.Insert(60);
	myAVL.LevelOrder();
	//myAVL.Insert(70);
	//myAVL.Insert(20);
	//myAVL.LevelOrder();
	//myAVL.LevelOrder();
	//BSTree myTree;
	//myTree.Insert(90);
	//myTree.Insert(60);
	//myTree.Insert(70);
	//myTree.Insert(20);
	//myTree.Insert(10);
	//myTree.Insert(40);
	//myTree.Insert(30);
	//myTree.Insert(50);
	//myTree.Insert(80);
	//myTree.Insert(100);
	//myTree.LevelOrder();

	//auto start = std::chrono::high_resolution_clock::now();
	//// process here
	//auto stop = std::chrono::high_resolution_clock::now();
	//long long duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
	//
	//cout << endl << "excution time = " << duration << endl;


	//stack<int *> myStack;

	//int* n1 = new int;
	//int* n2 = new int;
	//int* n3 = new int;
	//*n1 = 5;
	//*n1 = 7;
	//*n1 = 4;
	//myStack.push(n1);
	//myStack.push(n2);
	//myStack.push(n3);
	//int* tmp =  myStack.top();
	//myStack.pop();
	//cout << *tmp << endl;


	//Stack myStack;
	//myStack.Push(7);
	//myStack.Push(5);
	//myStack.Push(2);
	//myStack.Push(1);
	//myStack.Push(9);
	//myStack.Push(2);
	//myStack.Display();
	//cout << myStack.Pop() << endl;
	//myStack.Display();

	/*Queue myQ;
	myQ.Enqueue(2);
	myQ.Enqueue(9);
	myQ.Enqueue(1);
	myQ.Enqueue(2);
	myQ.Enqueue(5);
	myQ.Enqueue(7);
	myQ.display();
	myQ.Enqueue(9);
	myQ.display();
	myQ.Dequeue();
	myQ.Dequeue();
	myQ.Dequeue();
	myQ.Dequeue();
	myQ.Dequeue();
	myQ.display();*/
	//vector<int> arr = {1, 0, 1};
	//List linkedList(arr);
	//linkedList.addTail(2);
	//linkedList.addTail(9);
	//linkedList.addTail(1);
	//linkedList.addTail(2);
	//linkedList.addTail(7);
	//linkedList.addHead(6);
	//linkedList.addAfterIdx(5, 1);
	//linkedList.addAfterIdx(5, 0);
	//linkedList.addAfterIdx(5, 7);

	/*linkedList.display();
	linkedList.removeDuplicate();
	linkedList.display();*/

	////int arr[10] = {352, 543, 11, 998, 123, -5, 4, 67, 1000, 10};
	////int n = 10;
	//int n;
	//cout << "n = "; cin >> n;
	//int *arr = getRandomArray(n, 0, 10);
	//printArray(arr, n);
	//
	//
	////reverseArray(arr, n);
	////insertion_sort(arr, n);
	//mergeSort(arr, 0, n-1);
	//printArray(arr, n);
	////quickSort(arr, 0, n-1);
	////printArray(arr, n);
	//int x; cin >> x;
	//cout << recursiveBinarySearch(arr, 0, n-1 , x) << endl;

	return 0;
}

