#include <iostream>
using namespace std;
#define MAXN 100000

bool find(int* a, int n, int x) {
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (x <= a[mid]) r = mid;
		else l = mid + 1;
	}
	if (a[l] == x) return true;
	return false;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int a[MAXN], b[MAXN];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> b[i];
		if (find(a, n, b[i])) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}