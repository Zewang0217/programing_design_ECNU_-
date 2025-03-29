/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calculateMaxRows(const string& s) {
	if (s.empty()) return 0;

	int maxRow = 0;
	int minRow = 0;
	int currentRow = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] > s[i - 1]) currentRow++;
		else if (s[i] < s[i - 1]) currentRow--;
		
		if (currentRow > maxRow) maxRow = currentRow;
		if (currentRow < minRow) minRow = currentRow;
	}

	return maxRow - minRow + 1;
}

vector<string> generateWave(const string& s) {
	if (s.empty()) return {};


	// 生成每个位置所在的行号
	vector<int> index(s.size(), 0);
	for (int i = 1; i < s.size(); i++) {
		if (s[i] > s[i - 1]) {
			index[i] = index[i - 1] + 1;
		}
		else if (s[i] < s[i - 1]) {
			index[i] = index[i - 1] - 1;
		}
		else {
			index[i] = index[i - 1];
		}
	}

	// 调整行号，使最小行号为0
	int minIndex = index[0];
	int maxIndex = index[0];
	for (const auto& x : index) {
		if (x < minIndex) minIndex = x;
		if (x > maxIndex) maxIndex = x;
	}
	for (auto& x : index) {
		x -= minIndex;
	}

	int totalRows = maxIndex - minIndex + 1;
	int totalCols = s.length();

	// 填充字符
	vector<string> wave(totalRows,string(totalCols,  ' '));
	for (int col = 0; col < totalCols; col++) {
		int row = index[col];
		wave[row][col] = s[col];
	}

	// 去除末尾空格
	for (string& line : wave) {
		int lastNonSpace = line.find_last_not_of(' ');
		if (lastNonSpace != string::npos) {
			line = line.substr(0, lastNonSpace + 1);
		}
		else {
			line.clear();
		}
	}
	return wave;
}

int main() {
	string line;

	while (getline(cin, line)) {
		vector<string> wave = generateWave(line);
		for (int i = calculateMaxRows(line) - 1; i >= 0; i--) {
			cout << wave[i] << endl;
		}
	}
	return 0;
}
*/