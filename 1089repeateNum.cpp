/*
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		unordered_map<int, int> countRepeate;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			countRepeate[num]++;
		}

		int max = 0;
		for (const auto& n : countRepeate) {
			max = (max > n.second) ? max : n.second;
		}

		cout << "case #" << t << ":" << endl;
		cout << max << endl;
	}
}
*/