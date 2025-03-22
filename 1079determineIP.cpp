/*
#include <iostream>
#include <string>

using namespace std;

bool isValid(string IP) {
	int dotIndex[3];
	int i = 0, j = 0;
	//记录点的位置
	for (const char& ch : IP) {
		if (ch == '.') {
			dotIndex[i] = j;
			i++;
		}
		j++;
	}
    // 读取子字符串
	string a1 = IP.substr(0, dotIndex[0]);
	string a2 = IP.substr(dotIndex[0] + 1, dotIndex[1] - dotIndex[0] - 1);
	string a3 = IP.substr(dotIndex[1] + 1, dotIndex[2] - dotIndex[1] - 1);
	string a4 = IP.substr(dotIndex[2] + 1);

	int a = stoi(a1);
	int b = stoi(a2);
	int c = stoi(a3);
	int d = stoi(a4);

	if (!(a >= 0 && a <= 255)) {
		cout << "No 0" << " " << a << endl;
		return false;
	}
	if (!(b >= 0 && b <= 255)) {
		cout << "No 1" << " " << b << endl;
		return false;
	}
	if (!(c >= 0 && c <= 255)) {
		cout << "No 2" << " " << c << endl;
		return false;
	}
	if (!(d >= 0 && d <= 255)) {
		cout << "No 3" << " " << d << endl;
		return false;

	}
	return true;
}

int main() {
	int T;
	cin >> T;
	bool res;
	for (int t = 0; t < T; t++) {
		string IP;
		cin >> IP;

		cout << "case #" << t << ":" << endl;
		res = isValid(IP);
		if (res) {
			cout << "Yes" << endl;;
		}
	}
}
*/