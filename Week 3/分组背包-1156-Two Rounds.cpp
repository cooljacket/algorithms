// 1156-Two Rounds, http://acm.timus.ru/problem.aspx?space=1&num=1156
// ans = 连通分量数 - 1 + 边数
// 如何求有向图连通分量？并查集也可以的
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int MAX = 505;
vector<int> g[MAX], group(MAX), A(MAX, 0), B(MAX, 0), select(MAX, 0);
vector<vector<int> > choose(MAX, vector<int>(MAX));

bool bfs(int s, int val) {
    queue<int> q;
    q.push(s);
    group[s] = val;
    ++A[val];

    while (!q.empty()) {
        int u = q.front();  q.pop();
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (group[v] == 0) {
                group[v] = -group[u];
                (group[v] == val) ? (++A[val]) : (++B[val]);
                q.push(v);
            } else if (group[v] == group[u])
                return false;
        }
    }
    return true;
}

int main() {
    int n, m, u, v, comp = 0;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= 2*n; ++i) {
        if (group[i] == 0 && !bfs(i, ++comp)) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        //printf("hha: %d %d\n", A[comp], B[comp]);
    }

    choose[0][0] = 1;
    for (int k = 0; k < comp; ++k) {
        for (int v = 0; v <= n; ++v) {
            if (choose[k][v] == 0)
                continue;
            choose[k+1][v+A[k+1]] = 1;
            choose[k+1][v+B[k+1]] = -1;
        }
    }

    if (choose[comp][n] == 0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    int key = n;
    for (int i = comp; i >= 1; --i) {
        select[i] = choose[i][key];
        if (choose[i][key] > 0)
            key -= A[i];
        else
            key -= B[i];
        //printf("id: %d, %d, %d\n", i, select[i], key);
    }
    for (int i = 1; i <= 2*n; ++i) {
        //printf("%d, %d, %d\n", i, group[i], select[abs(group[i])]);
        if ((group[i] > 0 && select[group[i]] == 1) || (group[i] < 0 && select[-group[i]] == -1))
            printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i <= 2*n; ++i) {
        if (!(group[i] > 0 && select[group[i]] == 1) && !(group[i] < 0 && select[-group[i]] == -1)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}