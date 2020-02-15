#include <iostream>//gasd asdf
#include<vector>
#include <algorithm>
using namespace std;
vector <int> prefix(string s) {
	int n = s.size();
	vector <int> p(n);
	p[0] = 0;
	for (int i = 1; i < n; i++) {
		int k = p[i - 1];
		while (k > 0 && s[i] != s[k]) {
			k = p[k - 1];
		}
		if (s[i] == s[k])
			k++;
		p[i] = k;
	}
	return p;
}
int main() {
	string s1, t;
	int n;
	string s;
	int cnt = 0;
	cin >> s1 >> n;
	vector<string > h;

	s1[0] = s1[0] + 'A' - 'a';
	for (int i = 0;i < n;i++) {
		cin >> t;
		t[0] = t[0] - 'A' + 'a';
		s = t + "#" + s1;
		int l = s.size();
		vector<int> p = prefix(s);
		if (p[l - 1] > 0) {
			cnt++;
			t[0] = t[0] + 'A' - 'a';
			h.push_back(t);
		}
	}
	cout << cnt << endl;
	for (int i = 0;i < cnt;i++) {
		cout << h[i] << endl;
	}

	return 0;
}
