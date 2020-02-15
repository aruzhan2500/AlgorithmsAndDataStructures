#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

class Tree {
public:
	Node* root;
	int n;
	int a[10000];

	Tree() {
		root = NULL;
		n = 0;
	}

	Node* add(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else if (root->data >= data) {
			root->left = add(root->left, data);
		}
		else if (root->data < data) {
			root->right = add(root->right, data);
		}
		return root;
	}

	void print(Node* root) {
		if (root != nullptr) {
			print(root->left);
			cout << root->data << " ";
			print(root->right);
		}
	}

	void printLeaves(Node* root) {
		if (root == NULL) {
			return;
		}
		printLeaves(root->left);
		if (root->right == NULL && root->left == NULL)
			cout << root->data << endl;
		printLeaves(root->right);
	}

	void printLeavesOne(Node* root) {
		if (root == NULL) {
			return;
		}
		printLeavesOne(root->left);
		if ((root->right == NULL && root->left != NULL) || (root->right != NULL && root->left == NULL)) {
			cout << root->data << endl;
		}
		printLeavesOne(root->right);                                                                                                                                                                                 
	}
	int count(Node* root, int data) {
		if (root == NULL) {
			return 0;
		}
		else if (root->data == data) {
			return count(root->left, data) + 1;
		}
		count(find(root, data), data);
	}

	Node* find(Node* root, int x) {
		if (root == NULL) {
			return NULL;
		}
		else if (root->data == x) {
			return root;
		}
		else if (root->data < x) {
			return find(root->right, x);
		}
		else {
			return find(root->left, x);
		}
	}

	int max(int x, int y) {
		if (x > y) return x;
		return y;
	}

	int getSubtreeHeight(Node* root) {
		if (root == NULL) {
			return 0;
		}
		else {
			int l = getSubtreeHeight(root->left);
			int r = getSubtreeHeight(root->right);
			return max(l, r) + 1;
		}
	}

	void getSumOfLevel(Node* root, int l) {
		if (root == NULL) {
			return;
		}
		a[l] += root->data;
		if (root->left == NULL && root->right != NULL) {
			getSumOfLevel(root->right, l + 1);
		}
		if (root->left != NULL && root->right == NULL) {
			getSumOfLevel(root->left, l + 1);
		}
		if (root->left != NULL && root->right != NULL) {
			getSumOfLevel(root->right, l + 1);
			getSumOfLevel(root->left, l + 1);
		}
	}

	int numOfLeaves(Node* root) {
		if (root != NULL) {
			if (root->left == NULL && root->right == NULL) n++;
			if (root->left != NULL) numOfLeaves(root->left);
			if (root->right != NULL) numOfLeaves(root->right);
		}
		return n;
	}

	Node* getMin(Node* root) {
		while (root->left != NULL) {
			root = root->left;
		}
		return root;
	}

	Node* deleteNode(Node* root, int data) {
		if (root == NULL) {
			return NULL;
		}
		else if (root->data > data) {
			root->left = deleteNode(root->left, data);
			return root;
		}
		else if (root->data < data) {
			root->right = deleteNode(root->right, data);
			return root;
		}
		else {
			if (root->left == NULL && root->right == NULL) {
				delete root;
				return NULL;
			}
			else if (root->right == NULL) {
				Node* temp = root->left;
				delete root;
				return temp;
			}
			else if (root->left == NULL) {
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else {
				Node* temp = getMin(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
				return root;
			}
		}
	}

	int Size(Node* n, int a, int b) {
		if (n == NULL) {
			return max(a, b);
		}
		a = Size(n->left, ++a, b);
		b = Size(n->right, a, ++b);
		return max(a, b);
	}

	bool isBalansed(Node* n) {
		if (n == NULL) {
			return true;
		}
		bool first = (abs(getSubtreeHeight(n->left) - getSubtreeHeight(n->right)) <= 1);
		bool l = isBalansed(n->left);
		bool r = isBalansed(n->right);
		return l && r && first;
	}
};



int main()
{
	Tree* tree = new Tree();
	int n;
	cin >> n;
	int a[10000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tree->root = tree->add(tree->root, a[i]);
	}
	
}