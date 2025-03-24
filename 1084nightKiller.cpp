/*
#include <iostream>
#include <vector>
using namespace std;

int kill(int n, int m) {
	if (n == 1) return 1;
	vector<bool> alive(n, true);
	int count = 0; // ��¼���˶��ٴ�
	int index = 0; // ��¼λ��
	int remaining = n;

	while (remaining > 1) {
		if (alive[index]) {
			count++;
			if (count == m) {
				alive[index] = false;
				count = 0; // ���¼���
				remaining--; //������
			}
		}
		index = (index + 1) % n; // ��������
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