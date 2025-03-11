/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Pair {
	string IP;
	string URL;
	int octets[4];
};

void parseIP(Pair& p) {
	stringstream ss(p.IP);
	string segment;
	int i = 0;
	while (getline(ss, segment, '.')) {
		p.octets[i++] = stoi(segment);
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		cin.ignore();

		vector<Pair> pairs(n);
		for (int i = 0; i < n; i++) {
			cin >> pairs[i].IP >> pairs[i].URL;
			parseIP(pairs[i]);
		}

		sort(pairs.begin(), pairs.end(), [](const Pair& a, const Pair& b) {
			for (int i = 0; i < 4; i++) {
				if (a.octets[i] != b.octets[i]) return a.octets[i] > b.octets[i];
			}
			return a.URL < b.URL;
			});

		cout << "case #" << t << ":" << endl;
		for (int i = 0; i < n; i++) {
			cout << pairs[i].IP << " " << pairs[i].URL << endl;
		}
	}
}
*/