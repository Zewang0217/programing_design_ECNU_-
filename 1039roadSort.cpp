/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct road {
	int a;
	int b;
	int distence;
};

bool cmp(const road& a, const road& b) {
	if (a.distence != b.distence) {
		return a.distence > b.distence;
	}
	else if (a.a != b.a) {
		return a.a < b.a;
	}
	else {
		return a.b < b.b;
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		vector<road> roads(M);
		for (int i = 0; i < M; i++) {
			cin >> roads[i].a >> roads[i].b >> roads[i].distence;
		}

		sort(roads.begin(), roads.end(), cmp);

		cout << "case #" << t << ":" << endl;
		for (int i = 0; i < M; i++) {
			cout << "(" << roads[i].a << "," << roads[i].b << "," << roads[i].distence << ")" << endl;
		}
	}
}
*/