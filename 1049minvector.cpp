/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//一组降序，一组升序
bool cmp1(const int a, const int b) {
	return a > b;
}

bool cmp2(const int a, const int b) {
	return a < b;
}

int main() {
	int T;
	cin >> T; 

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		//读入 a, b矩阵
		vector<int> a;
		vector<int> b;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			a.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			b.push_back(tmp);
		}

		sort(a.begin(), a.end(), cmp1);
		sort(b.begin(), b.end(), cmp2);

		long long res = 0;
		for (int i = 0; i < n; i++) {
			res += a[i] * b[i];
		}

		cout << "case #" << t << ":" << endl;
		cout << res << endl;
	}
}
*/