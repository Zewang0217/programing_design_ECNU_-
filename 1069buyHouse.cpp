/*
#include <iostream>

using namespace std;

int main() {
	int priceRate, wageRate;
	double wage;
	while (cin >> wage >> priceRate >> wageRate) {
		double money = wage;
		double housePrice = 270;
		bool canBuy = false;
		bool first = true;

		if (money >= housePrice) {
			cout << "1" << endl;
			continue;
		}

		for (int i = 2; i <= 30; i++) {
			wage *= (0.01 * (double)wageRate + 1.0);
			money += wage;
			housePrice *= (0.01 * (double)priceRate + 1.0);
			if (money >= housePrice) {
				cout << i << endl;
				canBuy = true;
				break;
			}
			if (first) continue;

		}
		if (!canBuy) cout << "Impossible" << endl;
	}
	return 0;
}
*/