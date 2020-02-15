#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_func(string s) {
	int n = s.size();
	vector<int> p(n);
	p[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		p[i] = j;
	}
	return p;
}

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	vector<int> p = prefix_func(s);
	vector<int> ans(n + 1);
	for (int i = 0; i < n; ++i) {
		++ans[p[i]];
	}
	for (int i = n - 1; i > 0; --i) {
		ans[p[i - 1]] += ans[i];
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
	}
	return 0;
}