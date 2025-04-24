#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 100005;

// 每个节点的邻居列表（邻接表）
vector<int> graph[MAXN];

// 每个节点属于哪个连通分量（城市编号） 车站->城市
int component_id[MAXN] = { 0 };

// 存每个连通分量里有哪些站点 
// component_nodes[i]即代表i城市的所有车站
unordered_map<int, vector<int>> component_nodes;

// 对每个连通分量的节点记录下标位置（用于找在环上的位置）
// 创建一个类似： 城市编号 -> （车站节点 -> 位置（索引））   的map
unordered_map<int, unordered_map<int, int>> pos;


// 用于构建一个城市的“环路径顺序”
// u：当前车站；parent：上一站；id：当前城市；
// ring：当前车站的顺序列表；visited：访问过的
void dfs_ring(int u, int parent, int id, vector<int>& ring, unordered_set<int>& visited) {
    // 1.对当前站点处理
    // 在该顺序中存入这个站点
    ring.push_back(u);
    // 标记为以访问
    visited.insert(u);
    // 添加城市
    component_id[u] = id;

    // 2.往下走一步
    // 对当前站点的所有邻居遍历
    for (int v : graph[u]) {
        // 跳过上一个
        if (v == parent) continue;
        // 跳过以及访问的
        if (visited.count(v)) continue;
        // 
        dfs_ring(v, u, id, ring, visited);
        break; // 只往一个方向走一圈即可
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, q;
    cin >> m >> q; // m 条边，q 个询问

    // 将u，v分别放入对方的邻接图中
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 从城市1开始
    int comp_id = 1;
    unordered_set<int> visited;    // 标记是否访问

    // dfs将所有站点归到不同城市（连通变量）中
    for (int i = 1; i < MAXN; i++) {
        if (graph[i].size() && component_id[i] == 0) {// 有邻居且还没有添加到城市中
            // 记录顺序
            vector<int> ring;
            // 深度优先搜索
            dfs_ring(i, -1, comp_id, ring, visited);
            // 记录当前城市的车站顺序
            component_nodes[comp_id] = ring;
            // 给当前城市的所有站点添加索引（位置）
            for (int j = 0; j < ring.size(); j++) {
                pos[comp_id][ring[j]] = j;
            }
            // 到下一个城市
            comp_id++;
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        if (component_id[u] != component_id[v]) {
            cout << -1 << endl;
            continue;
        }

        int cid = component_id[u];
        int sz = component_nodes[cid].size();
        int idx_u = pos[cid][u];
        int idx_v = pos[cid][v];
        int diff = abs(idx_u - idx_v);
        int ans = min(diff, sz - diff);
        cout << ans << endl;
    }

    return 0;
}
