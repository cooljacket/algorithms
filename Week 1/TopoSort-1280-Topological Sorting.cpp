// 1280-Topological Sorting, http://acm.timus.ru/problem.aspx?space=1&num=1280
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef vector<vector<int> > Graph;
Graph g;
vector<int> inDegree;

int main() {
	int n, m, s, v, tmp;
	cin >> n >> m;
	g = Graph(n+1);
	inDegree = vector<int>(n+1, 0);

	for (int i = 0; i < m; ++i) {
		cin >> s >> v;
		g[s].push_back(v);
		++inDegree[v];
	}

	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (inDegree[tmp] != 0) {
			cout << "NO" << endl;
			return 0;
		}
		for (int j = 0; j < g[tmp].size(); ++j) {
			--inDegree[g[tmp][j]];
		}
	}

	cout << "YES" << endl;

	return 0;
}