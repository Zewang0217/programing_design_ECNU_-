/*
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isPalindromic(long long a) {
	string tmp = to_string(a);
	reverse(tmp.begin(), tmp.end());
	if (to_string(a) == tmp) return true;
	else return false;
}

int main() {
	long long n;
	cin >> n;
	int i = 0;

	while (!isPalindromic(n)) {
		string r = to_string(n);
		reverse(r.begin(), r.end());
		long long reversed = stoi(r);
		n += reversed;
		i++;
		if (isPalindromic(n)) {
			cout << i << " " << n;
			break;
		}
	}
	return 0;
}
*/