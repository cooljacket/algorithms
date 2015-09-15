// 1137-Bus Routes: The Jedi Tournament, http://acm.timus.ru/problem.aspx?space=1&num=1137
// 欧拉环游（有向图，路径要反过来输出）
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 10005, INF = 1e9;
vector<int> g[MAX];
vector<vector<bool> > vis(MAX);
vector<int> path, degree(MAX);

void Fleury(int start) {
    stack<int> s;
    s.push(start);
    while(!s.empty()) {
        int u = s.top();
        bool popIt = true;
        for (int i = 0; i < g[u].size(); ++i) {
            if (!vis[u][i]) {
                s.push(g[u][i]);
                vis[u][i] = true;
                popIt = false;
                break;
            }
        }
        if(popIt){
            path.push_back(u);
            s.pop();
        }
    }
}

int main() {
    int n, m, u, v;
    double d;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &m, &u);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v);
            g[u].push_back(v);
            vis[u].push_back(false);
            u = v;
        }
    }

    Fleury(1);
    printf("%d", path.size() - 1);
    for (int i = path.size() - 1; i >= 0; --i)
        printf(" %d", path[i]);
    return 0;
}