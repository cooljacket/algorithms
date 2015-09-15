// 1450-Russian Pipelines: The Jedi Tournament, http://acm.timus.ru/problem.aspx?space=1&num=1450
// 有向图，缩点（强连通分量），按拓扑排序求路径sum最大值？只需输出最大值
// 或者说其实根本不用，就是在有向图上做一遍dijkstra而已。。。
// 其实，它并没有有向环（强连通分量），所以只需要做一遍topo排序就可以了，从起点开始更新dist值。
// 或者所有权值转负，用bellman_ford求最短路
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
vector<LL> dist(MAX, INF);
vector<bool> inqueue(MAX, false);

int main() {
    int n, m, u, v, s, t, d;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &d);
        g[u].push_back((Edge){v, -d});
    }

    scanf("%d%d", &s, &t);

    dist[s] = 0;
    queue<int> q;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int u = q.front();  q.pop();
        inqueue[u] = false;
        for (int i = 0; i < g[u].size(); ++i) {
            Edge e = g[u][i];
            if (dist[u] + e.d < dist[e.to]) {
                dist[e.to] = dist[u] + e.d;
                if (!inqueue[e.to]) {
                    q.push(e.to);
                    inqueue[e.to] = true;
                }
            }
        }
    }

    if (dist[t] == INF)
        printf("No solution\n");
    else
        printf("%d\n", -dist[t]);

    return 0;
}