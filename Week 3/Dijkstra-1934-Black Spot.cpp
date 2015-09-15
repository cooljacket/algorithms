// 1934-Black Spot, http://acm.timus.ru/problem.aspx?space=1&num=1934
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    int u, v, next;
    double p;
};
const int MAX = 100004, INF = 1e9;
int index = 0;
vector<Node> g(MAX*2);
vector<int> parent(MAX), ds(MAX, INF), head(MAX, -1);
vector<bool> visited(MAX);
vector<double> dis(MAX, 0);

inline void add(int u, int v, int w) {
    g[index].u = u;
    g[index].v = v;
    g[index].p = (100 - w) * 1.0 / 100.0;
    g[index].next = head[u];
    head[u] = index++;
}

void spfa(int s, int t);

int main() {
    cin.sync_with_stdio(false);
    int n, m, s, t, u, v;
    double p;
    scanf("%d%d%d%d", &n, &m, &s, &t);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%lf", &u, &v, &p);
        add(u, v, p);
        add(v, u, p);
    }

    spfa(s, t);

    int key = t;
    stack<int> ans;
    while (parent[key] != key) {
        ans.push(key);
        key = parent[key];
    }
    
    printf("%d %lf\n%d", ans.size()+1, 1.0 - dis[t], s);
    while (!ans.empty()) {
        printf(" %d", ans.top());
        ans.pop();
    }
    printf("\n");

    return 0;
}

void spfa(int s, int t) {
    queue<int> q;
    dis[s] = 1.0;
    ds[s] = 0;
    parent[s] = s;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();  q.pop();
        visited[u] = false;
        for (int i = head[u]; i != -1; i = g[i].next) {
            int v = g[i].v;
            double w = g[i].p;
            if (ds[v] >= ds[u] + 1) {
                if (ds[v] == ds[u] + 1) {
                    if (dis[v] < dis[u] * w) {
                        dis[v] = dis[u] * w;
                        parent[v] = u;
                    }
                } else {
                    ds[v] = ds[u] + 1;
                    dis[v] = dis[u] * w;
                    parent[v] = u;
                }
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }   
}