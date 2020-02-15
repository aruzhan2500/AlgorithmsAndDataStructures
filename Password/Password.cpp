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
	int n;
	string t;
	cin >> s >> n >> t;
	int cnt = 0;
	string s1 = s + "#" + t;
	vector<int> v = prefix_func(s1);
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == s.size()) {
			cnt++;
		}
	}
	if (cnt > n) cout << "YES";
	else cout << "NO";
}