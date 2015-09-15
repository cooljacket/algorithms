// DFS to produce a all-N-permutation
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

typedef vector<vector<int> > Graph;
vector<bool> visited;
Graph g;
int depth, N;
vector<int> data;


void display(vector<int>& v) {
	int len = v.size();
	for (int i = 0; i < len; ++i) {
		cout << v[i];
		(i == len - 1) ? (cout << endl) : (cout << ' ');
	}
}

void dfs(int u) {
	visited[u] = true;
	data[depth++] = u;

	if (depth == N)
		display(data);

	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (!visited[v])
			dfs(v);
	}

	--depth;
	visited[u] = false;
}

int main() {
	cin >> N;
	g = Graph(N+1);
	visited = vector<bool>(N+1, false);
	data = vector<int>(N);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i != j) {
				g[i].push_back(j);
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		dfs(i);
	}

	return 0;
}