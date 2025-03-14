/*
#include <iostream>
#include <string>

using namespace std;
 
string getInt(int hole) {
	string num = "";
	if (hole == 0) {
		num += '1';
		return num;
	}
	if (hole == 1) {
		num += '0';
		return num;
	}
	while (hole > 0) {
		if (hole % 2 == 1) {
			num += '4';
			hole--;
		}
		else {
			num += '8';
			hole -= 2;
		}
	}
	return num;
}

int main() {
	int n; 
	while (cin >> n) {
		string res = getInt(n);
		cout << res << endl;
	}
}
*/