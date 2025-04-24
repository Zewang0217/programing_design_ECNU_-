#include <iostream>
#include <set>
using namespace std;

int main() {
	int N;
	cin >> N;
	set<int> nums;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		nums.insert(x);
	}

	bool first = true;
	for (const auto x : nums) {
		if (!first) cout << " ";
		first = false;
		cout << x;
	}
	cout << endl;
}