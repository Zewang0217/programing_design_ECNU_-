/*
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct maxNum {
    long long max;
    long long a;
};

// 预先计算出所有可能用到的质数
vector<bool> sieve(long long maxN) {
    vector<bool> isPrime(maxN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i * i <= maxN; ++i) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= maxN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main() {
    long long n;
    long long maxN = 20000;
    vector<bool> isPrime = sieve(maxN);

    while (cin >> n) {
        maxNum x;
        x.max = 0;
        for (long long i = 2; i <= n / 2; ++i) {
            long long j = n - i;
            if (i * j > x.max && isPrime[j] && isPrime[i]) {
                x.max = i * j;
                x.a = i;
            }
        }
        cout << x.a << " " << n - x.a << endl;
    }
    return 0;
}
*/