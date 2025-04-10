#include <iostream>
#include <vector>
#include <chrono>  // 用于时间测量
using namespace std;
using namespace std::chrono;  // 时间相关命名空间

class NQueens {
private:
    int n; // 棋盘大小
    vector<vector<string>> solutions; // 所有解

public:
    // 主函数，返回所有解
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string> board(n, string(n, '.')); // 初始化棋盘
        backtrack(board, 0);
        return solutions;
    }

private:
    // 回溯函数
    void backtrack(vector<string>& board, int row) {
        if (row == n) {
            solutions.push_back(board); // 找到一个解
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q'; // 放置皇后
                backtrack(board, row + 1); // 递归下一行
                board[row][col] = '.'; // 撤销选择
            }
        }
    }

    // 检查当前位置是否有效
    bool isValid(vector<string>& board, int row, int col) {
        // 检查列
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // 检查左上对角线
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // 检查右上对角线
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
};

/*
int main() {
    int n = 8; // 八皇后问题

    // 开始计时
    auto start = high_resolution_clock::now();

    NQueens solver;
    vector<vector<string>> solutions = solver.solveNQueens(n);

    // 结束计时
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "八皇后问题共有 " << solutions.size() << " 种解法：" << endl;
    cout << "算法执行时间: " << duration.count() << " 微秒 ("
        << duration.count() / 1000.0 << " 毫秒)" << endl;

    // 是否显示所有解法（解法较多时可以选择不显示）
    bool showAllSolutions = false;
    if (showAllSolutions) {
        for (int i = 0; i < solutions.size(); i++) {
            cout << "解法 " << i + 1 << ":" << endl;
            for (const string& row : solutions[i]) {
                cout << row << endl;
            }
            cout << endl;
        }
    }
    else {
        // 只显示前3种解法作为示例
        int displayCount = min(3, (int)solutions.size());
        cout << "显示前 " << displayCount << " 种解法作为示例：" << endl;
        for (int i = 0; i < displayCount; i++) {
            cout << "解法 " << i + 1 << ":" << endl;
            for (const string& row : solutions[i]) {
                cout << row << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
*/