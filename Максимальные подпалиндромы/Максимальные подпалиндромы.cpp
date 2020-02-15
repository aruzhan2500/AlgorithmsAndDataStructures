#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s, int l, int r) {
	for (int i = l; i <= r; i++) {
		if (s[i] != s[r - i])
			return false;
	}
	return true;
}

vector<int> prefix_func(string s) {
	int n = s.size();
	vector<int> p(n);
	for (int i = 0; i <= n / 2; i++) {
		 
	}
	return p;
}

int main() {
	string s;
	cin >> s;

}