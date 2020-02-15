#include <iostream>
using namespace std;

int min(int x, int y) {
	if (x > y) return y;
	return x;
}

int nearest(int *a, int l, int x) {
	if (l == 0) return a[0];
	return x + min(a[l] - x, x - a[l - 1]);
}

int find(int* a, int n, int x) {
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (x > a[mid]) l = mid + 1;
		r = mid;
	}
	if (a[l] == x) return x;
	return nearest(a, l, x);
}

int main()
{
	int n, k;
	cin >> n >> k;
	int a[1000000], b[1000000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> b[i];
		cout << find(*a, n, b[i]);
	}
	return 0;
}
