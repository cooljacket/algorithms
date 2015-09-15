// 2034-Caravans, http://acm.timus.ru/problem.aspx?space=1&num=2034
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100005, INF = 1e9;
typedef vector<vector<int> > Graph;
Graph g(MAX);
vector<bool> visited(MAX, false);
vector<int> dis_r(MAX, 0), dis_f(MAX, 0), dis(MAX, 0), big(MAX, 0);
int n, m, s, f, r, u, v;

void bfs(int u) {
	dis = vector<int>(MAX, 0);
	visited = vector<bool>(MAX, false);
	queue<int> q;
	q.push(u);
	visited[u] = true;
	dis[r] = 0;
	while (!q.empty()) {
		int now = q.front();	q.pop();
		for (int i = 0; i < g[now].size(); ++i) {
			int v = g[now][i];
			if (!visited[v]) {
				visited[v] = true;
				q.push(v);
				dis[v] = dis[now] + 1;
			}
		}
	}
}

int solve(int s, int f) {
	dis = vector<int>(MAX, 0);
	visited = vector<bool>(MAX, false);
	queue<int> q;
	q.push(s);
	big[s] = dis_r[s];
	visited[s] = true;

	while (!q.empty()) {
		int u = q.front();	q.pop();
		for (int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i];
			if (dis_f[u] == dis_f[v] + 1) {
				big[v] = max(big[v], min(big[u], dis_r[v]));
				if (!visited[v]) {
					visited[v] = true;
					q.push(v);
				}
			}
		}
	}

	return big[f];
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	cin >> s >> f >> r;

	bfs(r);	dis_r = dis;
	bfs(f);	dis_f = dis;

	cout << solve(s, f) << endl;

	return 0;
}