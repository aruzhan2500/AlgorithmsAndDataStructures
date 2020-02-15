#include <iostream>
using namespace std;

int find(int n) {
	int l = 0;
	int r = n - 1;
	int cnt = 0;
	while (l < r) {
		int mid = (l + r) / 2;
		cnt++;
		r = mid;
	}
	return cnt;
}
int main()
{
	int n;
	cin >> n;
	cout << find(n);
}