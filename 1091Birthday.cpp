/*
#include <iostream>

using namespace std;

int isLeapYear(int year) {
	if (year % 400 == 0) return true;

	if (year % 4 == 0 && year % 100 != 0) return true;

	return false;
}

int main() {
	int year;
	cin >> year;

	int giveOut = 0;
	int get = 0;
	int countBirthday = 0;

	for (int i = 2001; i <= year; i++) {
		if (isLeapYear(i)) {
			get += 700;
			countBirthday++;
		}
		giveOut += 140;
	}

	cout << countBirthday << " " << giveOut << " " << get << endl;
}
*/