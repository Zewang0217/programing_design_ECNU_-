/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int main() {
	int T;
	cin >> T;
	cin.ignore();

	for (int t = 0; t < T; t++) {
		string line;
		getline(cin, line);
		vector<char> chs;
		
		//读取所有字母
		for (const auto& ch : line) {
			if (isalpha(ch)) chs.push_back(ch);
		}
		
		//对字母排序
		sort(chs.begin(), chs.end(), [](char a, char b) {
			return a < b;
			});

		//以line为模板输出
		size_t length = line.size();
		int j = 0;
		cout << "case #" << t << ":" << endl;
		for (size_t i = 0; i < length; i++) {
			if (isalpha(line[i])) {
				cout << chs[j];
				j++;
			}
			else {
				cout << line[i];
			}
		}
		cout << endl;
	}
	return 0;
}
*/