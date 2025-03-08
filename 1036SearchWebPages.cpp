/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct web {
	int index;
	string name;
	int r;//ÏµÊý
};

bool cmp(const web& a, const web& b) {
	if (a.r != b.r) {
		return a.r > b.r;
	}
	else {
		return a.index < b.index;
	}
}

int main() {
	int N;
	cin >> N;

	vector<web> webs(N);
	for (int i = 0; i < N; i++) {
		cin >> webs[i].name >> webs[i].r;
		webs[i].index = i;
	}

	sort(webs.begin(), webs.end(), cmp);

	int maxR = webs[0].r;
	for (int i = 0; i < N; i++) {
		if (webs[i].r != maxR) {
			break;
		}
		cout << webs[i].name << endl;
	}
}
*/