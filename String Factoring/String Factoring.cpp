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
    
}