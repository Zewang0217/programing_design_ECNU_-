/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// a >= b
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		vector<int> nums;
		unordered_set<int> unique_nums;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if (unique_nums.insert(tmp).second) {
				nums.push_back(tmp);
			}
		}

		sort(nums.begin(), nums.end());
		int newSize = nums.size();
	    
		int count = 0;
		for (int i = 0; i < newSize; i++) {
			for (int j = i; j < newSize; j++) {
				if (i == j) continue;
				if (gcd(nums[j], nums[i]) == 1) count++;
			}
		}
		cout << "case #" << t << ":" << endl;
		cout << count << endl;
	}
}
*/