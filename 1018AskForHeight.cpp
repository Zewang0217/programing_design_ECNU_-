/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct player {
	int index;
	int height;
};

int cmp(player a, player b) {
	return a.height > b.height;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		vector<player> players(n);
		for (int j = 0; j < n; j++) {
			cin >> players[j].height;
			players[j].index = j;
		}
		sort(players.begin(), players.end(), cmp);

		for (int j = 0; j < m; j++) {
			cin >> n;
			cout << players[n - 1].index + 1 << " ";
		}
		cout << endl;
	}
}
*/