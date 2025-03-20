#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int CountOnesInChar(char c) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		if (c & (1 << i)) {
			count++;
		}
	}
	return count;
}

int CountOnesInString(string line) {
	int count = 0;
	for (char c : line) {
		count += CountOnesInChar(c);
	}
	return count;
}

//求最大公约数
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int T;
	cin >> T;
	cin.ignore();

	for (int t = 0; t < T; t++) {
		string line;
		getline(cin, line);

		int totalCount = CountOnesInString(line);
		int totalNums = line.length() * 8;
		int devisor = gcd(totalCount, totalNums);
		cout << totalCount / devisor << "/" << totalNums / devisor << endl;
	}
	return 0;
}