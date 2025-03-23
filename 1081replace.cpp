/*
#include <iostream>
#include <vector>

using namespace std;

void process(vector<int>& a) {
	int n = a.size();
	vector<int> tmp = a;
	int count = 0;
	while (1) {
		for (int i = 0; i < n; i++) {
			count = 0;
			for (int j = i; j < n; j++) {
				if (i == j) continue;
				if (a[i] > a[j]) count++;
			}
			a[i] = count;
		}
		if (a == tmp) break;
		tmp = a;
	}
	
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		vector<int> entry(n);

		for (int i = 0; i < n; i++) {
			cin >> entry[i];
		}

		process(entry);
		cout << "case #" << t << ":" << endl;
		bool first = true;
		for (int i = 0; i < n; i++) {
			if (!first) cout << " ";
			first = false;
			cout << entry[i];
		}
		cout << endl;
	}
}
*/