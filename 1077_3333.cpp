/*
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int C, W;
		cin >> C >> W;
		int max = pow(10, C);
		int min = pow(10, C - 1) + W;

		int count = 0;
		for (int i = min; i < max; i += 10) {
			if (i % 3 == 0) {
				count++;
			}
		}
		cout << "case #" << t << ":" << endl;
		cout << count << endl;
	}
}
*/