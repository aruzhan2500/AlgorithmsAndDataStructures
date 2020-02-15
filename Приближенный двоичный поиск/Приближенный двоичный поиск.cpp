#include <iostream>
using namespace std;

#define MAXN 100000

int nearest(int* a, int l, int x) {
	if (l == 0) return a[0];
	int d1 = x - a[l - 1];
	int d2 = a[l] - x;
	if (d2 >= d1) return a[l - 1];
	return a[l];
}

int find(int *a, int n, int x) {
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (x <= a[mid]) {
			r = mid;
		}
		else l = mid + 1;
	}
	if (a[l] == x) return x;
	return nearest(a, l, x);
}

int main()
{
	int n, k;
	cin >> n >> k;
	int a[MAXN];
	int b[MAXN];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> b[i];
		cout << find(a, n, b[i]) << endl;
	}
	return 0;
}
