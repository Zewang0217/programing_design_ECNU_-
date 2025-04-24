#include <iostream>
#include <vector>
using namespace std;

int main() {
    int P;
    int coin[4]; // 1Ԫ��5Ԫ��10Ԫ��25Ԫ
    int value[4] = { 1, 5, 10, 25 };

    cin >> P;
    for (int i = 0; i < 4; ++i) cin >> coin[i];

    // Step 1: ��̰����ɽ��
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

    // Step 2: ö�������滻��ϣ�ֱ���������滻
    bool changed = true;
    while (changed) {
        changed = false;

        // ���Խ�һ����Ӳ���滻�����ɸ�СӲ�����
        for (int from = 3; from >= 1; --from) {
            int from_val = value[from];
            if (used[from] == 0) continue;

            // ����������ϣ�С��ֵ��ϵĸ��� a,b,c ö��
            for (int a = 0; a <= coin[0] - used[0]; ++a) {
                for (int b = 0; b <= coin[1] - used[1]; ++b) {
                    for (int c = 0; c <= coin[2] - used[2]; ++c) {
                        int total_val = a * 1 + b * 5 + c * 10;
                        int total_cnt = a + b + c;

                        if (total_val == from_val && total_cnt > 1) {
                            // �ɹ��滻һ��
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

    // ��������
    int total = 0;
    for (int i = 0; i < 4; ++i)
        total += used[i];

    cout << total << endl;
    return 0;
}
