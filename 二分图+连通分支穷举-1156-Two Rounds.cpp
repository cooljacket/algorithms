// 1156-Two Rounds, http://acm.timus.ru/problem.aspx?space=1&num=1156
// 实际是求二分图，但是有了数量的限制，图又不一定是连通的，所以得搜索所有连通分支的起点，分别赋值1和-1...
// TLE了，在第10个就跪了
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

typedef vector<vector<int> > Graph;
const int MAX = 105;
Graph g(MAX);
vector<int> parent(MAX), comp;
int n, m, cnt;
bool ans;

bool bfs(int s, int val) {
    queue<int> q;
    q.push(s);
    parent[s] = val;
    if (val == 1)
        ++cnt;

    while (!q.empty()) {
        int u = q.front();  q.pop();
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (parent[v] == 0) {
                parent[v] = -parent[u];
                if (parent[v] == 1)
                    ++cnt;
                q.push(v);
            } else if (parent[v] == parent[u])
                return false;
        }
    }
    return true;
}

/*void display(vector<int>& v, string s) {
    cout << s;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == 0)
            break;
        cout << v[i] << ' ';
    }
    cout << endl;
}*/

void show(const vector<int>& v) {
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        cout << v[i];
        (i == len - 1) ? (cout << endl) : (cout << ' ');
    }
}

void dfs(int index) {
    if (ans)
        return ;
    if (index == comp.size()) {
        /*int cnt = 0;
        for (int i = 1; i <= 2*n; ++i) {
            if (parent[i] == 1)
                ++cnt;
        }*/
        if (cnt == n)
            ans = true;
        return ;
    }

    //cout << "NOW: " << comp[index] << endl;
    int u = comp[index], cc = cnt;
    vector<int> p(parent);
    //display(parent, "before 1: ");
    if (!bfs(u, 1))
        return ;
    dfs(index + 1);
    //display(parent, "after 1: ");
    if (ans)
        return ;

    parent = p;
    cnt = cc;
    if (!bfs(u, -1))
        return ;
    dfs(index + 1);
    //display(parent, "after -1: ");
}

int main() {
    int u, v;
    cin >> n >> m;
    vector<bool> vis(2*n+1, false);

    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= 2*n; ++i) {
        if (vis[i] != 0)
            continue;
        comp.push_back(i);
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int u = q.front();  q.pop();
            for (int i = 0; i < g[u].size(); ++i) {
                int v = g[u][i];
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    //display(comp, "COMP: ");

    dfs(0);
    if (!ans)
        cout << "IMPOSSIBLE" << endl;
    else {
        //cout << "GOOD" << endl;
        vector<int> A, B;
        for (int i = 1; i <= 2*n; ++i) {
            if (parent[i] == 1)
                A.push_back(i);
            else if (parent[i] == -1)
                B.push_back(i);
        }
        show(A);
        show(B);
    }

    return 0;
}