#include <iostream>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node {
	int data;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = nullptr;

	return node;
}

// Recursive function to insert an key into BST
Node* insert(Node* root, int key)
{
	// if the root is null, create a new node an return it
	if (root == nullptr)
		return newNode(key);

	// if given key is less than the root node, recuse for left subtree
	if (key < root->data)
		root->left = insert(root->left, key);

	// if given key is more than the root node, recuse for right subtree
	else
		root->right = insert(root->right, key);

	return root;
}

// Helper function to find minimum value node in given BST
Node* findMinimum(Node* root)
{
	while (root->left)
		root = root->left;

	return root;
}

// Recursive function to find inorder successor for given key in a BST
// Note that successor 'succ' is passed by reference to the function
void findSuccessor(Node* root, Node*& succ, int key)
{
	// base case
	if (root == nullptr) {
		succ = nullptr;
		return;
	}

	// if node with key's value is found, the successor is minimum value
	// node in its right subtree (if any)
	if (root->data == key)
	{
		if (root->right)
			succ = findMinimum(root->right);
	}
	// if given key is less than the root node, recuse for left subtree
	else if (key < root->data)
	{
		// update successor to current node before recursing in left subtree
		succ = root;
		findSuccessor(root->left, succ, key);
	}

	// if given key is more than the root node, recuse for right subtree
	else
		findSuccessor(root->right, succ, key);
}

// main function
int main()
{
	/* Construct below tree
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12  16    25
	*/

	int keys[] = { 20, 3, 1, 2, 10, 5, 15, 12, 18, 17, 40, 39, 35, 37, 30, 32, 55};

	Node* root = nullptr;
	for (int key : keys)
		root = insert(root, key);

	// find in-order successor for each key
	for (int key : keys)
	{
		Node* prec = nullptr;
		findSuccessor(root, prec, key);

		if (prec != nullptr)
			cout << "Successor of node " << key << " is " << prec->data;
		else
			cout << "Successor doesn't exists for " << key;

		cout << '\n';
	}

	return 0;
}
