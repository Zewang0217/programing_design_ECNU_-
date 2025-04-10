#include <iostream>
#include <queue>  // 用于BFS
using namespace std;

const int max_maze = 12;

class Maze {
public:
    Maze();
    void create_maze(int size);
    void reset_visited();
    int get_flag() const;
    int get_step() const;
    void dfs(int x, int y, int step);
    void bfs(int start_x, int start_y);
    void print_maze() const;  // 可选：打印迷宫
private:
    int min_step;
    int flag;
    char MAZE[max_maze + 2][max_maze + 2];
    int visited[max_maze + 2][max_maze + 2];

    // 辅助函数
    bool is_valid_move(int x, int y) const;
};

Maze::Maze() : min_step(max_maze* max_maze), flag(0) {}

void Maze::create_maze(int size) {
    // 创建边界墙
    for (int i = 0; i < size + 2; i++) {
        MAZE[0][i] = 'W';
        MAZE[size + 1][i] = 'W';
        MAZE[i][0] = 'W';
        MAZE[i][size + 1] = 'W';
    }
    // 输入迷宫内容
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            cin >> MAZE[i][j];
        }
    }
}

void Maze::reset_visited() {
    flag = 0;
    min_step = max_maze * max_maze;
    for (int i = 0; i < max_maze + 2; i++) {
        for (int j = 0; j < max_maze + 2; j++) {
            visited[i][j] = 0;
        }
    }
}

int Maze::get_flag() const { return flag; }
int Maze::get_step() const { return min_step; }

bool Maze::is_valid_move(int x, int y) const {
    return (MAZE[x][y] == 'O' || MAZE[x][y] == 'E') && !visited[x][y];
}

// DFS实现
void Maze::dfs(int x, int y, int step) {
    if (MAZE[x][y] == 'E') {
        if (step < min_step) {
            min_step = step;
            flag = 1;
        }
        return;
    }

    visited[x][y] = 1;

    // 四个方向: 上、右、下、左
    const int dx[4] = { -1, 0, 1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_valid_move(nx, ny)) {
            dfs(nx, ny, step + 1);
        }
    }

    visited[x][y] = 0;  // 回溯
}

// BFS实现
void Maze::bfs(int start_x, int start_y) {
    reset_visited();

    queue<pair<pair<int, int>, int>> q;  // 存储((x,y),步数)
    q.push({ {start_x, start_y}, 0 });
    visited[start_x][start_y] = 1;

    const int dx[4] = { -1, 0, 1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first.first;
        int y = current.first.second;
        int step = current.second;

        if (MAZE[x][y] == 'E') {
            min_step = step;
            flag = 1;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_valid_move(nx, ny)) {
                visited[nx][ny] = 1;
                q.push({ {nx, ny}, step + 1 });
            }
        }
    }
}

// 可选：打印迷宫
void Maze::print_maze() const {
    for (int i = 0; i < max_maze + 2; i++) {
        for (int j = 0; j < max_maze + 2; j++) {
            cout << MAZE[i][j] << " ";
        }
        cout << endl;
    }
}
/*

int main() {
    Maze maze;
    cout << "请输入" << max_maze << "x" << max_maze << "迷宫(S=起点, E=终点, O=通路, W=墙):" << endl;
    maze.create_maze(max_maze);

    int choice;
    do {
        cout << "\n选择算法: \n1. DFS \n2. BFS \n0. 退出\n选择: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            int x, y;
            cout << "输入起点坐标(如 1 1): ";
            cin >> x >> y;

            maze.reset_visited();

            if (choice == 1) {
                maze.dfs(x + 1, y + 1, 0);  // +1因为迷宫有外围墙
                cout << "DFS结果: ";
            }
            else {
                maze.bfs(x + 1, y + 1);
                cout << "BFS结果: ";
            }

            if (maze.get_flag()) {
                cout << "最短步数: " << maze.get_step() << endl;
            }
            else {
                cout << "无法到达终点" << endl;
            }
        }
    } while (choice != 0);

    return 0;
}*/