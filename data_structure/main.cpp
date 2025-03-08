/*
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Cirqueue.h"

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	
	Cirqueue<char> queue;
	string line;
	getline(cin, line);

	istringstream iss(line);
	char operation;

	while (iss >> operation) {
		if (queue.full()) {
			queue.serve_front();
		}
		queue.append_rear(operation);
	}

	int size = queue.size();
	for (int i = 0; i < size; i++) {
		if (i == n) break;
		char ch;
		queue.retrieve_rear(ch);
		cout << ch;
		if (i < size - 1) {
			cout << " ";
		}
		queue.serve_rear();
	}
	cout << endl;
}
*/