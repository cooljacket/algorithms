// 1982-Electrification Plan, http://acm.timus.ru/problem.aspx?space=1&num=1982
// 注意求总的管道的长度，而不是每段到最近的供电站的最短距离的和，因为是路径很有可能会重叠，就重复计算了
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

const int MAX = 105;
const int INF = 1e8;
vector<vector<int> > g(MAX, vector<int>(MAX, 0));
vector<int> dis(MAX, INF);
vector<bool> visited(MAX, false);

int PrimeMST(int n) {
	int now = 1, minW, ans = 0;
	dis[now] = 0;
	for (int i = 1; i <= n; ++i) {
		visited[now] = true;
		ans += dis[now];

		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && g[now][j] < dis[j])
				dis[j] = g[now][j];
		}

		minW = INF;
		// select the next one with the smallest weight to add into the MST
		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && dis[j] < minW) {
				minW = dis[j];
				now = j;
			}
		}
	}

	return ans;
}

int main() {
	int n, k, tmp;
	cin >> n >> k;
	vector<bool> power(n+1, false);

	for (int i = 0; i < k; ++i) {
		cin >> tmp;
		power[tmp] = true;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> g[i][j];
			// merge the k power stations into a logic point
			if (power[i] && power[j])
				g[i][j] = 0;
		}
	}

	cout << PrimeMST(n) << endl;

	return 0;
}