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
    int v, next;
    double p;
    bool operator < (const Node& rhs) const {
        return p < rhs.p;
    }
};
const int MAX = 100004, INF = 1e9;
int index = 0;
vector<Node> g(MAX*2);
vector<int> parent(MAX), ds(MAX, INF), head(MAX, -1), dt(MAX);
vector<bool> done(MAX), visited(MAX);
vector<double> dis(MAX, 0);

inline void add(int u, int v, int w) {
    g[index].v = v;
    g[index].p = (100 - w) * 1.0 / 100.0;
    g[index].next = head[u];
    head[u] = index++;
}

void dijkstra(int s, int t);

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

    queue<int> qq;
    qq.push(t);
    dt[t] = 0;
    visited[t] = true;
    while (!qq.empty()) {
        int now = qq.front();   qq.pop();
        for (int i = head[now]; i != -1; i = g[i].next) {
            int v = g[i].v;
            if (!visited[v]) {
                visited[v] = true;
                dt[v] = dt[now] + 1;
                qq.push(v);
            }
        }
    }

    dijkstra(s, t);

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

void dijkstra(int s, int t) {
    priority_queue<Node> q;
    q.push((Node){s, -1, 1.0});
    parent[s] = s;
    dis[s] = 0;

    while (!q.empty()) {
        Node now = q.top(); q.pop();
        int u = now.v;
        if (done[u])
            continue;
        done[u] = true;
        //cout << "Now: " << u << endl;
        for (int i = head[u]; i != -1; i = g[i].next) {
            int v = g[i].v;
            if (done[v] || dt[u] != dt[v] + 1)
                continue;
            if (dis[v] < now.p * g[i].p) {
                dis[v] = now.p * g[i].p;
                q.push((Node){v, 0, dis[v]});
                parent[v] = u;
            }
            //cout << "haha: " << u << ' ' << v << ' ' << dis[v] << endl;
        }
    }
}