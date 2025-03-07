/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<long long> books(N);
	for (int i = 0; i < N; i++) {
		cin >> books[i];
	}

	sort(books.begin(), books.end(), [](long long a, long long b) {
		return a > b;
		});

	long long res = 0;
	for (int i = 0; i < N; i++) {
		if ((i + 1) % 3 == 0) continue;
		res += books[i];
	}

	cout << res << endl;
}
*/