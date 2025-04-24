#include <iostream>
#include <vector>
using namespace std;

int main() {
    int P;
    int coin[4]; // 1元、5元、10元、25元
    int value[4] = { 1, 5, 10, 25 };

    cin >> P;
    for (int i = 0; i < 4; ++i) cin >> coin[i];

    // Step 1: 先贪心组成金额
    int used[4] = { 0 };
    int remain = P;
    for (int i = 3; i >= 0; --i) {
        int cnt = min(coin[i], remain / value[i]);
        used[i] = cnt;
        remain -= cnt * value[i];
    }

    if (remain != 0) {
        cout << "Impossible" << endl;
        return 0;
    }

    // Step 2: 枚举所有替换组合，直到不能再替换
    bool changed = true;
    while (changed) {
        changed = false;

        // 尝试将一个大硬币替换成若干个小硬币组合
        for (int from = 3; from >= 1; --from) {
            int from_val = value[from];
            if (used[from] == 0) continue;

            // 遍历所有组合：小面值组合的个数 a,b,c 枚举
            for (int a = 0; a <= coin[0] - used[0]; ++a) {
                for (int b = 0; b <= coin[1] - used[1]; ++b) {
                    for (int c = 0; c <= coin[2] - used[2]; ++c) {
                        int total_val = a * 1 + b * 5 + c * 10;
                        int total_cnt = a + b + c;

                        if (total_val == from_val && total_cnt > 1) {
                            // 成功替换一次
                            used[from] -= 1;
                            used[0] += a;
                            used[1] += b;
                            used[2] += c;
                            changed = true;
                            goto RESTART;
                        }
                    }
                }
            }
        }
    RESTART:;
    }

    // 计算总数
    int total = 0;
    for (int i = 0; i < 4; ++i)
        total += used[i];

    cout << total << endl;
    return 0;
}
