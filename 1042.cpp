/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

struct MayaDate {
	int day;
	int month;
	int year;
	string line;
};

bool cmp(const MayaDate& a, const MayaDate& b) {
	if (a.year != b.year) {
		return a.year < b.year;
	}
	else if (a.month != b.month) {
		return a.month < b.month;
	}
	else {
		return a.day < b.day;
	}
}

int main() {
	//录入所有月份信息
	unordered_map<string, int> monthIndex;
	string monthName[19] = { "pop", "no","zip", "zotz", "tzec", "xul"
		, "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin"
		, "muan", "pax", "koyab", "cumhu", "uayet" };
	//月份赋值，方便比较
	for (int i = 0; i < 19; i++) {
		monthIndex[monthName[i]] = i;
	}

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		cin.ignore();

		vector<MayaDate> dates;
		for (int i = 0; i < N; i++) {
			int day, year;
			string month;
			char dot;
			
			string line;
			getline(cin, line);
			istringstream iss(line);
			iss >> day >> dot >> month >> year;

			dates.emplace_back(MayaDate{ day, monthIndex[month], year, line });
			//此处用emplace直接构造对象，避免不必要的默认初始化，提高效率
		}

		sort(dates.begin(), dates.end(), cmp);

		cout << "case #" << t << ":" << endl;
		for (int i = 0; i < N; i++) {
			cout << dates[i].line << endl;
		}

	}
}

*/