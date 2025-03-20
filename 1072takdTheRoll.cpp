/*
#include <iostream>

using namespace std;

int CountAbsentStudent(int row, int col) {
	char ch;
	int absentCount = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> ch;
			if (ch == '.') absentCount++;
		}
	}
	return absentCount;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int row, col;
		cin >> row >> col;
		int res = CountAbsentStudent(row, col);
		cout << "case #" << t << ":" << endl;
		cout << res << endl;
	}
	return 0;
}
*/