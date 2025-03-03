/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct student {
	string id;
	int grade;
};

int cmp(student a, student b) {
	if (a.grade != b.grade) {
		return a.grade > b.grade;
	}
	else {
		return a.id < b.id;
	}
}

bool isPass(student a) {
	return a.grade >= 60;
}

int main() {
	int N;
	cin >> N;
	vector<student> students(N);
	for (int i = 0; i < N; i++) {
		cin >> students[i].id >> students[i].grade;
	}
	sort(students.begin(), students.end(), cmp);
	for (int i = 0; i < N; i++) {
		if (isPass(students[i])) {
			cout << students[i].id << " "
				<< students[i].grade << endl;
		}
	}
}

*/