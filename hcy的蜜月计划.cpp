#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long total = 0; // ʹ�� long long ��ֹ���
    for (int i = 0; i < N - 1; ++i) {
        int s, t, l;
        cin >> s >> t >> l;
        total += l;
    }
    cout << total * 2 << endl;
    return 0;
}