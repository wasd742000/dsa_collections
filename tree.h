#pragma once
#include <iostream>
#include <queue>
#include <stack> 
#include <algorithm> // std::min()

// MAX MIN VALUE OF NODE
#define MAX_VALUE 1000
#define MIN_VALUE 0


	/*
	#############################################################
	######                BINARY SEARCH TREE               ######
	#############################################################
	*/

class BSTree{
private:
	struct NodeBST {
		int val;
		NodeBST* left;
		NodeBST* right;

		NodeBST() {
			val = 0;
			left = NULL;
			right = NULL;
		}
		NodeBST(int inVal) {
			val = inVal;
			left = NULL;
			right = NULL;
		}
	};
	NodeBST* root;
	void Insert(NodeBST* treeRoot, int inVal);
	NodeBST* Delete(NodeBST* curRoot, int delVal);
	void Inorder(NodeBST* treeRoot);
	void Preorder_recursion(NodeBST* treeRoot);
	void Postorder(NodeBST* treeRoot);
	int getHeight(NodeBST* treeRoot);
	int findMin(NodeBST* treeRoot);
	int findMax(NodeBST* treeRoot);
	bool find(NodeBST* treeRoot, int value);
	bool isLesserTree(NodeBST* curRoot, int inVal);
	bool isBiggerTree(NodeBST* curRoot, int inVal);
	bool isBinarySearchTree(NodeBST* curRoot, int min, int max);
	bool isBinarySearchTree2(NodeBST* curRoot);
	int getSum(NodeBST *curRoot);
	int findMin_BT(NodeBST* curRoot);
	int maxRoot2Leaf(NodeBST* curRoot);

public:
	BSTree();

	/* 
	#############################################################
	######              BASIC BST MANIPULATING             ######
	#############################################################
	*/
	void Insert(int inVal) { Insert(this->root, inVal); }
	void Delete(int delVal) { Delete(this->root, delVal); }
	// insert without BST rule, only for testing
	// dir: insert direction (1: left, 0: right)


	/*
	#############################################################
	#####				     BST TRAVERSAL               ########
	#############################################################
	*/
	// DFS
	void Inorder() { Inorder(this->root); }
	void Preorder_stack();
	void Preorder_recursion(){ Preorder_recursion(this->root); }
	void Postorder(){ Postorder(this->root); }
	// BFS
	void LevelOrder();
	
	/*
	#############################################################
	#####				   GET BST INFO                  ########
	#############################################################
	*/
	int getHeight() { return getHeight(this->root); }
	bool isEmpty();
	int countNode();
	int findMin() { return findMin(this->root); }
	int findMax() { return findMax(this->root); }
	bool find(int value) { return find(this->root, value); }
	bool find_BFS(int value);
	bool isBinarySearchTree() { return isBinarySearchTree(this->root, MIN_VALUE, MAX_VALUE); }
	bool isBinarySearchTree2() { return isBinarySearchTree2(this->root); };
	int getSum() { return getSum(this->root); }
	int getSum_BFS();

	// origin method for binary tree
	int findMin_BT(){ return findMin_BT(this->root); }
	int maxRoot2Leaf() { return maxRoot2Leaf(this->root); }

};


/*
#############################################################
######						AVL TREE	               ######
#############################################################
*/

class AVL {
private:
	struct Node {
		int _val;
		int _h; // height of node
		Node* _left, * _right;
		// 1 node has height = 0
		Node() {
			_val = 0;
			_h = 0;
			_left = _right = NULL;
		}
		Node(int val) {
			_val = val;
			_h = 0;
			_left = _right = NULL;
		}
	};

	Node* _root;

	int findMin(Node* root);
	int getBalance(Node* node);
	int getHeight(Node* node);
	Node* leftRotate(Node* node);
	Node* rightRotate(Node* node);
	Node* Insert(Node* root, int val);
	Node* Delete(Node* root, int val);
public:
	AVL();
	void Insert(int val) { _root = Insert(_root, val); }
	void Delete(int val) { Delete(_root, val); }
	// BFS - Level Order traversal (using stack)
	void LevelOrder();

};