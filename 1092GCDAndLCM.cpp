/*
#include <iostream>

using namespace std;

int cauculateGCD(int a, int b) {
	int GCD = 1;
	int devisor = 2;
	if (min(a, b) == 1) return 1;

	while (devisor <= min(a, b)){
		if (a % devisor == 0 && b % devisor == 0) {
			GCD *= devisor;
			a /= devisor;
			b /= devisor;
			devisor = 2;
			continue;
		}
		devisor++;
	}
	return GCD;
}

int cauculateLCM(int a, int b, int GCD) {
	a /= GCD;
	b /= GCD;
	return a * b * GCD;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int a, b;
		cin >> a >> b;
		int GCD = cauculateGCD(a, b);
		cout << GCD << " " << cauculateLCM(a, b, GCD) << endl;
	}
}
*/