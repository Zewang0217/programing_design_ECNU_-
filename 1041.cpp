/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	//记录存货
	unordered_map<int, int> count;
	for (int i = 0; i < n; i++) {
		cin >> count[i + 1];
	}

	//读入各个供货商
	vector<pair<int, int>> offers;
	for (int i = 0; i < m; i++) {
		int type, price;
		cin >> type >> price;
		offers.emplace_back(type, price);
	}

	//排序
	sort(offers.begin(), offers.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
		});

	//计算总利润
	long long totalProfit = 0;
	for (auto &offer : offers) {
		int type = offer.first;
		int price = offer.second;

		if (count[type] > 0) {
			totalProfit += (long long)price * count[type];//每个收购商可以无限收购
			count[type] = 0;
		}
	}
	cout << totalProfit << endl;;
}
*/