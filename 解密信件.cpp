#include <iostream>
using namespace std;

long long findOriginalPos(long long n, long long x) {
    if (n == 1) {
        return 1;
    }
    long long k = n / 2;
    if (x <= k) {
        // 当前x位于前半部分，先递归处理前半部分，再整体反转
        long long sub_original = findOriginalPos(k, x);
        return n + 1 - sub_original; // 反转后的位置
    }
    else {
        // 当前x位于后半部分，先递归处理后部分，再整体反转
        long long sub_original = findOriginalPos(n - k, x - k);
        return n + 1 - (k + sub_original); // 反转后的位置
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long n, x;
        cin >> n >> x;
        cout << findOriginalPos(n, x) << '\n';
    }

    return 0;
}