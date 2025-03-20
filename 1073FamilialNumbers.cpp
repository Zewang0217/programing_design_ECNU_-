/*
#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime(10001, true);


vector<bool> sieve() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < 10001; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j < 10001; j += i) {
				isPrime[j] = false;
			}
		}
	}
	return isPrime;
}

bool Family(int a, int b, int& primeFactor) {
	int m = min(a, b);
	for (int i = 2; i < m; i++) {
		if (a % i == 0 && b % i == 0 && isPrime[i]) {
			primeFactor = i;
			return true;
		}
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	sieve();

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		cout << "case #" << t << ":" << endl;
		int primeFactor;
		if (Family(N, M, primeFactor)) {
			cout << "Yes" << " " << primeFactor << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
*/