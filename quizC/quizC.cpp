#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	stack<int> s1;
	stack<int> s2;
	int n;
	cin >> n;
	vector<int> num;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		num.push_back(x);
	}
	if (num[0] == 1) {
		s1.push(num[0]);
	}
	else s2.push(num[0]);
	for (int i = 1; i < num.size(); i++) {
		if (num[i - 1] + 1 == num[i]) {
			s1.push(num[i]);
		}
		else {
			s2.push(num[i]);
		}
	}
	while (!s2.empty()) {
		if (s2.top() - 1 == s1.top()) {
			s1.push(s2.top());
			s2.pop();
		}
	}
	if (s2.empty()) cout << "yes";
	else cout << "no";
	return 0;
}