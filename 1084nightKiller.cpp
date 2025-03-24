/*
#include <iostream>
#include <vector>
using namespace std;

int kill(int n, int m) {
	if (n == 1) return 1;
	vector<bool> alive(n, true);
	int count = 0; // 记录数了多少次
	int index = 0; // 记录位置
	int remaining = n;

	while (remaining > 1) {
		if (alive[index]) {
			count++;
			if (count == m) {
				alive[index] = false;
				count = 0; // 重新计数
				remaining--; //存活减少
			}
		}
		index = (index + 1) % n; // 更新索引
	}

	for (int i = 0; i < n; i++) {
		if (alive[i]) {
			return i + 1;
		}
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int m, n;
		cin >> n >> m;
		int res = kill(n, m);
		cout << "case #" << t << ":" << endl;
		cout << res << endl;
	}
}
*/