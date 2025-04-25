#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int a, b;
		cin >> a >> b;
		cout << "case #" << t << ":" << endl;
		cout << lcm(a, b) << endl;
	}
}