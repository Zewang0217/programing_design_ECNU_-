/*
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct S {
	string str;
	int count;
};

void countNoRepeat(vector<S>& Ss) {
	for (auto& s : Ss) {
		//单独处理每一个字符串
		unordered_map<char, int> count;
		for (char c : s.str) {
			count[c]++;
		}
		int currentCount = count.size();
		s.count = currentCount;
	}
}

bool cmp(const S& a, const S& b) {
	if (a.count != b.count) {
		return a.count > b.count;
	}
	else {
		return a.str < b.str;
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		vector<S> Ss(n);
		for (int i = 0; i < n; i++) {
			cin >> Ss[i].str;
		}

		countNoRepeat(Ss);

		sort(Ss.begin(), Ss.end(), cmp);

		cout << "case #" << t << ":" << endl;
		for (const auto& s : Ss) {
			cout << s.str << endl;
		}
	}
}
*/