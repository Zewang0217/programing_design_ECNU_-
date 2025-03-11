/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct num {
	long long n;
	int count;
};

int countSetBits(long long n) {
	int count = 0;
	// 64 λ����
	for (int i = 0; i < 64; i++) {
		if (n & (1LL << i)) { //1LL ָlong long ��һ��������ֵΪһ����64λ��
			count++;
		}
	}
	return count;
}

bool cmp(const num& a, const num& b) {
	if (a.count != b.count) {
		return a.count > b.count;
	}
	else {
		return a.n < b.n;
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n; 
		cin >> n;

		vector<num> nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i].n;
			nums[i].count = countSetBits(nums[i].n);
		}

		sort(nums.begin(), nums.end(), cmp);

		cout << "case #" << t << ":" << endl;
		bool first = true;
		for (int i = 0; i < n; i++) {
			if (!first) cout << " ";
			first = false;
			cout << nums[i].n;
		}
		cout << endl;
	}
}
*/