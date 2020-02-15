#include <iostream>
#include <map>
#include <cstring>

using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) {
		val = x;
		left = right = NULL;
	}
};

void insert(int x, TreeNode* root) {
	TreeNode* cur = new TreeNode(x);
	if (root == NULL) {
		root = cur;
		return;
	}
	else if (x < root->val) {
		insert(x, root->left);
	}
	else insert(x, root->right);
}

TreeNode* invertTree(TreeNode* root) {
	if (root == NULL) {
		return NULL;
	}
	TreeNode* ch = new TreeNode(NULL);
	ch = root->left;
	root->left = root->right;
	root->right = ch;
	invertTree(root->left);
	invertTree(root->right);
	return root;

}

void Order(TreeNode* &root) {
	if (root == NULL) return;
	Order(root->left);
	printf("%d\n", root->val);
	Order(root->right);
}

int main() {
	TreeNode* root = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		insert(x, root);
	}
	TreeNode* ans = invertTree(root);
	Order(ans);
}