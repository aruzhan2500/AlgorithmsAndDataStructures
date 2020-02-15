#include <iostream>
using namespace std;

#define MAXN 1000;

class Node {
public:
	int data;
	Node* next;
	int cnt;

	Node(int data) {
		this->data = data;
		next = NULL;
		cnt = 0;
	}

	int subQuery(Node* root, int x) {
		if (root == NULL) {
			root = new Node(x);
		}
		else if (root->data < x) {
			root->next = new Node(x);
		}
		else if (root->data > x) {
			root->next = new Node(x);
			cnt++;
		}
		return cnt;
	}
};

int main()
{
	Node* root = NULL;
	int n, q;
	cin >> n >> q;
	int b[1000];
	pair<int, int> p[1000];
	int a[1000];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> p[i].first;
		cin >> p[i].second;
	}
	for (int i = 0; i < q; i++) {
		for (int j = p[i].first; j < p[i].second; j++) {
			a[i] = root->subQuery(root, b[j]);
		}
	}
	for (int i = 0; i < q; i++) {
		cout << a[i];
	}
}