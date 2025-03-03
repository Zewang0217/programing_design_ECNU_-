/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool cmpA(int a, int b) {
	return a < b;
}
bool cmpD(int a, int b) {
	return a > b;
}

int main() {
	char operation;
	cin >> operation;
	cin.ignore();

	//Read the numbers
	string line, tmp;
	while (getline(cin, tmp)) {
		line += tmp + " ";
	}

	istringstream iss(line);
	vector<int> nums;
	int n;
	while (iss >> n) {
		nums.push_back(n);
	}

	switch (operation) {
	    case 'A':
			sort(nums.begin(), nums.end(), cmpA);
			break;
		case 'D':
			sort(nums.begin(), nums.end(), cmpD);
	}

	//output
	cout << nums[0];
	int lastNumber = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] != lastNumber) {
			cout << " " << nums[i];
			lastNumber = nums[i];
		}
	}
}
*/