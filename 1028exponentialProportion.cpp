/*
#include <iostream>
#include <vector>
#include<cmath>
#include <algorithm>

using namespace std;

struct num {
	double value;
	double ratio;
};

bool cmp(const num& a, const num& b) {
	return a.value > b.value;
}

double getRatio(vector<num>& nums) {
	double sum = 0;
	for (auto& aNum : nums) {
		sum += exp(aNum.value);
	}
	for (auto& aNum : nums) {
		aNum.ratio = exp(aNum.value) / sum;
	}
	return 0.5 / nums.size();
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		vector<num> nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i].value;
		}

		double ratio = getRatio(nums);

		sort(nums.begin(), nums.end(), cmp);

		cout << "case #" << t << ":" << endl;
		for (const auto& n : nums) {
			if (n.ratio > ratio) {
				cout.precision(2);
				cout << fixed << n.value << endl;
			}
		}
	}
}
*/