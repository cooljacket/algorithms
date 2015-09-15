// 1160-Network, http://acm.timus.ru/problem.aspx?space=1&num=1651
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 1005, INF = 1e9;
typedef vector<vector<int> > Graph;
Graph g(MAX, vector<int>(MAX, INF));
vector<int> dist(MAX, INF), parent(MAX, -1);

struct Edge
{
    int u, v;
};
vector<Edge> ee;

int PrimMST(int n) {
    int v0 = 1, minW, maxEdge = -1, minOne, p;

    for (int i = 1; i <= n; ++i) {
        dist[i] = g[v0][i];
        parent[i] = v0;
    }
    dist[v0] = 0;

    for (int i = 1; i < n; ++i) {
        minW = INF;
        for (int j = 1; j <= n; ++j) {
            if (dist[j] != 0 && minW > dist[j]) {
                minW = dist[j];
                minOne = j;
            }
        }

        dist[minOne] = 0;
        p = parent[minOne];
        ee.push_back((Edge){p, minOne});
        if (g[p][minOne] > maxEdge)
            maxEdge = g[p][minOne];

        for (int j = 1; j <= n; ++j) {
            if (g[minOne][j] < dist[j]) {
                dist[j] = g[minOne][j];
                parent[j] = minOne;
            }
        }
    }
    return maxEdge;
}

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        g[u][v] = w;
        g[v][u] = w;
    }

    int maxLen = PrimMST(n);
    cout << maxLen << endl;
    cout << ee.size() << endl;
    for (int i = 0; i < ee.size(); ++i)
        cout << ee[i].u << ' ' << ee[i].v << endl;

    return 0;
}