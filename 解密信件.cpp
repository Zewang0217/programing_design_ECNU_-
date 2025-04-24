#include <iostream>
using namespace std;

long long findOriginalPos(long long n, long long x) {
    if (n == 1) {
        return 1;
    }
    long long k = n / 2;
    if (x <= k) {
        // ��ǰxλ��ǰ�벿�֣��ȵݹ鴦��ǰ�벿�֣������巴ת
        long long sub_original = findOriginalPos(k, x);
        return n + 1 - sub_original; // ��ת���λ��
    }
    else {
        // ��ǰxλ�ں�벿�֣��ȵݹ鴦��󲿷֣������巴ת
        long long sub_original = findOriginalPos(n - k, x - k);
        return n + 1 - (k + sub_original); // ��ת���λ��
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