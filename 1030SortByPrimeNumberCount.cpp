#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimesBetween(int start, int end) {
    if (end < 2) return 0;
    vector<bool> isPrimeArray(end + 1, true);
    isPrimeArray[0] = isPrimeArray[1] = false;

    // 埃拉托斯特尼筛法
    for (int i = 2; i * i <= end; ++i) {
        if (isPrimeArray[i]) {
            for (int j = i * i; j <= end; j += i) {
                isPrimeArray[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = max(2, start); i <= end; ++i) {
        if (isPrimeArray[i]) {
            count++;
        }
    }
    return count;
}

bool cmp(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    else if (a.first.first != b.first.first) {
        return a.first.first < b.first.first;
    }
    else {
        return a.first.second < b.first.second;
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<pair<int, int>> intervals(n);
        vector<pair<pair<int, int>, int>> intervalsWithCount(n);

        for (int i = 0; i < n; ++i) {
            cin >> intervals[i].first >> intervals[i].second;
        }

        for (int i = 0; i < n; ++i) {
            int count = countPrimesBetween(intervals[i].first, intervals[i].second);
            intervalsWithCount[i] = make_pair(intervals[i], count);
        }

        sort(intervalsWithCount.begin(), intervalsWithCount.end(), cmp);

        cout << "case #" << t << ":" << endl;

        for (const auto& interval : intervalsWithCount) {
            cout << interval.first.first << " " << interval.first.second << endl;
        }
    }

    return 0;
}