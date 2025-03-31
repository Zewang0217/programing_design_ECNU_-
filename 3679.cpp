#include <iostream>
#include <cmath>

using namespace std;

// ¿ìËÙÃÝ¼ÆËã base^exp
long long fast_pow(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

void solve3() {
    int T;
    cin >> T;
    while (T--) {
        long long L, R;
        int B, K;
        cin >> L >> R >> B >> K;

        long long B_pow_K = fast_pow(B, K);
        long long B_pow_K_plus_1 = B_pow_K * B;
        int count = 0;

        int m = max(L, B_pow_K);
        int M = min(R, B_pow_K_plus_1);
        for (int i = m; i <= R; i += B_pow_K) {
            if (i % B_pow_K_plus_1 == 0) {
                continue;
            }
            else {
                count++;
            }
            
        }
        cout << count << endl;
    }
}

int main() {
    solve3();
    return 0;
}