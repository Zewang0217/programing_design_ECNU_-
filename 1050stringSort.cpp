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
		
		//��ȡ������ĸ
		for (const auto& ch : line) {
			if (isalpha(ch)) chs.push_back(ch);
		}
		
		//����ĸ����
		sort(chs.begin(), chs.end(), [](char a, char b) {
			return a < b;
			});

		//��lineΪģ�����
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