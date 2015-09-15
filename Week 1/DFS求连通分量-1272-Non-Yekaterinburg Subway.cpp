// 1272-Non-Yekaterinburg Subway, http://acm.timus.ru/problem.aspx?space=1&num=1272
#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<vector<int> > Graph;
vector<bool> visited;
Graph g;

void dfs(int u) {
	visited[u] = true;
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main() {
	int N, M, K, u, v;
	cin >> N >> K >> M;
	g = vector<vector<int> > (N+1);
	visited = vector<bool> (N+1, false);

	for (int i = 0; i < K; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
	}

	int num = 0;
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			++num;
			dfs(i);
		}
	}

	cout << num - 1 << endl;

	return 0;
}