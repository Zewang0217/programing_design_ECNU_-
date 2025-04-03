#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
string decimalToBinary(const string& decimal) {
    string binary;
    string num = decimal;
    while (num != "0") {
        int remainder = 0;
        string temp;
        for (char c : num) {
            int digit = c - '0';
            int value = remainder * 10 + digit;
            remainder = value % 2;
            temp.push_back((value / 2) + '0');
        }
        binary.push_back(remainder + '0');
        num = temp;
        // Remove leading zeros in temp
        size_t pos = num.find_first_not_of('0');
        if (pos != string::npos) {
            num = num.substr(pos);
        }
        else {
            num = "0";
        }
    }
    reverse(binary.begin(), binary.end());
    // Remove leading zeros in binary
    size_t pos = binary.find_first_not_of('0');
    if (pos != string::npos) {
        binary = binary.substr(pos);
    }
    else {
        binary = "0";
    }
    return binary;
}

string binaryToDecimal(const string& binary) {
    string decimal = "0";
    for (char bit : binary) {
        int carry = bit - '0';
        for (int i = decimal.size() - 1; i >= 0; --i) {
            int digit = decimal[i] - '0';
            digit = digit * 2 + carry;
            carry = digit / 10;
            decimal[i] = (digit % 10) + '0';
        }
        if (carry > 0) {
            decimal.insert(decimal.begin(), carry + '0');
        }
    }
    return decimal;
}

void solve() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string numStr;
        cin >> numStr;
        if (numStr == "0") {
            cout << "case #" << i << ":" << endl;
            cout << 0 << endl;
            continue;
        }
        string binary = decimalToBinary(numStr);
        reverse(binary.begin(), binary.end());
        string reversedDecimal = binaryToDecimal(binary);
        cout << "case #" << i << ":" << endl;
        cout << reversedDecimal << endl;
    }
}*/

/*
int main() {
    solve();
    return 0;
}
*/