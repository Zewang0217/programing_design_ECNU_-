/*
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string progressNumber(string a) {
	string reversed = a;
	reverse(reversed.begin(), reversed.end());
	return reversed;
}

int main() {
	char plus, equal;
	string a, b, c;
	while (true) {
		//read
		
		string line;
		cin >> line;
		a = line.substr(0, line.find("+") - 0);
		c = line.substr(line.find("=") + 1);
		line.erase(line.find("="));
		b = line.substr(line.find("+")+ 1);
		
		if (a == "0" && b == "0" && c == "0") {
			cout << "True" << endl;
			break;
		}

		string a1, b1, c1;
		a1 = progressNumber(a);
		b1 = progressNumber(b);
		c1 = progressNumber(c);

		if (stoi(a1) + stoi(b1) == stoi(c1)) cout << "True" << endl;
		else cout << "False" << endl;
	}

	return 0;
}
*/