/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//对键值对比较：
//出现次数多排在前面；
//数字小的排前面。
int compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main() {
	int T;
	cin >> T;
	cin.ignore();

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		cin.ignore();

		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		//前者为键，后者为值
		unordered_map<int, int> count;
		for (int num : arr) {
			//在数字对应的键处加一，若没有则创建一个
			count[num]++;
		}

		//第一个为数字大小，第二个为出现次数
		vector<pair<int, int>> pairs;
		for (const auto& entry : count) {
			//以pair形式存储键值对
			pairs.emplace_back(entry.first, entry.second);
		}

		sort(pairs.begin(), pairs.end(), compare);

		cout << "case #" << t << ":" << endl;
		bool first = true;
		for (const auto& pair : pairs) {
			for (int i = 0; i < pair.second; i++) {
				if (!first) {
					cout << " ";
				}
				cout << pair.first;
				first = false;
			}
		}
		cout << endl;
	}
	return 0;
}

*/