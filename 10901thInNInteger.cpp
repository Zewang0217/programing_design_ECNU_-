/*
#include <iostream>
#include <string>
using namespace std;
int countOnes(int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		string num = to_string(i);
		for (const char& ch : num) {
			if (ch == '1') count++;
		}
	}
	return count;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		int res = countOnes(n);
		cout << "case #" << t << ":" << endl;
		cout << res << endl;
	}
}
*/