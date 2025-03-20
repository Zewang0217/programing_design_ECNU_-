/*
#include <vector>
#include <iostream>

using namespace std;

vector<int> countMoney(int n) {
	vector<int> money(6, 0);
	while (n >= 100) {
		money[0]++;
		n -= 100;
	}
	while (n >= 50) {
		money[1]++;
		n -= 50;
	}
	while (n >= 20) {
		money[2]++;
		n -= 20;
	}
	while (n >= 10) {
		money[3]++;
		n -= 10;
	}
	while (n >= 5) {
		money[4]++;
		n -= 5;
	}
	money[5] = n;
	return money;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int money;
		cin >> money;
		vector<int> res = countMoney(money);
		
		bool first = true;
		cout << "case #" << t << ":" << endl;
		for (int i = 0; i < 6; i++) {
			if (!first) {
				cout << " ";
			}
			first = false;
			cout << res[i];
		}
		cout << endl;
	}
}
*/