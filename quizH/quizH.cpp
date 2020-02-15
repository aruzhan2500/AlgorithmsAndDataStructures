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
	string s1, s2;
	cin >> s1 >> s2;
	string t;
	cin >> t;
	string text1 = t + "#" + s1;
	vector<int> p1 = prefix_func(text1);
	string text2 = t + "#" + s2;
	vector<int> p2 = prefix_func(text2);
	int cnt = 0;
	for (int i = 0; i < p1.size(); i++) {
		if (p1[i] == t.size() && p2[i] == t.size()) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}