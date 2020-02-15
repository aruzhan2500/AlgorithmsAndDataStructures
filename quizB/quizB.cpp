#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	cout << s.substr(3, s.size() - 4);
	return 0;
}