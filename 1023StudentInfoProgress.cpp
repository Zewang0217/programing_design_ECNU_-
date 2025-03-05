/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct student {
	int ID;
	string name;
	float score1;
	float score2;
	float score3;
};

bool cmp(student a, student b) {
	float scoreA = a.score1 + a.score2 + a.score3;
	float scoreB = b.score1 + b.score2 + b.score3;

	if (scoreA != scoreB) {
		return scoreA > scoreB;
	}
	else {
		return a.ID < b.ID;
	}
}

int main() {
	int T;
	cin >> T;


	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		vector<student> students(n);
		for (int i = 0; i < n; i++) {
			student s;
			cin >> s.ID >> s.name >> s.score1 >>
				s.score2 >> s.score3;

			students[i] = s;
		}

		sort(students.begin(), students.end(), cmp);

		cout << "case #" << t << ":" << endl;
		for (int i = 0; i < n; i++) {
			cout << students[i].ID << " " << students[i].name << " "
				<< students[i].score1 << " " <<  students[i].score2 
				<< " " << students[i].score3  << endl;
		}
	}
}

*/