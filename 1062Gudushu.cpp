/*
#include <iostream>
#include <vector>
using namespace std;

// 计算一个数各位数字的和
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n = 1000000;

    vector<bool> isLonely(n + 1);
    for (int i = 0; i <= n; i++) {
        isLonely[i] = true;
    }

    for (int i = 1; i <= n; i++) {
        int candidate = i + digitSum(i);
        if (candidate <= n) {
            isLonely[candidate] = false;
        }
    }

    for (int num = 1; num <= n; num++) {
        if (isLonely[num]) {
            cout << num << endl;
        }
    }

    return 0;
}
*/