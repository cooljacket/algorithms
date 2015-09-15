// 1205-By the Underground or by Foot?, http://acm.timus.ru/problem.aspx?space=1&num=1205
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point
{
	double x, y;
};

struct Node
{
	int from, to;
	double weight;
	bool operator < (const Node& rhs) const {
		return weight >= rhs.weight;
	}
};

typedef vector<vector<Node> > Graph;
const double INF = 1e19 * 9;

double dis(const Point& a, const Point& b) {
	double xx = a.x - b.x, yy = a.y - b.y;
	return sqrt(xx * xx + yy * yy);
}

int main() {
	double foot, groud, x, y, d;
	int N, u, v;
	cin >> foot >> groud >> N;
	Graph g(N+2);
	vector<Point> stations(N+2);

	for (int i = 1; i <= N; ++i) {
		cin >> x >> y;
		stations[i] = ((Point){x, y});
	}

	while (cin >> u >> v) {
		if (u == 0 && v == 0)
			break;
		d = dis(stations[u], stations[v]) / groud;
		g[u].push_back((Node){u, v, d});
		g[v].push_back((Node){v, u, d});
	}

	int a[] = {0, N+1};
	for (int i = 0; i < 2; ++i) {
		int index = a[i];
		cin >> x >> y;
		stations[index] = (Point){x, y};
	}
	for (int i = 0; i <= N+1; ++i) {
		for (int j = i+1; j <= N+1; ++j) {
			d = dis(stations[i], stations[j]) / foot;
			g[i].push_back((Node){i, j, d});
			g[j].push_back((Node){j, i, d});
		}
	}

	priority_queue<Node> q;
	vector<bool> done(N+2, false);
	vector<double> dist(N+2, INF);
	vector<int> parent(N+2, 0);
	dist[0] = 0;
	q.push((Node){0, 0, 0});

	while (!q.empty()) {
		Node now = q.top();	q.pop();
		int u = now.to;
		if (done[u])
			continue;
		done[u] = true;
		for (int i = 0; i < g[u].size(); ++i) {
			Node v = g[u][i];
			if (dist[u] + v.weight < dist[v.to]) {
				dist[v.to] = dist[u] + v.weight;
				q.push(v);
				parent[v.to] = u;
			}
		}
	}

	cout << fixed << setprecision(7) << dist[N+1] << endl;

	int key = N + 1;
	vector<int> route;
	while (parent[key] != 0) {
		key = parent[key];
		route.push_back(key);
	}

	cout << route.size();
	for (int i = route.size() - 1; i >= 0; --i)
		cout << ' ' << route[i];
	cout << endl;

	return 0;
}