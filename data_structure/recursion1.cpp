/*
#include <iostream>
using namespace std;

int n; 
int cnt = 1;
long long sum = 1;
int arr[21] = { 0 }; // �洢����
int record[21] = { 0 }; // ��¼�Ƿ�ʹ��

void permutation(int x) {
	if (cnt > 10) return;

	if (x == n + 1) { // ���һ�����У�����
		cout << cnt << ":";
		for (int i = 1; i <= n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		cnt++;
		return;
	}
	
	// �ݹ���� n �� n + 1 �Ĺ�ϵ
	for (int i = 1; i <= n; i++) { // ����1��i
		if (record[i] == 0) { // ���iû�б�ʹ��
			arr[x] = i; // ��i���뵱ǰλ��
			record[i] = 1; // ���i��ʹ��
			permutation(x + 1); // �ݹ鴦����һλ
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