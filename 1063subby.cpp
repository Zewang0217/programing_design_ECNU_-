/*
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	int T;
	cin >> T;


	for (int t = 0; t < T; t++) {
		string message;
		cin >> message;

		//设置偏置值，将字母对应到数字
		int bias = 'a' - 1;
		for (char ch : message) {
			int res = ch - bias;
			cout << setw(2) << setfill('0') << res;
		}
		cout << endl;
	}
}
*/