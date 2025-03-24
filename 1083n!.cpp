/*
#include <iostream>
using namespace std;

int FactorialZeros(int x) {
	int countZeros = 0;
	long long tmp = 1;
	for (int i = x; i >= 1; i--) {
		tmp *= i;
		if (tmp % 10 == 0 && tmp >= 10) {
			countZeros++;
			tmp /= 10;
		}
	}
	return countZeros;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int x;
		cin >> x;
		int res = FactorialZeros(x);
		cout << "case #" << t << ":" << endl;
		cout << res << endl;
	}
}
*/