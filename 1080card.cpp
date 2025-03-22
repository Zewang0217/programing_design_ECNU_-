/*
#include <iostream>
#include <queue>

using namespace std;

int last_card(int N) {
    queue<int> q;

    // ��ʼ�����У���� 1~N
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    // �������������
    while (q.size() > 1) {
        q.pop();              // �Ƴ����׿�Ƭ
        q.push(q.front());    // ���µĶ��׿�Ƭ�ƶ�����β
        q.pop();              // �Ƴ�ԭ����
    }

    return q.front(); // ʣ�µ����һ�ſ�Ƭ
}

int main() {
    int T;
    cin >> T;
    vector<int> cases(T);

    for (int i = 0; i < T; i++) {
        cin >> cases[i];
    }

    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ":\n" << last_card(cases[i]) << "\n";
    }

    return 0;
}

*/