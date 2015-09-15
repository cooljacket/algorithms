// 1109-Conference, http://acm.timus.ru/problem.aspx?space=1&num=1109
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef vector<vector<int> > Graph;
Graph g;
vector<int> B;
vector<bool> taken;
int M, N, K, u, v, match = 0;

bool find(int x) {
	for (int i = 0; i < g[x].size(); ++i) {
		int v = g[x][i];
		if (!taken[v]) {
			taken[v] = true;
			if (B[v] == 0 || find(B[v])) {
				B[v] = x;
				return true;
			}
		}
	}

	return false;
}

int main() {
	cin >> M >> N >> K;

	g = Graph(M+1);
	B = vector<int>(N+1, 0);

	for (int i = 0; i < K; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
	}

	for (int i = 1; i <= M; ++i) {
		taken = vector<bool>(N+1, false);
		if (find(i))
			++match;
	}

	cout << M + N - match << endl;

	return 0;
}