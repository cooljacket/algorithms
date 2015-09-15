// 1930-Ivan's Car, http://acm.timus.ru/problem.aspx?space=1&num=1930
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

struct Edge
{
	int to;
	bool upOrDown, pre;
	// 注意，小于号与优先队列的搭配，需要排在前面的是优先级高的
	bool operator < (const Edge& rhs) const {
		int a = pre ^ upOrDown;
		int b = rhs.pre ^ rhs.upOrDown;
		return a > b;
	}
};

const bool UP = true, DOWN = false;
const int INF = 1e9;
typedef vector<vector<Edge> > Graph;


int main() {
	int n, m, u, v;
	cin >> n >> m;
	Graph g(n+1);
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		g[u].push_back((Edge){v, UP, UP});
		g[v].push_back((Edge){u, DOWN, DOWN});
	}

	cin >> u >> v;

	priority_queue<Edge> q;
	vector<bool> done(n+1, false);
	vector<int> dist(n+1, INF);
	done[u] = true;
	for (int i = 0; i < g[u].size(); ++i) {
		Edge e = g[u][i];
		q.push((Edge){e.to, e.upOrDown, e.upOrDown});
		dist[e.to] = 0;
	} 

	while (!q.empty()) {
		Edge e = q.top();	q.pop();
		int now = e.to;
		if (done[now])
			continue;
		done[now] = true;
		for (int i = 0; i < g[now].size(); ++i) {
			Edge ee = g[now][i];
			ee.pre = e.upOrDown;
			int dis = (ee.upOrDown ^ ee.pre);
			if (dist[now] + dis < dist[ee.to]) {
				dist[ee.to] = dist[now] + dis;
				q.push(ee);
			}
		}
	}

	cout << dist[v] << endl;

	return 0;
}