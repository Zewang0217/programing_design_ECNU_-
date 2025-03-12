/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

bool compare(const string& a, const string& b, const string& order) {
    int midLength = min(a.length(), b.length());
    for (int i = 0; i < midLength; i++) {
        char A = toupper(a[i]);
        char B = toupper(b[i]);
        size_t aPos = order.find(A);
        size_t bPos = order.find(B);
        if (aPos != bPos) {
            return aPos < bPos;
        } 
    }
    return a.length() < b.length();
}

int main() {
    string order;
    while (cin >> order) {
        cin.ignore();
        string line;
        getline(cin, line);
        istringstream iss(line);
        string word;

        vector<string> words;
        while (iss >> word) {
            words.push_back(word);
        }

        sort(words.begin(), words.end(), [&order](const string& a, const string& b) {
            return compare(a, b, order);
            });

        bool first = true;
        for (const auto& w : words) {
            if (!first) cout << " ";
            first = false;
            cout << w;
        }
        cout << endl;
    }
}
*/