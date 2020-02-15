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
	int n;
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		string s; 
		cin >> s;
		vector<int> p = prefix_func(s);
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 1) k = i;
		}
		cout << p.size() / k - 1;
	}
	return 0;
}