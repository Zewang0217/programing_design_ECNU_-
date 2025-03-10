/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getHighest(long long a) {
	if (a < 0) a = -a;
	while (a >= 10) {
		a = a / 10;
	}
	return a;
}

bool cmp(long long a, long long b) {
	int highestA = getHighest(a);
	int highestB = getHighest(b);

	if (highestA != highestB) {
		return highestA > highestB;
	}
	else {
		return a < b;
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		vector<long long> nums(N);
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}

		sort(nums.begin(), nums.end(), cmp);

		cout << "case #" << t << ":" << endl;
		bool first = true;
		for (int i = 0; i < N; i++) {
			if (!first) cout << " ";
			cout << nums[i];
			first = false;
		}
		cout << endl;
	} 
}
*/