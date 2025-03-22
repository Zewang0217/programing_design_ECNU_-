/*
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void solve_cases(const vector<pair<int, int>>& cases) {
	for (size_t idx = 0; idx <= cases.size() - 1; idx++) {
		int N = cases[idx].first, S = cases[idx].second;
		vector<tuple<int, int, int>> solutions;

		for (int x = 0; x <= N; x++) {
			int y = (S - 3 * x) - (N - x);
			int z = N - x - y;
			if (y >= 0 && z >= 0 && 3 * x + 2 * y + z == S) {
				solutions.emplace_back(x, y, z);
			}
		}

		cout << "case #" << idx << ":" << endl;

		if (!solutions.empty()) {
			for (const auto& t : solutions) {
				cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
			} 
		}
		else {
			cout << "-1" << endl;
		}
	}
}

int main() {
	int T;
	cin >> T;
	vector<pair<int, int>> cases(T);
	for (int i = 0; i < T; i++) {
		cin >> cases[i].first >> cases[i].second;
	}

	solve_cases(cases);
	return 0;
}
*/