// 1709-Penguin-Avia, http://acm.timus.ru/problem.aspx?space=1&num=1209
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef vector<vector<int> > Graph;
Graph g;
int backNum = 0;
vector<bool> visited;
vector<vector<char> > plan;

void dfs(int u, int parent) {
	visited[u] = true;
	//cout << "Current: " << u << ' ' << parent << endl;
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (v != parent) {
			if(!visited[v])
				dfs(v, u);
			else {
				++backNum;
				plan[u][v] = 'd';
				//cout << "Back: " << u << ' ' << v << endl;
			}
		}
	}
}

int main() {
	int n;
	long long d, a;
	char ch;
	cin >> n >> d >> a;
	g = vector<vector<int> >(n);
	plan = vector<vector<char> >(n, vector<char>(n, '0'));
	visited = vector<bool>(n, false);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> ch;
			if (ch == '1') {
				g[i].push_back(j);
			}
		}
	}

	vector<int> comp;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(i, -1);
			comp.push_back(i);
		}
	}

	for (int i = 1; i < comp.size(); ++i) {
		int pre = comp[i-1], now = comp[i];
		plan[now][pre] = 'a';
		plan[pre][now] = 'a';
	}

	long long ans = d * (long long)(backNum / 2) + a * (comp.size() - 1);
	cout << ans << endl;
	/*cout << "backNum: " << backNum << endl;
	cout << "comp: " << comp.size() << endl;*/

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << plan[i][j];
		}
		cout << endl;
	}

	return 0;
}