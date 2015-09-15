// 1124-Mosaic, http://acm.timus.ru/problem.aspx?space=1&num=1982
// ans = 连通分量数 - 1 + 边数
// 如何求有向图连通分量？并查集也可以的
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

const int MAX = 505;
typedef vector<vector<int> > Graph;
Graph g;
vector<int> root(MAX);
vector<bool> vis(MAX);

int find(int x) {
    while (x != root[x])
        x = root[x];
    return root[x];
}

int main() {
    int m, n, t, ans = 0;
    cin >> n >> m;
    g = Graph(n+1);

    for (int i = 1; i <= n; ++i)
        root[i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> t;
            if (t != i) {
                ++ans;
                vis[t] = vis[i] = true;
                int x = find(i), y = find(t);
                if (x != y)
                    root[x] = y;
            }
        }
    }

    set<int> s;
    for (int i = 1; i <= n; ++i) {
        if (vis[i])
            s.insert(find(i));
    }

    (ans == 0) ? (cout << ans << endl) : (cout << ans - 1 + s.size() << endl);

    return 0;
}