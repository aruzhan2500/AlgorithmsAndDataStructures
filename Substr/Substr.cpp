//кате не полностью только 2 стринга гана жумыс жасайды
#include <iostream>
#include <vector>

using namespace std;

vector<int> preffix_func(string s) {
	int n = s.size();
	vector<int>p(n);
	p[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = p[i - 1];
		while (j > 0 && s[j] != s[i])
			j = p[j - 1];
		if (s[i] == s[j])
			j++;
		p[i] = j;
	}
	return p;
}
int main() {
	string s, word1, word2;
	int n;

	word1 + word2 = s;
	cin >> s >> n >> word1 >> word2;
	vector <int> p = preffix_func(s);
	for (int i = 0; i < s.size(); i++) {
		while (word1 + word2 == s) {
			break;
		}
		if (word1 + word2 == s) {
			cout << "YES" << endl;
		}
		else cout << "No" << endl;
	}

}