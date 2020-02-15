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

};

int main()
{
	int n, m;
	cin >> n >> m;
	BST* bst = new BST();
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		bst->root = bst->insert(bst->root, x);
	}
	for (int i = 0;i < m;i++) {
		string s;
		cin >> s;
		Node* node = new Node(1);
		node = bst->root;
		bool b = true;
		for (int i = 0;i < s.size();i++) {
			if (s[i] == 'L') {
				node = node->left;
			}
			else
				if (s[i] == 'R') {
					node = node->right;
				}
			if (node == NULL) {
				b = false;
				break;
			}
		}if (b)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}