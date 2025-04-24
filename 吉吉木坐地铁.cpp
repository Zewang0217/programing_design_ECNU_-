#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 100005;

// ÿ���ڵ���ھ��б��ڽӱ�
vector<int> graph[MAXN];

// ÿ���ڵ������ĸ���ͨ���������б�ţ� ��վ->����
int component_id[MAXN] = { 0 };

// ��ÿ����ͨ����������Щվ�� 
// component_nodes[i]������i���е����г�վ
unordered_map<int, vector<int>> component_nodes;

// ��ÿ����ͨ�����Ľڵ��¼�±�λ�ã��������ڻ��ϵ�λ�ã�
// ����һ�����ƣ� ���б�� -> ����վ�ڵ� -> λ�ã���������   ��map
unordered_map<int, unordered_map<int, int>> pos;


// ���ڹ���һ�����еġ���·��˳��
// u����ǰ��վ��parent����һվ��id����ǰ���У�
// ring����ǰ��վ��˳���б�visited�����ʹ���
void dfs_ring(int u, int parent, int id, vector<int>& ring, unordered_set<int>& visited) {
    // 1.�Ե�ǰվ�㴦��
    // �ڸ�˳���д������վ��
    ring.push_back(u);
    // ���Ϊ�Է���
    visited.insert(u);
    // ��ӳ���
    component_id[u] = id;

    // 2.������һ��
    // �Ե�ǰվ��������ھӱ���
    for (int v : graph[u]) {
        // ������һ��
        if (v == parent) continue;
        // �����Լ����ʵ�
        if (visited.count(v)) continue;
        // 
        dfs_ring(v, u, id, ring, visited);
        break; // ֻ��һ��������һȦ����
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, q;
    cin >> m >> q; // m ���ߣ�q ��ѯ��

    // ��u��v�ֱ����Է����ڽ�ͼ��
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // �ӳ���1��ʼ
    int comp_id = 1;
    unordered_set<int> visited;    // ����Ƿ����

    // dfs������վ��鵽��ͬ���У���ͨ��������
    for (int i = 1; i < MAXN; i++) {
        if (graph[i].size() && component_id[i] == 0) {// ���ھ��һ�û����ӵ�������
            // ��¼˳��
            vector<int> ring;
            // �����������
            dfs_ring(i, -1, comp_id, ring, visited);
            // ��¼��ǰ���еĳ�վ˳��
            component_nodes[comp_id] = ring;
            // ����ǰ���е�����վ�����������λ�ã�
            for (int j = 0; j < ring.size(); j++) {
                pos[comp_id][ring[j]] = j;
            }
            // ����һ������
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
