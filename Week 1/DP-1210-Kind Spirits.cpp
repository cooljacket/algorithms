// 1210-Kind Spirits, http://acm.timus.ru/problem.aspx?space=1&num=1210
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 35;
const int INF = 1e8;

int main() {
	int n, m;
	char ch;
	cin >> n;
	vector<int> dis(MAX, INF);
	dis[1] = 0;

	for (int level = 1; level <= n; ++level) {
		cin >> m;
		vector<int> buf = vector<int>(MAX, INF);
		for (int node = 1; node <= m; ++node) {
			int id, cost;
			while (cin >> id && id != 0) {
				cin >> cost;
				int tmp = dis[id] + cost;
				if (tmp < buf[node]) 
					buf[node] = tmp;
			}
		}
		dis = buf;
		if (level < n)
			cin >> ch;
	}

	int minCost = INF;
	for (int index = 1; index <= m; ++index) {
		if (dis[index] < minCost)
			minCost = dis[index];
	}
	cout << minCost << endl;

	return 0;
}