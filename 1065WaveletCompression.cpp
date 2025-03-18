/*
#include <iostream>
#include <vector>

using namespace std;

// ��С���任
void inverseWaveletTransform(vector<int>& signal, int n) {
    // ����С�ķֿ��С��ʼ�𲽻ָ�
    for (int size = 2; size <= n; size *= 2) {
        vector<int> temp(signal.begin(), signal.begin() + size);
        int half = size / 2;
        for (int i = 0; i < half; i++) {
            signal[2 * i] = (temp[i] + temp[half + i]) / 2;
            signal[2 * i + 1] = (temp[i] - temp[half + i]) / 2;
        }
    }
}

int main() {
    int n;
    while (cin >> n && n > 0) {
        vector<int> signal(n);
        for (int i = 0; i < n; i++) {
            cin >> signal[i];
        }

        inverseWaveletTransform(signal, n);

        // ������
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << signal[i];
        }
        cout << endl;
    }
    return 0;
}
*/