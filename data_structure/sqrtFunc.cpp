#include <iostream>
using namespace std;
int main() {
	int x;
	cin >> x;

	if (x < 2) {
		cout << x << endl;
		return 0;
	}

	int left = 0, right = x / 2;
	int res = 0;
	while (left <= right) {
		long long mid = left + (right - left) / 2;
		if (mid * mid < x) {
			res = mid; // 向下取整
			left = mid + 1;
		}
		else if (mid * mid > x) {
			right = mid - 1;
		}
		else {
			res = mid;
			break;
		}
	}

	cout << res << endl;
}