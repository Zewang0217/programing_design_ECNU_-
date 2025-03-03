/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(int a, int b) {
	int A = a % 10;
	int B = b % 10;
	if (A != B) {
		return A < B;
	}
	else {
		return a < b;
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int j = 0; j < n; j++) {
			cin >> nums[j];
		}
		sort(nums.begin(), nums.end(), cmp);
		
		cout << "case #" << i << ":" << endl;
		cout << nums[0];
		int lastNumber = nums[0];
		if (n > 1) {
			for (int j = 1; j < n; j++) {
				if (nums[j] != lastNumber) {
					cout << " " << nums[j];
					lastNumber = nums[j];
				}
			}
		}
		
		cout << endl;
	}
}

*/