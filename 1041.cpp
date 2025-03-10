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
	
	//��¼���
	unordered_map<int, int> count;
	for (int i = 0; i < n; i++) {
		cin >> count[i + 1];
	}

	//�������������
	vector<pair<int, int>> offers;
	for (int i = 0; i < m; i++) {
		int type, price;
		cin >> type >> price;
		offers.emplace_back(type, price);
	}

	//����
	sort(offers.begin(), offers.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
		});

	//����������
	long long totalProfit = 0;
	for (auto &offer : offers) {
		int type = offer.first;
		int price = offer.second;

		if (count[type] > 0) {
			totalProfit += (long long)price * count[type];//ÿ���չ��̿��������չ�
			count[type] = 0;
		}
	}
	cout << totalProfit << endl;;
}
*/