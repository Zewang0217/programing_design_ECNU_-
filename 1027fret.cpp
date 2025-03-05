/*
#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

struct team {
	int score;
	int index;
	int win;
	int lose;
	int tie;
};

int cmp(const team& a, const team& b) {
	if (a.score != b.score) {
		return a.score > b.score;
	}
	else if (a.win != b.win) {
		return a.win > b.win;
	}
	else if (a.lose != b.lose) {
		return a.lose < b.lose;
	}
	else {
		return a.index < b.index;
	}
}

int main() {
	int n, m;
	

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}

		vector<team> teams(n);

		for (int i = 0; i < n; i++) {
			teams[i].index = i + 1;
			teams[i].score = 0;
			teams[i].win = 0;
			teams[i].lose = 0;
			teams[i].tie = 0;
		}

		//读取队伍序号
		for (int i = 0; i < m; i++) {
			int teamIndex1, teamIndex2;
			cin >> teamIndex1 >> teamIndex2;

			if (teamIndex1 == 0 && teamIndex2 == 0) {
				return 0;
			}

			int outcome;
			cin >> outcome;
			//输赢结果判定
			switch (outcome) {
			case 1:
				teams[teamIndex1 - 1].score += 3;
				teams[teamIndex1 - 1].win += 1;
				teams[teamIndex2 - 1].score -= 1;
				teams[teamIndex2 - 1].lose += 1;
				break;
			case -1:
				teams[teamIndex1 - 1].score -= 1;
				teams[teamIndex1 - 1].lose += 1;
				teams[teamIndex2 - 1].score += 3;
				teams[teamIndex2 - 1].win += 1;
				break;
			case 0:
				teams[teamIndex1 - 1].score += 1;
				teams[teamIndex1 - 1].tie += 1;
				teams[teamIndex2 - 1].score += 1;
				teams[teamIndex2 - 1].tie += 1;
			}
		}

		sort(teams.begin(), teams.end(), cmp);

		bool isFirst = true;
		for (int i = 0; i < n; i++) {
			if (!isFirst) {
				cout << " ";
			}
			cout << teams[i].index;
			isFirst = false;
		}
		cout << endl;
	}
}
*/