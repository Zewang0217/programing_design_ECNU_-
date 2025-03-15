/*
#include <iostream>
#include <iomanip>

using namespace std;

struct Time {
	int h = 0;
	int m = 0;
	int s = 0;
};

Time calculateTime(int s) {
	Time t;
	t.h = s / 3600;
	s -= t.h * 3600;

	t.m = s / 60;
	s -= t.m * 60;

	t.s = s;
	return t;
}

int main() {
	int n; 
	while (cin >> n) {
		if (n == -1) break;
		Time t = calculateTime(n);
		cout << setfill('0') << setw(2) << t.h << ":"
			<< setfill('0') << setw(2) << t.m << ":"
			<< setfill('0') << setw(2) << t.s << endl;
	}
	return 0;
}
*/