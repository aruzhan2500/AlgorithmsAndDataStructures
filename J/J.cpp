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
	vector<string> text;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "add") {
			string t;
			cin >> t;
			text.push_back(t);
		}
		if (s == "find") {
			string str;
			cin >> str;
			int cnt = 0;
			int counter = 0;
			for (int i = 0; i < text.size(); i++) {
				string pref = str + "#" + text[i];
				vector<int> p = prefix_func(pref);
				for (int j = 0; j < p.size(); j++) {
					if (p[j] == str.size()) {
						cnt++;
					}
				}
				if (cnt > 0) counter++;
			}
			cout << counter << endl;
		}
	}
	return 0;
}