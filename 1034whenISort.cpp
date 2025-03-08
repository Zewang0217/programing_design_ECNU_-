/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct num {
	int value;
	int originPosition;
	int afterPosition;
};

bool cmp1(const num& a, const num& b) {
	if (a.value != b.value) {
		return a.value < b.value;
	}
	else {
		return a.originPosition < b.originPosition;
	}
}

bool cmp2(const num& a, const num& b) {
		return a.originPosition < b.originPosition;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		vector<num> nums(N);

		for (int i = 0; i < N; i++) {
			cin >> nums[i].value;
			nums[i].originPosition = i;
		}

		sort(nums.begin(), nums.end(), cmp1);

		for (int i = 0; i < N; i++) {
			nums[i].afterPosition = i;
		}

		sort(nums.begin(), nums.end(), cmp2);


		for (int i = 0; i < N; i++) {
			cout << nums[i].afterPosition << " ";
		}
		cout << endl;
	}
}
*/