#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// ��ŵ���ݹ麯��
void hanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        // cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }

    // �Ƚ� n-1 �����Ӵ� source �ƶ��� auxiliary������ target
    hanoi(n - 1, source, target, auxiliary);

    // ���� n �����Ӵ� source �ƶ��� target
    // cout << "Move disk " << n << " from " << source << " to " << target << endl;

    // ��� n-1 �����Ӵ� auxiliary �ƶ��� target������ source
    hanoi(n - 1, auxiliary, source, target);
}

/*
int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    // ��¼��ʼʱ��
    auto start = high_resolution_clock::now();

    // ���ú�ŵ��������A Ϊ��ʼ����B Ϊ��������C ΪĿ����
    hanoi(n, 'A', 'B', 'C');

    // ��¼����ʱ��
    auto stop = high_resolution_clock::now();

    // ����ʱ����
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Execution time: " << duration.count() << "nanoseconds ("
        << duration.count() / 1000.0 << "mircroseconds)" << endl;

    return 0;
}
*/