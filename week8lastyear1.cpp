#include <iostream>
#include <utility>
#include <vector>

using namespace std;
bool field[1001][1001];
vector<pair<int, int>> points;

void solve() {
	int count = 0;
	vector<int> row(1001, 0);
	vector<int> col(1001, 0);

	for (const auto& p : points) {
		field[p.first][p.second] = true;
		col[p.first]++;
		row[p.second]++;
	}

	for (const auto& p : points) {
		if (col[p.first] == 1 && row[p.second] == 1) {
			for (int i = 0; i < 1001; i++) {
				if (row[i] == 1) field[p.first][i] = true;
				col[p.first]++;
				row[i]++;
				count++;
			}
		}
	}

	cout << count;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points.emplace_back(x, y);
	}

	solve();
}