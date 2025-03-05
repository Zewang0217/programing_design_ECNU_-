/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int score;
		vector<int> scores;
		while (cin >> score) {
			if (score == -1) break;
			scores.push_back(score);
		}

		sort(scores.begin(), scores.end());

		int maxScore = scores[scores.size() - 1];
		int minScore = scores[0];
		int sum = 0;
		for (const int& s : scores) {
			sum += s;
		}
		int avgScore = sum / scores.size();

		cout << "case #" << t << ":" << endl;
		cout << maxScore << endl;
		cout << minScore << endl;
		cout << avgScore << endl;
	}
}
*/