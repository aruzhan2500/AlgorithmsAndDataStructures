#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left, * right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

class BST {
public:
	Node* root;
	BST() {
		root = NULL;
	}

	Node* insert(Node* node, int data) {
		if (node == NULL) {
			node = new Node(data);
			return node;
		}
		if (data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);
		return node;
	}

	Node* rightMost(Node* node) {
		while (node->right != NULL) {
			node = node->right;
		}
	}
};

int main()
{
	int n;
	cin >> n;
	BST* bst = new BST();
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		bst->root = bst->insert(bst->root, x);
	}
	BST* bst2 = new BST();
	bst2->root = bst->insert(bst->rightMost(bst->root), )
	return 0;
}