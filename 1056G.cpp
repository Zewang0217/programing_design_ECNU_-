/*
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double cauculateT(double H) {
	double T = sqrt(2 * H / 9.8);
	return T;
}

double cauculateH(int n) {
	if (n < 0) return -1;
	if (n == 0) return 0;
	else if (n == 1) return 1.75;
	else if (n == 2) return 6.75;
	else return (n - 3) * 3 + 11.75;
}

int main() {
	int n;
	cin >> n;
	double H = cauculateH(n);

	double T = cauculateT(H);
	cout << fixed << setprecision(3) << T << endl;
}
*/