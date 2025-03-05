/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cctype>

using namespace std;
bool cmp(const string& a, const string& b) {
	return a < b;
}


string removePunctuation(const string& word) {
	string result;
	for (char c : word) {
		if (!ispunct(c)) {
			result += c;
		}
		else {
			result += " ";
		}
	}
	return result;
}

int main() {
	int T;
	cin >> T;
	cin.ignore();

	for (int t = 0; t < T; t++) {
		string line;
		getline(cin, line);
		istringstream iss(line);
		string word;
		vector<string> words;
		
		while (iss >> word) {
			string cleanWord = removePunctuation(word);
			if (!cleanWord.empty()) {
				istringstream cleanIss(cleanWord);
				string singleWord;
				while (cleanIss >> singleWord) {
					words.push_back(singleWord);
				}
			}
		}

		//利用map统计次数
		unordered_map<string, int> count;
		for (string w : words) {
			count[w]++;
		}

		vector<string> res;
		for (const auto& entry : count) {
			res.push_back(entry.first);
		}

		sort(res.begin(), res.end(), cmp);

		cout << "case #" << t << ":" << endl;
		bool first = true;
		for (const auto& pair : res) {
			if (!first) {
				cout << " ";
			}
			cout << pair;
			first = false;
		}
		cout << endl;
	}
}
*/