/*
#include <vector>
#include <iostream>

using namespace std;

// �ж��Ƿ��Ǽ�ͦ��
bool isSturdy(int n) {
	int pos = n; // ��¼ÿһ��ɾȥ���λ��
	int step = 2; // ��¼ÿһ��ɾ���Ĳ���
	while (step <= pos) {
		if (pos % step == 0) { // �����һ�ֻᱻɾ��
			return false;
		}
		// ���ᱻɾ��������ɾ��Ԫ���ų���������һ��������һ��
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