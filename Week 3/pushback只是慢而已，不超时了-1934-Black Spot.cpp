// 1934-Black Spot, http://acm.timus.ru/problem.aspx?space=1&num=1934
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
	int u;
	double p;
	bool operator < (const Node& rhs) const {
		return p < rhs.p;
	}
};
typedef vector<vector<Node> > Graph;

int main() {
	int n, m, s, t, u, v;
	double p;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	Graph g(n+1);
	vector<int> parent(n+1);
	vector<bool> done(n+1);
	vector<double> dis(n+1, 0);
	vector<int> dt(n+1, 0);

	for (int i = 0; i < m; ++i) {
		scanf("%d%d%lf", &u, &v, &p);
		g[u].push_back((Node){v, p / 100.0});
		g[v].push_back((Node){u, p / 100.0});
	}

	queue<int> qq;
	qq.push(t);
	dt[t] = 0;
	done[t] = true;
	while (!qq.empty()) {
		int now = qq.front();	qq.pop();
		for (int i = 0; i < g[now].size(); ++i) {
			int v = g[now][i].u;
			if (!done[v]) {
				done[v] = true;
				dt[v] = dt[now] + 1;
				qq.push(v);
			}
		}
	}
	done = vector<bool>(n+1, false);

	priority_queue<Node> q;
	q.push((Node){s, 1.0});
	parent[s] = s;
	dis[s] = 0;

	while (!q.empty()) {
		Node now = q.top();	q.pop();
		int u = now.u;
		if (done[u])
			continue;
		done[u] = true;
		for (int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i].u;
			//cout << "dt: " << dt[u] << ' ' << dt[v] << ' ' << u << ' ' << v << endl;
			if (done[v] || dt[u] != dt[v] + 1)
				continue;
			//cout << "dis: " << now.p << ' ' << g[u][i].p << ' ' << now.p * (1.0 - g[u][i].p) << endl;
			if (dis[v] < now.p * (1.0 - g[u][i].p)) {
				dis[v] = now.p * (1.0 - g[u][i].p);
				Node tmp = (Node){v, dis[v]};
				q.push(tmp);
				parent[v] = u;
				//cout << "haha: " << v << " from: " << u << ' ' << dis[v] << endl;
			}
		}
	}

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