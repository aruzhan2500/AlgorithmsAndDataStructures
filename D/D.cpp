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
	int n, m;
	cin >> n >> m;
	vector<string> s1;
	vector<string> s2;
	string s = "";
	bool res;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		s1.push_back(t);
	}
	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < n; j++) {
			res = false;
			s = s1[j] + "#" + t;
			vector<int> p = prefix_func(s);
			for (int k = 0; k < p.size(); k++) {
				if (s1[j].size() == p[k] && s1[j].size() < t.size()) {
					res = true;
				}
			}
		}
		if (res == true) cout << "YES";
		else cout << "NO";
	}
	return 0;
}