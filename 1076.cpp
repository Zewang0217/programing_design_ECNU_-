/*
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int h, f;
        cin >> h >> f;
        cout << "case #" << i << ":" << endl;
        if (f % 2 != 0) {
            cout << "Impossible" << endl;
        }
        else {
            int y = f / 2 - h;
            int j = h - y;
            if (y >= 0 && j >= 0) {
                cout << j << " " << y << endl;
            }
            else {
                cout << "Impossible" << endl;
            }
        }
    }
    return 0;
}*/