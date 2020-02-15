#include <iostream>
#include <vector>
using namespace std;
vector<int> prefix_func(string s) {
	int n = s.size();
	vector<int> p(n);
	p[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = p[i - 1];
		while (j > 0 && s[j] != s[i])
			j = p[j - 1];
		if (s[j] == s[i])
			j++;
		p[i] = j;
	}
	return p;
}

int main() {
	int n, m;
	cin >> n >> m;
	string a[n];
	string b[m];
	for (int i = 0;i < n;i++) {
		string x;
		cin >> x;
		a[i] = x;
	}
	for (int i = 0;i < m;i++) {
		string x;
		cin >> x;
		b[i] = x;
	}
	for (int i = 0;i < m;i++) {
		int cnt = 0;
		for (int j = 0;j < n;j++) {
			string s1 = b[i] + "#" + a[j];
			vector<int> p = prefix_func(s1);
			int x = p[b[i].size() + b[i].size()];
			int y = b[i].size();
			if (x == y)
				cnt++;
		}cout << cnt << endl;
	}
}