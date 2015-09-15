// 1080-Map Coloring, http://acm.timus.ru/problem.aspx?space=1&num=1080
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

typedef vector<vector<int> > Graph;
const int UnColored = -1;

int main() {
	int N, tmp;
	cin >> N;
	Graph g(N+1);
	vector<int> color(N+1, UnColored);

	for (int i = 1; i <= N; ++i) {
		while (cin >> tmp && tmp != 0) {
			g[i].push_back(tmp);
			g[tmp].push_back(i);
		}
	}

	queue<int> q;
	q.push(1);
	color[1] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < g[now].size(); ++i) {
			int v = g[now][i];
			if (color[v] != UnColored && color[v] == color[now]) {
				cout << -1 << endl;
				return 0;
			}
			if (color[v] == UnColored) {
				color[v] = 1 - color[now];
				q.push(v);
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << color[i];
	}
	cout << endl;

	return 0;
}