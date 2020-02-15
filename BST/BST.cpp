#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		left = right = nullptr;
	}
};

Node* add(Node* root, int data) {
	if (root == nullptr) return new Node(data);
	if (data < root->data) {
		if (root->left == nullptr) {
			root->left = new Node(data);
		}
		else add(root->left, data);
	}
	else if (data > root->data) {
		if (root->right == nullptr) {
			root->right = new Node(data);
		}
		else add(root->right, data);
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

int main()
{
	int n;
	cin >> n;
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		root = add(root, x);
	}
	cout << endl;
	print(root);
}