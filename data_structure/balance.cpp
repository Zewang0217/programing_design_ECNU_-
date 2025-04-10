/*
#include "Cirqueue.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string line;
		getline(cin, line);

		char ch;
		bool left = true;
		Cirqueue<char> leftQ;
		Cirqueue<char> rightQ;
		bool hasColon = false;
		for (char ch : line) {
			if (ch == ':') {
				left = false;
				hasColon = true;
				continue;
			}
			if (left) {
				leftQ.append_rear(ch);
			}
			else {
				rightQ.append_rear(ch);
			}
		}

		//ÅÐ¶ÏNRSDL
		if (!hasColon || leftQ.size() == 0 && rightQ.size() == 0)  cout << "N" << endl;
		else if (leftQ.size() == rightQ.size()) {
			bool same = true;
			size_t size = leftQ.size();
			char l, r;
			for (size_t i = 0; i < size; i++) {
				leftQ.retrieve_rear(l);
				rightQ.retrieve_rear(r);
				if (l != r) {
					cout << "D" << endl;
					same = false;
					break;
				}
			}
			if (same) cout << "S" << endl;
		}
		else {
			if (leftQ.size() > rightQ.size()) {
				cout << "L" << endl;
			}
			else {
				cout << "R" << endl;
			}
		}
	}
}

*/