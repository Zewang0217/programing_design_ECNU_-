/*

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

// 计算 KL 散度
double computeKL(int K, vector<int>& X, vector<int>& Y) {
    double M = 0, My = 0;
    for (int i = 0; i < K; i++) {
        M += X[i];
        My += Y[i];
    }
    double KL = 0.0;
    for (int i = 0; i < K; i++) {
        double px = (X[i] + 1.0 / K) / (M + 1);
        double py = (Y[i] + 1.0 / K) / (My + 1);
        if (px > 0 && py > 0) {
            KL += px * log(px / py);
        }
    }
    return (fabs(KL) < 1e-7) ? 0.0000 : KL;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int K, N;
        cin >> K >> N;

        vector<int> X(K);
        for (int i = 0; i < K; i++) cin >> X[i];

        vector<pair<int, double>> results;
        for (int j = 0; j < N; j++) {
            vector<int> Y(K);
            for (int i = 0; i < K; i++) cin >> Y[i];

            double KL = computeKL(K, X, Y);
            results.push_back({ j + 1, KL });
        }

        // 排序：按 KL 散度升序，若相同则按原始输入顺序
        sort(results.begin(), results.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            if (fabs(a.second - b.second) < 1e-7) return a.first < b.first;
            return a.second < b.second;
            });

        // 输出
        cout << "case #" << t << ":" << endl;
        for (const auto& res : results) {
            cout << res.first << " " << fixed << setprecision(4) << res.second << endl;
        }
    }
    return 0;
}
*/