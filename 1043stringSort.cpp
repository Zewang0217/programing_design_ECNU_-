/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

struct str {
	string str;
	int num;
	bool hasNum = false;
};

bool cmp(const str& a, const str& b) {
	if (a.hasNum && !b.hasNum) return false;
	else if (!a.hasNum && b.hasNum) return true;
	else if (a.hasNum && b.hasNum) {
		if (a.num != b.num) {
			return a.num < b.num;
		}
		else {
			return a.str < b.str;
		}
	}
	else {
		return a.str < b.str;
	}
}

bool getNum(str& a) {
	string num;
	for (char ch : a.str) {
		if (isdigit(ch)) {
			num += ch;
			a.hasNum = true;
		}
	}
	if (a.hasNum) {
		a.num = stoi(num);
	}
	return a.hasNum;
}

int main() {
	vector<str> strs;
	string s;
	
	string line;
	getline(cin, line);
	istringstream iss(line);
	string s1;
	while (iss >> s1) {
		str tmp;
		tmp.str = s1;
		strs.push_back(tmp);
	}

	for (auto& s : strs) {
		getNum(s);
	}

	sort(strs.begin(), strs.end(), cmp);

	bool first = true;
	for (int i = 0, size = strs.size(); i < size; i++) {
		if (!first) cout << " ";
		cout << strs[i].str;
		first = false;
	}
}
*/