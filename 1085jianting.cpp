/*
#include <vector>
#include <iostream>

using namespace std;

// 判断是否是坚挺数
bool isSturdy(int n) {
	int pos = n; // 记录每一轮删去后的位置
	int step = 2; // 记录每一轮删除的步长
	while (step <= pos) {
		if (pos % step == 0) { // 如果这一轮会被删除
			return false;
		}
		// 不会被删除，将被删除元素排除，步长加一，开启下一轮
		pos -= pos / step;
		step++;
	}
	return true;
}

int getSturdyIndex(int n) {
	if (n == 1) return 1;
	vector<int> sturdy = { 1 };
	int current = 3;
	while (current <= n) {
		if (isSturdy(current)) {
			sturdy.push_back(current);
			if (current == n) {
				return sturdy.size();
			}
		}
		current += 2;
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		cout << "case #" << t << ":" << endl;
		if (!isSturdy(n)) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << " " << getSturdyIndex(n) << endl;
		}
	}
}
*/