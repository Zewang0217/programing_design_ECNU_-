/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
	string id;
	int S;
	vector<int> index;
	int score = 0;
};

void getScore(student& a, const vector<int>& scores) {
	int size = a.S;
	for (int i = 0; i < size; i++) {
		a.score += scores[a.index[i] - 1];
	}
}

bool cmp(const student& a, const student& b) {
	if (a.score != b.score) {
		return a.score > b.score;
	}
	else {
		return a.id < b.id;
	}
}

int main() {
	int T;
	cin >> T;

	
	for (int t = 0; t < T; t++) {
		int N, M, G;
		cin >> N >> M >> G;
		
		vector<int> scores(M);
		for (int i = 0; i < M; i++) {
			cin >> scores[i];
		}

		vector<student> students(N);
		for (int i = 0; i < N; i++) {
			cin >> students[i].id >> students[i].S;
			for (int j = 0; j < students[i].S; j++) {
				int x;
				cin >> x;
				students[i].index.push_back(x);
			}
		}

		for (auto &s : students) {
			getScore(s, scores);
		}

		//输出部分
		cout << "case #" << t << ":" << endl;
		vector<student> passStudents;
		int passCount = 0;
		//单独存放通过的学生
		for (auto s : students) {
			if (s.score >= G) {
				passCount++;
				passStudents.push_back(s);
			}
		}
		
		sort(passStudents.begin(), passStudents.end(), cmp);

		if (passCount == 0) {
			cout << "0" << endl;
			continue;
		}
		else {
			cout << passCount << endl;
			for (auto s : passStudents) {
				cout << s.id << " " << s.score << endl;
			}
		}

	}
}
*/