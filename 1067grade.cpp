/*
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

struct stu {
	string id;
	int grade;
};

double calculateAvrgScore(const vector<stu>& a) {
	int sum = 0;
	for (const auto s : a) {
		sum += s.grade;
	}
	double avrg = (double)sum / a.size();
	return avrg;
}

double calculateS2(const vector<stu>& a) {
	double avrg = calculateAvrgScore(a);
	double S2 = 0;
	for (const auto& s : a) {
		S2 += (s.grade - avrg) * (s.grade - avrg);
	}
	S2 /= (double)a.size();
	return sqrt(S2);
}

int main() {
	int n;
	cin >> n;

	vector<stu> students(n);
	for (int i = 0; i < n; i++) {
		cin >> students[i].id >> students[i].grade;
	}

	double avrg = calculateAvrgScore(students);
	double S2 = calculateS2(students);

	cout << fixed << setprecision(2) << avrg << " "
		<< fixed << setprecision(2) << S2 << endl;
	return 0;
}
*/