#include "tree.h"


/*
#############################################################
######              BS TREE				               ######
#############################################################
*/

BSTree::BSTree() {
	this->root = NULL;
}

void BSTree::Insert(NodeBST* treeRoot, int inVal) {
	// case 0: empty BST
	if (treeRoot == NULL) {
		treeRoot = new NodeBST(inVal);
		this->root = treeRoot;
	}
	// case 1, 2, 3, 4: tree not empty
	else {
		// case 1, 2: new node should be on the left child tree
		if (inVal <= treeRoot->val)
		{
			if (treeRoot->left == NULL) // case 1: left child tree is empty
				treeRoot->left = new NodeBST(inVal);
			else // case 2: left child tree is not empty
				Insert(treeRoot->left, inVal);
		}
		// case 3, 4: new node should be on the right child tree
		else { 
			if (treeRoot->right == NULL) // case 3: right child tree is empty
				treeRoot->right = new NodeBST(inVal);
			else // case 4: right child tree is not empty
				Insert(treeRoot->right, inVal);
		}
	}
}

BSTree:: NodeBST* BSTree::Delete(NodeBST* curRoot, int delVal) {
	if (curRoot == NULL)
		return curRoot;
	else if (delVal < curRoot->val)
		curRoot->left = Delete(curRoot->left, delVal);
	else if (delVal > curRoot->val)
		curRoot->right = Delete(curRoot->right, delVal);
	else { // found ! (delVal == curRoot->val) 
		// case 0: deleting leaf node
		if (curRoot->left == NULL && curRoot->right == NULL) {
			NodeBST* tmp = curRoot;
			curRoot = NULL;
			delete tmp;
		}
		// case 1: deleting node with 1 child
		else if (curRoot->right == NULL) { // child on the left
			NodeBST* tmp = curRoot;
			curRoot = curRoot->left;
			delete tmp;
		}
		else if (curRoot->left == NULL) { // child on the right
			NodeBST* tmp = curRoot;
			curRoot = curRoot->right;
			delete tmp;
		}
		// case 2: deleting node with 2 child
		// find max on left sub tree or find min on right sub tree
		else {
			//int tmp = findMin(curRoot->right);
			curRoot->val = findMin(curRoot->right);
			curRoot->right = Delete(curRoot->right, curRoot->val);
		}
	}
	
	return curRoot;
}

void insert_Custom(int inVal) {
	
}

void BSTree::Inorder(NodeBST* treeRoot) {
	if (treeRoot == NULL)
		return;
	//std::cout << "inorder" << std::endl;
	Inorder(treeRoot->left);
	std::cout << " " << treeRoot->val;
	Inorder(treeRoot->right);
}



void BSTree::Preorder_stack() {
	std::stack<NodeBST*> tmp;
	tmp.push(this->root);

	while (!tmp.empty()) {
		NodeBST* curNode = tmp.top();
		tmp.pop();
		if (curNode->right != NULL)
			tmp.push(curNode->right);
		if (curNode->left != NULL)
			tmp.push(curNode->left);

		std::cout << " " << curNode->val;
	}
}

void BSTree::Preorder_recursion(NodeBST* treeRoot) {
	if (treeRoot == NULL)
		return;
	std::cout << " " << treeRoot->val;
	Preorder_recursion(treeRoot->left);
	Preorder_recursion(treeRoot->right);
}

void BSTree::Postorder(NodeBST* treeRoot) {
	if (treeRoot == NULL)
		return;
	Postorder(treeRoot->left);
	Postorder(treeRoot->right);
	std::cout << " " << treeRoot->val;

}

void BSTree::LevelOrder() {
	if (this->isEmpty())
		return;

	std::queue<NodeBST*>  nodeQueue;
	nodeQueue.push(this->root);

	while (!nodeQueue.empty()) {
		std::cout << nodeQueue.front()->val << " ";
		if (nodeQueue.front()->left != NULL)
			nodeQueue.push(nodeQueue.front()->left);
		if (nodeQueue.front()->right != NULL)
			nodeQueue.push(nodeQueue.front()->right);
		nodeQueue.pop();
	}
}

bool BSTree::isEmpty() {
	return (this->root == NULL);
}

int BSTree::getHeight(NodeBST* treeRoot) {
	// empty tree has height = -1
	if (treeRoot == NULL)
		return -1;

	return (1 + std::max(getHeight(treeRoot->left), getHeight(treeRoot->right)));
}

int BSTree::findMin(NodeBST* treeRoot) {
	if (treeRoot == NULL)
		return -1;
	else if (treeRoot->left == NULL)
		return treeRoot->val;

	return findMin(treeRoot->left);

	//// find leftmost node (min node)
	//NodeBST* curNode = treeRoot;
	//while (curNode->left != NULL)
	//	curNode = curNode->left;

	//return curNode->val;
}

int BSTree::findMax(NodeBST* treeRoot) {
	if (treeRoot == NULL)
		return -1;

	// find rightmost node (max node)
	NodeBST* curNode = treeRoot;
	while (curNode->right != NULL)
		curNode = curNode->right;

	return curNode->val;
}


bool BSTree::find(NodeBST* curRoot, int value) {
	// BST is empty -> not found
	if (curRoot == NULL)
		return false;
	// curRoot's value is the value that needed to find -> found
	if (curRoot->val == value)
		return true;

	//NOTE!: from here you could use recursion like this:
	//return (find(curRoot->left, value) || find(curRoot->right, value));
	// END FUNCTION

	// ELSE
	if (value <= curRoot->val)
		return find(curRoot->left, value);
	else // (value > curRoot->val)
		return find(curRoot->right, value);
}

bool BSTree::find_BFS(int value) {
	// current tree root is empty
	if (this->isEmpty())
		return false;

	std::queue<NodeBST*> tmp;
	tmp.push(this->root);

	while (!tmp.empty()) {
		NodeBST* curNode = tmp.front();
		tmp.pop();

		if (curNode->val == value)
			return true;

		if (curNode->left != NULL)
			tmp.push(curNode->left);

		if (curNode->right != NULL)
			tmp.push(curNode->right);
		//std::cout << curNode->val << " ";
	}
	
	return false;
}

// sub function for isBST function
bool BSTree::isLesserTree(NodeBST* curRoot, int inVal) {
	// sub tree is empty -> true
	if (curRoot == NULL)
		return true;
	if (curRoot->val < inVal
		&& isLesserTree(curRoot->left, inVal)
		&& isLesserTree(curRoot->right, inVal))
		return true;

	return false;
}

bool BSTree::isBiggerTree(NodeBST* curRoot, int inVal) {
	if (curRoot == NULL)
		return true;

	if (curRoot->val > inVal
		&& isBiggerTree(curRoot->left, inVal)
		&& isBiggerTree(curRoot->right, inVal))
		return true;

	return false;
}

/* CHECK IF A TREE IS A BINARAY SEARCH TREE
SOLUTION 3: Use inorder traversal to store node, if all value is sorted -> is BST 
SOLUTION 2: Recursion, root node should be bigger than all node on the left tree and smaller than all node on the right tree
SOLUTION 1: Recursion, root node should be bigger than max node on the left and smaller than min node on the right 

*/

// SOLUTION 1
bool BSTree::isBinarySearchTree(NodeBST* curRoot, int min, int max) {
	if (curRoot == NULL)
		return true;

	if (curRoot->val > min
		&& curRoot->val < max
		&& isBinarySearchTree(curRoot->left, min, curRoot->val)
		&& isBinarySearchTree(curRoot->right, curRoot->val, max))
		return true;

	return false;
}

// SOLUTION 2
bool BSTree::isBinarySearchTree2(NodeBST* curRoot) {
	if (curRoot == NULL)
		return true;
	
	if (isLesserTree(curRoot->left, curRoot->val)
		&& isBiggerTree(curRoot->right, curRoot->val)
		&& isBinarySearchTree2(curRoot->left)
		&& isBinarySearchTree2(curRoot->right))
		return true;

	return false;
}

int BSTree::getSum(NodeBST* curRoot) {
	// tree is empty -> sum = 0
	if (curRoot == NULL)
		return 0;
	return curRoot->val + getSum(curRoot->left) + getSum(curRoot->right);
}

int BSTree::getSum_BFS() {
	int sum = 0;
	std::queue<NodeBST*> tmp;
	tmp.push(this->root);

	while (!tmp.empty()) {
		NodeBST* curNode = tmp.front();
		tmp.pop();
		sum += curNode->val;

		if (curNode->left != NULL)
			tmp.push(curNode->left);
		if (curNode->right != NULL)
			tmp.push(curNode->right);
	}
	return sum;
}

// for binary tree only
// use could use BFS or DFS instead
int BSTree::findMin_BT(NodeBST* curRoot) {
	if (curRoot == NULL)
		return MAX_VALUE;
	return std::min(curRoot->val, std::min(findMin_BT(curRoot->left), findMin_BT(curRoot->right)));
}


// for both BT and BST
int BSTree::maxRoot2Leaf(NodeBST* curRoot) {
	if (curRoot == NULL)
		return 0;
	return curRoot->val + std::max(maxRoot2Leaf(curRoot->left), maxRoot2Leaf(curRoot->right));
}


/*
#############################################################
######						AVL TREE	               ######
#############################################################
*/

AVL::AVL() {
	_root = NULL;
}

int AVL::findMin(Node* root)
{
	if (root == NULL) // empty tree
		return -1;
	if (root->_left == NULL)
		return root->_val;
	return findMin(root->_left);
}

// get tree height with root: node
int AVL::getHeight(Node* node) {
	if (node == NULL) // empty tree has height = -1
		return -1;
	return node->_h;
}

// left unbalance: balance > 1
// right unbalance: balance < -1
int AVL::getBalance(Node* node) {
	if (node == NULL) // null node dont have any child
		return 0;
	return node->_left - node->_right;
}


AVL::Node* AVL::leftRotate(Node* node) {
	Node* right_child = node->_right;
	node->_right = right_child->_left;
	right_child->_left = node;

	// update height for both nodes
	node->_h = 1 + std::max(getHeight(node->_left), getHeight(node->_right));
	right_child->_h = 1 + std::max(getHeight(right_child->_left), getHeight(right_child->_right));

	return right_child; // return for update if node has parent
}

//AVL::Node* AVL::leftRotate(Node* node) {
//	Node* tmp = node->_right; // tmp is the child node
//	node->_right = tmp->_left;
//	tmp->_left = node;
//	
//	// update height after rotate
//	tmp->_h = 1 + std::max(getHeight(tmp->_left), getHeight(tmp->_right));
//	node->_h = 1 + std::max(getHeight(node->_left), getHeight(node->_right));
//
//	return tmp; // for update if node has parent
//}

AVL::Node* AVL::rightRotate(Node* node) {
	Node* tmp = node->_left;
	node->_left = tmp->_right;
	tmp->_right = node;

	// update height after rotate
	tmp->_h = 1 + std::max(getHeight(tmp->_left), getHeight(tmp->_right));
	node->_h = 1 + std::max(getHeight(node->_left), getHeight(node->_right));

	return tmp; // for update if node has parent 
}

AVL::Node* AVL::Insert(Node* root, int val) {
	if (root == NULL) { // empty AVL tree
		//Node* newNode = ;
		std::cout << "insert " << val << std::endl;
		return new Node(val);
	}
	if (val < root->_val) // insert on left sub tree
		root->_left = Insert(root->_left, val);
	else if (val > root->_val) // insert on right sub tree
		root->_right = Insert(root->_right, val);
	else
		return root;

	// update current root height after insertion
	root->_h += 1 + std::max(getHeight(root->_left), getHeight(root->_right));
	
	// check if current root is unbalance
	// left unbalance
	if (getBalance(root) > 1){
		// left-left unbalance 
		//(it means val has been insert on the sub left tree of current root's left child and cause unbalance )
		if (val < root->_left->_val) {
			// rotate right
			return rightRotate(root);
		}
		// left-right unbalance 
		//(it means val has been insert on the sub right tree of current root's left child and cause unbalance )
		else if (val > root->_left->_val) {
			// rotate left then right
			root->_right = leftRotate(root->_right);
			return rightRotate(root);
		}
	}

	// right unbalance
	if (getBalance(root) < -1) {
		// right-right unbalance 
		if (val > root->_right->_val) {
			// rotate left
			return leftRotate(root);
		}
		// right-left
		else if (val < root->_right->_val) {
			// rotate right then left
			root->_right = rightRotate(root->_right);
			return leftRotate(root);
		}
	}

	return root; // if current root is balance
}

AVL::Node* AVL::Delete(Node* root, int val) {
	if (root == NULL)
		return root;
	else if (val < root->_val)
		root->_left = Delete(root->_left, val);
	else if (val > root->_val)
		root->_right = Delete(root->_right, val);
	else { // found val;
		// case 0: deleting node is leaf
		if (root->_left == NULL && root->_right == NULL) {
			Node* tmp = root;
			root = NULL;
			delete tmp;
		}
		// case 1: deleting node has 1 child
		else if (root->_left != NULL) {
			Node* tmp = root;
			root = root->_left;
			delete tmp;
		}
		else if (root->_right != NULL) {
			Node* tmp = root;
			root = root->_right;
			delete tmp;
		}
		// case 2: deleting has 2 child
		else {
			int tmp = findMin(root->_right);
			root->_val = tmp;
			root->_right = Delete(root->_right, tmp);
		}
	}

	if (root == NULL) // root have only one node and after deleting is is NULL
		return root;

	// update cur root height
	root->_h = 1 + std::max(getHeight(root->_left), getHeight(root->_left));

	// left unbalance
	if (getBalance(root) > 1) {
		// left-right unbalance
		if (val < root->_val) {
			root->_left = leftRotate(root->_left);
			return rightRotate(root);
		}
		// left-left unbalance
		else if (val > root->_val) {
			return rightRotate(root);
		}
	}
	// right unbalance
	else if (getBalance(root) < -1){
		// right-right unbalance
		if (val < root->_val) {
			return leftRotate(root);
		}
		// right-left unbalance
		else if (val > root->_val) {
			root->_right = rightRotate(root->_right);
			return leftRotate(root);
		}
	}

	return root;
}

void AVL::LevelOrder() {
	std::stack<Node*> tmp;
	tmp.push(_root);
	
	while (!tmp.empty()) {
		// pop top node to curNode
		Node* curNode = tmp.top();
		tmp.pop();
		
		// process curNode
		std::cout << curNode->_val << " ";
		
		// push curNode child if exist
		if (curNode->_left != NULL)
			tmp.push(curNode->_left);
		if (curNode->_right != NULL)
			tmp.push(curNode->_right);
	}
}