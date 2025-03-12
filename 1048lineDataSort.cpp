/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
	int size = min(a.size(), b.size());
	for (int i = 0; i < size; i++) {
		if (a[i] != b[i]) return a[i] > b[i];
	}
	return a.size() > b.size();
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		cin.ignore();

		vector<vector<int>> lines(n);
		for (int i = 0; i < n; i++) {
			int tmp;
			while (cin >> tmp) {
				if (tmp == -1) break;
				lines[i].push_back(tmp);
			}
		}

		sort(lines.begin(), lines.end(), cmp);

		for (int i = 0; i < n; i++) {
			for (int j = 0, s = lines[i].size(); j < s; j++) {
				cout << lines[i][j] << " ";
			}
			cout << endl;
		}
	}
}
*/