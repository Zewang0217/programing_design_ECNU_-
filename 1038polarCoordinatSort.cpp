/*
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

#define M_PI 3.1415926

using namespace std;

void toPolar(pair<double, double>& a) {
	double x = a.first;
	double y = a.second;
	double r = sqrt(x * x + y * y);
	double theta = atan2(y, x);  
	if (theta < 0) {
		theta += 2 * M_PI;
	}
	a.first = r;
	a.second = theta;
}


bool cmp(const pair<double, double>& a, const pair<double, double>& b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		cout << "case #" << t << ":" << endl;

		vector<pair<double, double>> dots(N);

		for (int i = 0; i < N; i++) {
			cin >> dots[i].first >> dots[i].second;
			toPolar(dots[i]);
		}

		sort(dots.begin(), dots.end(), cmp);

		for (int i = 0; i < N; i++) {
			cout << "(" << fixed << setprecision(4) << dots[i].first
				<< "," << fixed << setprecision(4) << dots[i].second << ")" << endl;
		}
	}
}
*/