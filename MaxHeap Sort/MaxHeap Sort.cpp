#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
public:
	vector<int> a;
	int sz;

	MaxHeap() {
		sz = 0;
	}

	int parent(int i) {
		return (i - 1) / 2;
	}

	int left(int i) {
		return 2 * i + 1;
	}

	int right(int i) {
		return 2 * i + 2;
	}

	int getMax() {
		return a[0];
	}

	void insert(int k) {
		a.push_back(k);
		sz++;
		int i = sz - 1;
		while (i > 0 && a[parent(i)] < a[i]) {
			swap(a[parent(i)], a[i]);
			i = parent(i);
		}
	}

	void heapify(int i) {
		if (left(i) > sz - 1) 
			return;
		int j = left(i);
		int maxi = a[left(i)];
		if (right(i) < sz && a[right(i)] > maxi) {
			maxi = a[right(i)];
			j = right(i);
		}
		if (a[i] < a[j]) {
			swap(a[i], a[j]);
			heapify(j);
		}
	}

	void decreaseKey(int i, int new_value) {
		a[i] = new_value;
		heapify(i);
	}

	void increaseKey(int i, int new_value) {
		a[i] = new_value;
		while (i > 0 && a[parent(i)] < a[i]) {
			swap(a[parent(i)], a[i]);
			i = parent(i);
		}
	}

	void print() {
		for (int i = 0; i < sz; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}

	int extractMax() {
		int root_value = a[0];
		swap(a[0], a[sz - 1]);
		sz--;
		heapify(0);
		return root_value;
	}
};
int main()
{
	MaxHeap* maxHeap = new MaxHeap();
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		maxHeap->insert(k);
	}

	for (int i = 0; i < n; i++) {
		cout << maxHeap->extractMax() << " ";
	}
	return 0;
}