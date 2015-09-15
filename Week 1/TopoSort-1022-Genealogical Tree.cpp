// 1022-Genealogical Tree, http://acm.timus.ru/problem.aspx?space=1&num=1022
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef vector<vector<int> > Graph;

void display(vector<int>& v) {
	int len = v.size();
	for (int i = 0; i < len; ++i) {
		cout << v[i];
		(i == len - 1) ? (cout << endl) : (cout << ' ');
	}
}

int main() {
	int n, t;
	cin >> n;
	Graph g(n+1);
	vector<int> inDegree(n+1, 0);

	for (int i = 1; i <= n; ++i) {
		while (cin >> t && t != 0) {
			g[i].push_back(t);
			++inDegree[t];
		}
	}

	queue<int> q;
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		ans.push_back(now);
		for (int i = 0; i < g[now].size(); ++i) {
			int v = g[now][i];
			if (--inDegree[v] == 0)
				q.push(v);
		}
	}

	display(ans);

	return 0;
}