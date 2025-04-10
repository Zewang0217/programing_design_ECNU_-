#include <iostream>
#include <vector>
#include <chrono>  // ����ʱ�����
using namespace std;
using namespace std::chrono;  // ʱ����������ռ�

class NQueens {
private:
    int n; // ���̴�С
    vector<vector<string>> solutions; // ���н�

public:
    // ���������������н�
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string> board(n, string(n, '.')); // ��ʼ������
        backtrack(board, 0);
        return solutions;
    }

private:
    // ���ݺ���
    void backtrack(vector<string>& board, int row) {
        if (row == n) {
            solutions.push_back(board); // �ҵ�һ����
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q'; // ���ûʺ�
                backtrack(board, row + 1); // �ݹ���һ��
                board[row][col] = '.'; // ����ѡ��
            }
        }
    }

    // ��鵱ǰλ���Ƿ���Ч
    bool isValid(vector<string>& board, int row, int col) {
        // �����
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // ������϶Խ���
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // ������϶Խ���
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
};

/*
int main() {
    int n = 8; // �˻ʺ�����

    // ��ʼ��ʱ
    auto start = high_resolution_clock::now();

    NQueens solver;
    vector<vector<string>> solutions = solver.solveNQueens(n);

    // ������ʱ
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "�˻ʺ����⹲�� " << solutions.size() << " �ֽⷨ��" << endl;
    cout << "�㷨ִ��ʱ��: " << duration.count() << " ΢�� ("
        << duration.count() / 1000.0 << " ����)" << endl;

    // �Ƿ���ʾ���нⷨ���ⷨ�϶�ʱ����ѡ����ʾ��
    bool showAllSolutions = false;
    if (showAllSolutions) {
        for (int i = 0; i < solutions.size(); i++) {
            cout << "�ⷨ " << i + 1 << ":" << endl;
            for (const string& row : solutions[i]) {
                cout << row << endl;
            }
            cout << endl;
        }
    }
    else {
        // ֻ��ʾǰ3�ֽⷨ��Ϊʾ��
        int displayCount = min(3, (int)solutions.size());
        cout << "��ʾǰ " << displayCount << " �ֽⷨ��Ϊʾ����" << endl;
        for (int i = 0; i < displayCount; i++) {
            cout << "�ⷨ " << i + 1 << ":" << endl;
            for (const string& row : solutions[i]) {
                cout << row << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
*/