#include <iostream>
#include <vector>

using namespace std;

vector<int> get_hash(string s) {
	int n = s.size();
	int p = 31;
	int p_pow = 1;
	vector<int> h(n);
	h[0] = s[0];
	for (int i = 0; i < s.size(); i++) {
		p_pow *= p;
		h[i] = h[i - 1] + s[i] * p_pow;
	}
	return h;
}

int main()
{
	string t, s;
	cin >> t >> s;
	int n = t.size();
	int m = s.size();
	int h_s = get_hash(s)[s.size() - 1];
	vector<int> h_t = get_hash(t);
	vector<int> p(n);
	p[0] = 1;
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] * 31;
	}
	for (int i = 0; i < n - m + 1; i++) {
		int j = i + m - 1;
		int hash_i_j = h_t[j];
		if (i > 0) {
			hash_i_j = hash_i_j - h_t[i - 1];
		}
		if (hash_i_j == h_s * p[i]) {
			cout << i << " ";
		}
	}
	return 0;
} 