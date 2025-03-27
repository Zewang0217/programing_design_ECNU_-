#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPerfetNum(int n, vector<int>& factors) {
	int sumOfFactors = 0;
	for (const auto& n : factors) {
		sumOfFactors += n;
	}
	if (n == sumOfFactors) return true;
	return false;
}

bool getFactors(int n, vector<int>& factors) {
	if (n == 1) {
		return false;
	}
	int factor = 1;
	while (sqrt(n) >= factor) {
		if (n % factor == 0) {
			factors.push_back(factor);
			if (factor != n / factor && factor != 1) {
				factors.push_back(n / factor);
			}
		}
		factor++;
	}
	return isPerfetNum(n, factors);
}

int main() {
	vector<int> factors;

	for (int i = 1; i <= 4000; i++) {
		if (getFactors(i, factors)) {
			cout << i << " its factors are ";

			sort(factors.begin(), factors.end());

			bool first = true;
			for (const auto& n : factors) {
				if (!first) cout << ",";
				first = false;
				cout << n;
			}
			cout << "." << endl;
		}
		factors.clear();
	}
}