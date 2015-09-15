// 1119-Metro, http://acm.timus.ru/problem.aspx?space=1&num=1119
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

const double Unit = 100;
const double Dig = sqrt(2 * Unit * Unit);

int main() {
	int N, M, K, u, v;
	cin >> N >> M >> K;
	// N : col, M : row
	vector<vector<bool> > hasDig(M+1, vector<bool>(N+1, false));
	vector<double> dis(N+1, 0);

	for (int i = 0; i < K; ++i) {
		cin >> u >> v;
		hasDig[v][u] = true;
	}

	for (int i = 0; i <= N; ++i) {
		dis[i] = i * Unit;
	}

	for (int i = 1; i <= M; ++i) {
		double beg = dis[0];
		dis[0] += Unit;
		for (int j = 1; j <= N; ++j) {
			double tmp = dis[j];
			if (hasDig[i][j]) {
				dis[j] = beg + Dig;
			}
			else
				dis[j] = min(dis[j-1], dis[j]) + Unit;
			beg = tmp;
		}
	}

	cout << (int)(dis[N] + 0.5) << endl;

	return 0;
}