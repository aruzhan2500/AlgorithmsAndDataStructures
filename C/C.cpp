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
	int n = 0;
	string s1 = "";
	for (char i = 'A'; i <= 'Z'; i++) {
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == i) {
				s1 = s.substr(j) + "#" + t;
				n = j;
			}
		}
	}
	vector<int> p = prefix_func(s1);
	bool res = false;
	for (int i = s.size() - n; i < p.size(); i++) {
		if (p[i] == s.size() - n) {
			res = true;
		}
	}
	if (res == true) cout << "YES";
	else cout << "NO";
	return 0;
}