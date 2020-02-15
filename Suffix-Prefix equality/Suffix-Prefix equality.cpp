#include <iostream>
using namespace std;
int main() {
	string word;
	cin >> word;
	string sorted_word = "";
	for (int i = 0; i < word.size() / 2; i++) {
		if (word[i] != 'E' && word[i] != 'A' && word[i] != 'a' && word[i] != 'U' && word[i] != 'O' && word[i] != 'o' && word[i] != 'I' && word[i] != 'i' && word[i] != 'e' && word[i] != 'u') {
			sorted_word += word[i];
		}
	}
	for (int i = word.size() - 1; i >= word.size() / 2; i--) {
		sorted_word += word[i];
	}
	if (sorted_word[0] <= 'z' && sorted_word[0] >= 'a') {
		sorted_word[0] = sorted_word[0] - 'a' + 'A';
	}
	cout << sorted_word;
	return 0;
}