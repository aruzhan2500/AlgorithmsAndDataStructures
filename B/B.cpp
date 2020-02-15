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
	string t;
	cin >> t;
	int n;
	cin >> n;
	vector<int> p1;
	vector<int> p2;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		string s1 = s + "#" + t;
		p1 = prefix_func(s1);
		for (int j = 0;j < s1.size();j++) {
			p2.push_back(0);
		}
		for (int j = 0; j < p1.size(); j++) {
			p2[j] += p1[j];
		}
	}
	bool res = true;
	for (int j = p1.size() - t.size(); j < p1.size(); j++) {
		if (p2[j] == 0) {
			res = false;
			break;
		}
		else res = true;
	}
	if (res) cout << "YES";
	else cout << "NO";
	return 0;
}