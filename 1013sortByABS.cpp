/*#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(int a, int b) {
	return abs(a) < abs(b);
}

int main() {
	int T;
	while (cin >> T) {
		vector<int> nums;
		for (int t = 0; t < T; t++) {
			int n;
			cin >> n;
			nums.push_back(n);
		}
		sort(nums.begin(), nums.end(), cmp);
		for (int i = 0; i < T; i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}
	
}
*/