/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Classroom {
	long long ID;
	int distance;
	int rows, cols;
	vector<vector<int>> seats;
};

bool cmp(const Classroom& a, const Classroom& b) {
	return a.distance < b.distance;
}

bool isValidSeat(const vector<vector<int>>& seats, int r,
	int c, int rows, int cols) {
	if (seats[r][c] == 1) return false;

	if (c > 0 && seats[r][c - 1] == 1) return false;
	if (c < cols - 1 && seats[r][c + 1] == 1) return false;
	if (r > 0 && seats[r - 1][c] == 1) return false;

	return true;
}

int main() {
	int n;
	while (cin >> n) {
		vector<Classroom> classrooms(n);
		classrooms.resize(n);

		for (int i = 0; i < n; i++) {
			cin >> classrooms[i].ID >> classrooms[i].distance
				>> classrooms[i].rows >> classrooms[i].cols;
			classrooms[i].seats.resize(classrooms[i].rows, vector<int>(classrooms[i].cols));

			
			//∂¡»°æÿ’Û
			for (int r = 0; r < classrooms[i].rows; r++) {
				string row;
				cin >> row;

				for (int c = 0; c < classrooms[i].cols; c++) {
					classrooms[i].seats[r][c] = row[c] - '0';
				}
			}
		}

		sort(classrooms.begin(), classrooms.end(), cmp);

		bool found = false;
		for (const auto& cls : classrooms) {
			for (int r = 0; r < cls.rows; r++) {
				for (int c = 0; c < cls.cols; c++) {
					if (isValidSeat(cls.seats, r, c, cls.rows, cls.cols)) {
						cout << cls.ID << endl;
						found = true;
						break;
					}
				}
				if (found) break;
			}
			if (found) break;
		}

		if (!found) {
			cout << "Bad Luck,Rocker!" << endl;
		}
	}
}
*/