/*
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	bool found = false;
	for (long long i = 1000; i < 10000; i++) {
		long long num = i;
		int A = num % 10;
		num /= 10;
		int B = num % 10;
		num /= 10;
		int C = num % 10;
		num /= 10;
		int D = num;
		if (A * A * A * A + B * B * B * B + C * C * C * C + D * D * D * D == i) {
			found = true;
			cout << i << endl;
		}

	}
	if (!found) {
		cout << "no answer" << endl;
	}
	return 0;
}
*/