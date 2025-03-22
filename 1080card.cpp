/*
#include <iostream>
#include <queue>

using namespace std;

int last_card(int N) {
    queue<int> q;

    // 初始化队列，入队 1~N
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    // 按规则操作队列
    while (q.size() > 1) {
        q.pop();              // 移除队首卡片
        q.push(q.front());    // 将新的队首卡片移动到队尾
        q.pop();              // 移除原队首
    }

    return q.front(); // 剩下的最后一张卡片
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