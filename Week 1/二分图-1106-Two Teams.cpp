// 1106-Two Teams, http://acm.timus.ru/problem.aspx?space=1&num=1106
// 题目并不是要求二分图...
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef vector<vector<int> > Graph;

bool biGraph(Graph& g, vector<int>& color, int u) {
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		cout << "Now: " << u << ' ' << v << ' ' << color[u] << ' ' << color[v] << endl;
		if (color[v] == color[u])
			return false;
		if (color[v] == 0) {
			color[v] = -color[u];
			if (!biGraph(g, color, v))
				return false;
		}
	}
	return true;
}

int main() {
	int n, f;
	cin >> n;
	Graph g(n+1);

	for (int i = 1; i <= n; ++i) {
		while (cin >> f && f != 0) {
			g[i].push_back(f);
		}
	}

	// 0: uncolored, 1: white, -1: black
	vector<int> color(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0)
			color[i] = 1;
		if (!biGraph(g, color, i)) {
			cout << 0 << endl;
			return 0;
		}
	}

	vector<int> part;
	for (int i = 1; i <=n; ++i) {
		if (color[i] == 1)
			part.push_back(i);
	}

	cout << part.size() << endl;
	cout << part[0];
	for (int i = 1; i < part.size(); ++i)
		cout << ' ' << part[i];
	cout << endl;

	return 0;
}