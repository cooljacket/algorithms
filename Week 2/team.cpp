#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100009;
vector<int> indegree(MAX, 0), next2(MAX, 0), depth(MAX, 0), check(MAX, 0);
int n, minNum, maxNum;

void bfs(int u) {
	queue<int> q;
	check[u] = u;
	int size = 0, d = 0;
	q.push(u);
	depth[u] = 1;

	while (!q.empty()) {
		++size;
		int v = q.front();	q.pop();
		int w = next2[v];
		if (v == w)
			continue;
		if (check[w] != 0 && check[w] != u)
			continue;

		if (check[w] == u) {
			maxNum -= (depth[v] - depth[w]);
			d = depth[v] - depth[w] + 1;
		} else {
			depth[w] = depth[v] + 1;
			check[w] = u;
			q.push(w);
		}
	}
	if (size == d)
		++minNum;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> next2[i];
		if (next2[i] == i)
			continue;
		++indegree[next2[i]];
	}
	for (int i = 1; i <= n; ++i)
		if (indegree[i] == 0)
			++minNum;
	maxNum = n;
	for (int i = 1; i <= n; ++i)
		if (indegree[i] == 0)
			bfs(i);
	for (int i = 1; i <= n; ++i)
		if (check[i] == 0)
			bfs(i);

	cout << minNum << ' ' << maxNum << endl;
	return 0;
}