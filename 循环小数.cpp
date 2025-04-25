#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// 1.计算尾数
// 2.判断是否循环
// 3.寻找循环节

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

string find_repeating_cycle(int m, int n) {
	// 记录每个余数第一次出现的位置
	map<int, int> remainder_positions;
	// 存储小数部分的每一位数字
	vector<int> digits;
	// 循环字符串
	string result;
	// 初始余数
	int remainder = m % n;
	// 当前处理位置
	int position = 0;

	while (remainder != 0 &&
		remainder_positions.find(remainder) == remainder_positions.end()) {
		remainder_positions[remainder] = position;
		remainder *= 10;
		digits.push_back(remainder / n);
		remainder = remainder % n;
		position++;
	}

	if (remainder == 0) {
		return "0";
	}
	else {
		for (int i = remainder_positions[remainder];
			i < digits.size(); i++) {
			result += to_string(digits[i]);
		}
		return result;
	}
}

void process_fraction(int m, int n) {
	int common_divisor = gcd(m, n);
	m /= common_divisor;
	n /= common_divisor;

	int temp = n;
	while (temp % 2 == 0) {
		temp /= 2;
	}
	while (temp % 5 == 0) {
		temp /= 5;
	}

	if (temp == 1) {
		cout << "0" << endl;
	}
	else {
		cout << find_repeating_cycle(m, n) << endl;
	}
}

int main() {
	string line;
	while (getline(cin, line)) {
		size_t slash_pos = line.find('/');
		int m = stoi(line.substr(0, slash_pos));
		int n = stoi(line.substr(slash_pos + 1));
		process_fraction(m, n);
	}
	return 0;
}