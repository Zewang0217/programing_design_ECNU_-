/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct DNA {
	int count;
	string name;
};

bool cmp(const DNA& a, const DNA& b) {
	if (a.count != b.count) {
		return a.count < b.count;
	}
	else {
		return a.name < b.name;
	}
}

int main() {
	int n;
	cin >> n;

	unordered_map<string, int> DNAcount;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		DNAcount[s]++;
	}

	vector<DNA> DNAs;
	for (const auto& d : DNAcount) {
		DNA tmp;
		tmp.name = d.first;
		tmp.count = d.second;
		DNAs.push_back(tmp);
	}

	sort(DNAs.begin(), DNAs.end(), cmp);

	for (const auto& a : DNAs) {
		cout << a.name << endl;
	}
}
*/