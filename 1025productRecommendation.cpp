/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct product {
	string id;
	int sale;
	double price;
};

bool cmp(const product& a, const product& b) {
	if (a.sale != b.sale) {
		return a.sale > b.sale;
	}
	else {
		return a.price < b.price;
	}
}

double getMedian(vector<double> nums) {
	size_t size = nums.size();
	double median = 0;
	sort(nums.begin(), nums.end());
	if (size % 2 == 0) {
		median = (float)(nums[size / 2] + nums[size / 2 - 1]) / 2.0;
	}
	else {
		median = nums[size / 2];
	}
	return median;
}

double getPriceMedian(vector<product> products) {
	vector<double> prices;
	for (const auto& product : products) {
		prices.push_back(product.price);
	}
	return getMedian(prices);
}

double getSaleMedian(vector<product> products) {
	vector<double> sales;
	for (const auto& product : products) {
		sales.push_back(product.sale);
	}
	return getMedian(sales);
}

bool isRecommended(product p, double priceMedian, double saleMedian) {
	if (p.price < priceMedian && p.sale > saleMedian) {
		return true;
	}
	return false;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		vector<product> p;
		for (int i = 0; i < n; i++) {
			product P;
			cin >> P.id >> P.sale >> P.price;
			p.push_back(P);
		}

		cout << "case #" << t << ":" << endl;



		double priceMedian = getPriceMedian(p);
		double saleMedian = getSaleMedian(p);

		sort(p.begin(), p.end(), cmp);

		int recommendationCount = 0;
	    for (const auto& product : p) {
			if (isRecommended(product, priceMedian, saleMedian)) {
				recommendationCount++;
				cout << product.id << " " << product.sale
					<< " " << product.price << endl;
			}
		}
		if (recommendationCount == 0) {
			cout << "no recommendation" << endl;
		}
	}
}
*/