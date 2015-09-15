// 1450-Russian Pipelines: The Jedi Tournament, http://acm.timus.ru/problem.aspx?space=1&num=1450
// 有向图，缩点（强连通分量），按拓扑排序求路径sum最大值？只需输出最大值
// 或者说其实根本不用，就是在有向图上做一遍dijkstra而已。。。
// 其实，它并没有有向环（强连通分量），所以只需要做一遍topo排序就可以了，从起点开始更新dist值。
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int MAX = 505, INF = 1e9;
typedef long long LL;
struct Edge
{
    int to;
    LL d;
};
vector<vector<Edge> > g(MAX);
vector<int> ind(MAX);
vector<LL> dist(MAX, 0);
vector<bool> visited(MAX, false);

bool check(int s, int t) {
    queue<int> q;
    vector<bool> vis(MAX, false);
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();  q.pop();
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].to;
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return vis[t];
}

int main() {
    int n, m, u, v, s, t, d;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &d);
        g[u].push_back((Edge){v, d});
        ++ind[v];
    }

    scanf("%d%d", &s, &t);
    if (!check(s, t)) {
        printf("No solution\n");
        return 0;
    }

    queue<int> q;
    bool start = false;
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front();    q.pop();
        if (u == s)
            start = true;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].to;
            if (!visited[v] && --ind[v] == 0) {
                q.push(v);
                visited[v] = true;
            }
            if (start) {
                dist[v] = max(dist[v], dist[u] + g[u][i].d);
            }
        }
    }

    printf("%d\n", dist[t]);

    return 0;
}