/*
#include <iostream>
#include <string>
using namespace std;

void ROT13(string& words) {
	for (char& c : words) {
		if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M')) {
			c = c + 13;
		}
		else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z')) {
			c = c - 13;
		}
		else {
			continue;
		}
	}
}

int main() {
	int T;
	cin >> T;
	cin.ignore();

	for (int t = 0; t < T; t++) {
		string words;
		getline(cin, words);
		ROT13(words);
		cout << "case #" << t << ":" << endl;
		cout << words << endl;
	}
}
*/