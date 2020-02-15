#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <istream>
using namespace std;

vector<string> a;
int n;

void merge(int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	string L[n1];
	string R[n2];
	for (int i = 0; i < n1; i++) {
		L[i] = a[l + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = a[m + 1 + i];
	}
	int uk1 = 0;
	int uk2 = 0;
	int k = l;
	while (uk1 < n1 && uk2 < n2) {
		if (L[uk1].length() <= R[uk2].length()) {
			a[k] = L[uk1];
			uk1++;
		}
		else {
			a[k] = R[uk2];
			uk2++;
		}
		k++;
	}
	while (uk1 < n1) {
		a[k] = L[uk1];
		uk1++;
		k++;
	}
	while (uk2 < n2) {
		a[k] = R[uk2];
		uk2++;
		k++;
	}
}

void mergesort(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergesort(l, m);
		mergesort(m + 1, r);
		merge(l, m, r);
	}
}

int main()
{
	int n;
	cin >> n;
	string s[n];
	vector<string> result[n];
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
		string str = s[i];
		for (int j = 0; j < s[i].length(); j++) {
			string substring = "";
			while (str[j] != " ") {
				substring += str[j];
				j++;
			}
			result[i].push_back(substring);
		}
	}
	for (int i = 0; i < result[i].size(); i++) {
		a[i] = result[i][i];
		mergesort(0, result[i].size() - 1);
		cout << a[i];
	}
}