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
	int n;
	cin >> n;
	int max = 0;
	int cnt = 0;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	string t;
	cin >> t;
	vector<int> count;
	vector<string> res;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		string s1 = v[i] + "#" + t;
		vector<int> p = prefix_func(s1);
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == v[i].size()) {
				cnt++;
			}
		}
		count.push_back(cnt);
		res.push_back(v[i]);
		if (cnt > max) {
			max = cnt;
		}
	}
	
	cout << max << endl;
	for (int i = 0; i < n; i++) {
		if (count[i] == max) {
			cout << res[i] << endl;
		}
	}
	return 0;
}