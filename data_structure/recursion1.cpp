/*
#include <iostream>
using namespace std;

int n; 
int cnt = 1;
long long sum = 1;
int arr[21] = { 0 }; // 存储排列
int record[21] = { 0 }; // 记录是否被使用

void permutation(int x) {
	if (cnt > 10) return;

	if (x == n + 1) { // 完成一个排列，返回
		cout << cnt << ":";
		for (int i = 1; i <= n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		cnt++;
		return;
	}
	
	// 递归过程 n 与 n + 1 的关系
	for (int i = 1; i <= n; i++) { // 遍历1到i
		if (record[i] == 0) { // 如果i没有被使用
			arr[x] = i; // 将i放入当前位置
			record[i] = 1; // 标记i已使用
			permutation(x + 1); // 递归处理下一位
			arr[x] = 0;
			record[i] = 0;
		}
	}
	return;
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum *= i;
	}
	permutation(1);
	cout << sum;
	return 0;
}
*/