// 1651-Shortest Subchain, http://acm.timus.ru/problem.aspx?space=1&num=1651
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

struct Edge
{
    int to, w;
};
const int MAX = 100005, INF = 1e9;
typedef vector<vector<Edge> > Graph;
Graph g(MAX);
vector<bool> inqueue(MAX, false);
vector<int> next2(MAX, 0), index(MAX, 0), dist(MAX, INF), parent(MAX, -1);

void spfa(int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    inqueue[s] = true;

    while (!q.empty()) {
        int u = q.front();  q.pop();
        inqueue[u] = false;
        for (int i = 0; i < g[u].size(); ++i) {
            Edge e = g[u][i];
            if (dist[u] + e.w < dist[e.to]) {
                parent[e.to] = u;
                dist[e.to] = dist[u] + e.w;
                if (!inqueue[e.to]) {
                    q.push(e.to);
                    inqueue[e.to] = true;
                }
            }
        }
    }
}

int main() {
    int n, u, t;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> index[i];
    }

    for (int i = n; i >= 1; --i) {
        if (next2[index[i]] != 0)
            g[i].push_back((Edge){next2[index[i]], 0});
        next2[index[i]] = i;
        g[i].push_back((Edge){i + 1, 1});
    }

    spfa(1);

    vector<int> path(1, index[n]);
    int last = index[n], now = n;
    while (now != -1) {
        if (index[now] != last)
            path.push_back(index[now]);
        last = index[now];
        now = parent[now];
    }

    for (int i = path.size() - 1; i >= 0; --i) {
        (i == 0) ? (cout << path[i] << endl) : (cout << path[i] << ' ');
    }

    return 0;
}