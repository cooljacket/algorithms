// 1227-Rally Championship, http://acm.timus.ru/problem.aspx?space=1&num=1227
// 无向图，但要求只能走路的一个方向。dfs有根树，求路上累计的最大值，其实就是每次计算完子节点后疏松一下
// 如果有环，则都可以，注意起点和终点可以在路上而不只是节点上
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Edge
{
    int to, w;
};

const int MAX = 105, INF = 1e9;
typedef vector<vector<Edge> > Graph;
Graph g(MAX);
vector<int> dist(MAX, 0);
vector<bool> visited(MAX, false);
bool good = false;
int n, m, s;

void dfs(int u, int parent) {
    visited[u] = true;
    //printf("DFS: %d %d\n", u, dist[u]);
    for (int i = 0; i < g[u].size(); ++i) {
        Edge e = g[u][i];
        if (e.to != parent) {
            if (!visited[e.to]) {
                dfs(e.to, u);
                dist[u] = max(dist[u], dist[e.to] + e.w);
                //printf("VIS: %d from: %d, %d %d %d %d\n", e.to, u, dist[u], dist[e.to], e.w, dist[e.to] + e.w);
                if (dist[u] >= s) {
                    good = true;
                    return ;
                }
            } else {
                good = true;
                return ;
            }
        }
    }
}

int main() {
    int u, v, d;
    scanf("%d%d%d", &n, &m, &s);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &d);
        g[u].push_back((Edge){v, d});
        g[v].push_back((Edge){u, d});
    }

    for (int i = 1; i <= n; ++i) {
        dfs(i, 0);
        if (good)
            break;
        visited = vector<bool>(MAX, false);
        dist = vector<int>(MAX, 0);
    }

    good ? (printf("YES\n")) : (printf("NO\n"));

    return 0;
}