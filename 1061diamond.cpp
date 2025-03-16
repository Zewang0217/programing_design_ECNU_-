/*
#include <iostream>
using namespace std;

void printDiamond(int n) {
    int size = 2 * n - 1; // 菱形的总高度和最大宽度
    for (int i = 0; i < size; ++i) {
        int stars = (i < n) ? (2 * i + 1) : (2 * (size - 1 - i) + 1);
        int spaces = n - 1 - (i < n ? i : size - 1 - i);

        for (int j = 0; j < spaces; ++j) cout << " ";
        for (int j = 0; j < stars; ++j) cout << "*";
        for (int j = 0; j < spaces; ++j) cout << " ";

        cout << endl;
    }
}

int main() {
    int n;
    while (cin >> n) {
        printDiamond(n + 1);
    }
    return 0;
}
*/