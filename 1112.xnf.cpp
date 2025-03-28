#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> parseFunction(const string& func) {
	vector<int> coefficients(4, 0);
	string funcPart = func.substr(func.find('=') + 1);
	
	string processed;
	for (size_t i = 0; i < funcPart.size(); i++) {
		if (funcPart[i] == '-') {
			if (i == 0 || funcPart[i - 1] == '+' || funcPart[i - 1] == '-') {
				processed += funcPart[i];
			}
			else {
				processed += "+-";
			}
		}
		else {
			processed += funcPart[i];
		}
	}

	istringstream iss(processed);
	string term;
	while (getline(iss, term, '+')) { 
		// 对输入字符串流 iss 中的内容进行逐段读取，分隔符为 +。
		//每次读取到一个由 + 分隔的子字符串后，就会把该子字符串存于 term 变量里，
		// 同时循环持续执行，直至 iss 中的内容读取完毕。

		if (term.find("x^3") != string::npos) {
			string coefStr = term.substr(0, term.find("x^3"));
			if (coefStr.empty()) {
				coefficients[3] = 1;
			}
			else if (coefStr == "-") {
				coefficients[3] = -1;
			}
			else {
				coefficients[3] = stoi(coefStr);
			}
		}

		else if (term.find("x^2") != string::npos) {
			string coefStr = term.substr(0, term.find("x^2")); 
			if (coefStr.empty()) {
				coefficients[2] = 1;
			}
			else if (coefStr == "-") {
				coefficients[2] = -1;
			}
			else {
				coefficients[2] = stoi(coefStr);
			}
		}

		else if (term.find("x") != string::npos) {
			string coefStr = term.substr(0, term.find("x"));
			if (coefStr.empty()) {
				coefficients[1] = 1;
			}
			else if (coefStr == "-") {
				coefficients[1] = -1;
			}
			else {
				coefficients[1] = stoi(coefStr);
			}
		}

		else {
			coefficients[0] = stoi(term);
		}
	}
	return coefficients;
}

int calculateFunction(const vector<int>& coefficients, int x) {
	return coefficients[3] * x * x * x + coefficients[2] * x * x +
		coefficients[1] * x + coefficients[0];
}

void printFunction(const vector<int>& coefficients) {
	for (int y = 20; y >= -20; y--) {
		for (int x = -20; x <= 20; x++) {
			int fx = calculateFunction(coefficients, x);
			if (fx == y) cout << "*";

			else if (y == 0 && x == 0) cout << "+";

			else if (y == 20 && x == 0) cout << "^";

			else if (x == 0) cout << "|";

			else if (y == 0) {
				if (x == 20) cout << ">"; 
				else  cout << "-";
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
}

/*
int main() {
	string func; 
	bool first = true;
	while (getline(cin, func)) {
		if (!first) cout << endl;
		first = false;

		vector<int> coefficient;
		coefficient = parseFunction(func);
		printFunction(coefficient);
	}
	return 0;
}
*/