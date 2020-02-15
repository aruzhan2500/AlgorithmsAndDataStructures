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

int main() {
	string t, s;
	cin >> t >> s;
	string s1 = s + "#" + t + t;
	bool res = false;
	vector<int> p = prefix_func(s1);
	for (int i = 0; i < p.size(); i++) {
		if (s.size() == p[i]) {
			res = true;
		}
	}
	if (res && p[p.size() - 1] != s.size()) cout << p[p.size() - 1];
	else if (res && p[p.size() - 1] == s.size()) cout << 0;
	else cout << -1;
	return 0;
}
