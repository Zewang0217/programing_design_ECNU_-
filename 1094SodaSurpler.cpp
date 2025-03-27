/*
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int count = 0;
	int res = 0;
	while (cin >> a >> b >> c) {
		count = a + b;
		while (count != 0) {
			res += count / c;
			count = count / c + count % c;
			if (count < c) break;
		}
		cout << res << endl;
	}

}
*/