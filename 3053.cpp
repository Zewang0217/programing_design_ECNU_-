#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

/*
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string s;
		cin >> s;
		unordered_map<char, bool> seen;
		string unique_chars;
		for (char c : s) {
			if (!seen[c]) {
				seen[c] = true;
				unique_chars += c;
			}
		}
		int k = unique_chars.size();
		int base = max(k, 2);
		unordered_map<char, int> char_to_digit;
		char_to_digit[unique_chars[0]] = 1;
		if (k >= 2) {
			char_to_digit[unique_chars[1]] = 0;
		}
		if (k > 2) {
			for (int i = 2; i < k; i++) {
				char_to_digit[unique_chars[i]] = i;
			}
		}
		long long value = 0; 
		for (char c : s) {
			value = value * base + char_to_digit[c];
		}
		cout << "case #" << t << ":" << endl;
		cout << value << endl;
	 }
}*/