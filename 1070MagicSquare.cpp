/*
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMagicSquare(int n) {
	vector<vector<int>> magicSquare(n, vector<int>(n, 0));

	int row = n - 1;
	int col = n / 2;
	magicSquare[row][col] = 1;

	for (int num = 2; num <= n * n; num++) {
		int nextRow = (row + 1) % n;
		int nextCol = (col - 1 + n) % n;

		if (magicSquare[nextRow][nextCol] != 0 || (row == n - 1 && col == 0)) {
			row = (row - 1 + n) % n;
		}
		else {
			row = nextRow;
			col = nextCol;
		}
		magicSquare[row][col] = num;
	}
	return magicSquare;
}

void printMagicSquare(const vector<vector<int>>& magicSquare) {
	int n = magicSquare.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > 0) cout << " ";
			cout << magicSquare[i][j];
		}
		cout << endl;
	}
}

int main() {
	int n;
	while (cin >> n) {
		vector<vector<int>> magicSquare = generateMagicSquare(n);
		printMagicSquare(magicSquare);
	}
	return 0;
}
*/