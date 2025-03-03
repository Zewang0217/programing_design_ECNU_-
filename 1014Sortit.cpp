/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	vector<int> nums;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		nums.push_back(n);
	}
	sort(nums.begin(), nums.end(), [](int a, int b) {
		return abs(a) < abs(b);
		});
	cin.ignore();
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		cout << nums[n - 1] << endl;
	}
}
*/