/*
#include <iostream>
#include <unordered_set>>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	cin.ignore();

	for (int t = 0; t < T; t++) {
		int n1, n2;
		cin >> n1 >> n2;
		cin.ignore();

		vector<int> list1;
		unordered_set<int> list2Set;

		//read the first SLlist
		for (int i = 0; i < n1; i++) {
			int val;
			cin >> val;
			list1.push_back(val);
		}
		cin.ignore();

		//read the second list into a hashmap(set)
		for (int i = 0; i < n2; i++) {
			int val;
			cin >> val;
			list2Set.insert(val);
		}
		cin.ignore();

		cout << "case #" << t << ":" << endl;

		//过滤list1，只保留不在list2Set中的元素
		vector<int> result;
		for (int num : list1) {
			if (list2Set.find(num) == list2Set.end()) {
				result.push_back(num);
			}
		}

		if(!result.empty()) {
			for (size_t i = 0; i < result.size(); i++) {
				if (i > 0) cout << " ";
				cout << result[i];
			}
		}
		cout << endl;
	}
}
*/