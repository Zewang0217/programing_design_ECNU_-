/*
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int n;
	cin >> n;

	unordered_set<int> nums;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.insert(num);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int ask;
		cin >> ask;
		if (nums.find(ask) != nums.end()) {
			cout << "yes!" << endl;
		}
		else {
			cout << "no!" << endl;
		}
	}
	return 0;
}
*/