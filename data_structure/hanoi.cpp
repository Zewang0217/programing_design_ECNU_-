#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// 汉诺塔递归函数
void hanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        // cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }

    // 先将 n-1 个盘子从 source 移动到 auxiliary，借助 target
    hanoi(n - 1, source, target, auxiliary);

    // 将第 n 个盘子从 source 移动到 target
    // cout << "Move disk " << n << " from " << source << " to " << target << endl;

    // 最后将 n-1 个盘子从 auxiliary 移动到 target，借助 source
    hanoi(n - 1, auxiliary, source, target);
}

/*
int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    // 记录起始时间
    auto start = high_resolution_clock::now();

    // 调用汉诺塔函数，A 为起始柱，B 为辅助柱，C 为目标柱
    hanoi(n, 'A', 'B', 'C');

    // 记录结束时间
    auto stop = high_resolution_clock::now();

    // 计算时间间隔
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Execution time: " << duration.count() << "nanoseconds ("
        << duration.count() / 1000.0 << "mircroseconds)" << endl;

    return 0;
}
*/