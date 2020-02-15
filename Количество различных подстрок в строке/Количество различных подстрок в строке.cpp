#include<iostream>

using namespace std;
int f(string s, string t) {
	int p = 31;

	int p_i[s.size() + 1];
	p_i[0] = 1;

	for (int i = 1; i <= s.size(); ++i) {
		p_i[i] = p_i[i - 1] * p;
	}

	int h_p[s.size()];
	h_p[0] = s[0] - 'a' + 1;

	for (int i = 1; i < s.size(); ++i) {
		h_p[i] = h_p[i - 1] + p_i[i] * (s[i] - 'a' + 1);
	}

	int x, y;

	int ht = t[0] - 'a' + 1;
	for (int i = 1; i < t.size(); ++i) {
		ht += p_i[i] * (t[i] - 'a' + 1);
	}
	int f = 0;
	for (int i = 0; i <= s.size() - t.size(); ++i) {
		if (i == 0) {
			x = 0;
		}
		else {
			x = h_p[i - 1];
		}
		y = h_p[i + t.size() - 1];
		if (y - x == ht * p_i[i]) {
			f = f + 1;
		}
	}
	return f;
}

int main() {

	// freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s, t;
	int cnt = 1;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		t = s.substr(i, s.size());
		cnt = cnt + f(s, t);

	}

	cout << cnt;
	return 0;
}