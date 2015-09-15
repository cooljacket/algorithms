// 1242-Werewolf, http://acm.timus.ru/problem.aspx?space=1&num=1242
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;

typedef vector<vector<int> > Graph;
vector<bool> good;

void dfs(Graph& g, int id) {
	good[id] = true;
	for (int i = 0; i < g[id].size(); ++i) {
		int v = g[id][i];
		if (!good[v])
			dfs(g, v);
	}
}

int main() {
	int N, u, v;
	string str;
	cin >> N;
	Graph parent(N+1), child(N+1);
	good = vector<bool>(N+1, false);

	getline(cin, str);
	while (getline(cin, str)) {
		if (str == "BLOOD")
			break;
		stringstream ss(str);
		ss >> u >> v;
		parent[u].push_back(v);
		child[v].push_back(u);
	}

	while (cin >> u) {
		dfs(parent, u);
		dfs(child, u);
	}

	vector<int> ans;
	bool first = true;
	for (int i = 1; i <= N; ++i) {
		if (!good[i]) {
			if (first) {
				first = false;
				cout << i;
			} else
				cout << ' ' << i;
		}
	}

	if (first)
		cout << 0 << endl;
	else
		cout << endl;

	return 0;
}