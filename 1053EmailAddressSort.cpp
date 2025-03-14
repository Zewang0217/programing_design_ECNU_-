/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct em {
	string name;
	string domain;
};

bool cmp(const em& a, const em& b) {
	if (a.domain != b.domain) return a.domain < b.domain;
	return a.name > b.name;
}

int main() {
	int n;
	cin >> n;

	vector<em> ems;
	for (int i = 0; i < n; i++) {
		string email;
		cin >> email;

		int pos = email.find('@');
		em a;
		a.name = email.substr(0, pos - 0);
		a.domain = email.substr(pos + 1);
		ems.push_back(a);
	}

	sort(ems.begin(), ems.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << ems[i].name << "@" << ems[i].domain << endl;
	}
}
*/