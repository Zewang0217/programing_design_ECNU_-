/*
#include <iostream>
#include <string>
using namespace std;

string proccess(string plaintext, string key) {
	string ciphertext = "";
	int i = 0;
	for (auto& ch : plaintext) {
		if (ch == ' ') {
			ciphertext += ' ';
			continue;
		}
		int shift = key[i % key.length()]  - 'A';
		char encrypted = ((ch - 'A' + shift) % 26) + 'A';
		ciphertext += encrypted;
		i++;
	}
	return ciphertext;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin.ignore();
		string plaintext;
		string key;
		getline(cin, plaintext);
		cin >> key;

		string ciphertext;
		ciphertext = proccess(plaintext, key);

		cout << "case #" << t << ":" << endl;
		cout << ciphertext << endl;
	}
}
*/