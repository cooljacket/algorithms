// 1119-Metro, http://acm.timus.ru/problem.aspx?space=1&num=1119
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef vector<vector<float> > AdjMatrix;
const double INF = 1e5;
const double Unit = 100;
const double Dig = sqrt(2 * Unit * Unit);

void display(AdjMatrix& g) {
	for (int i = 0; i < g.size(); ++i) {
		for (int j = 0; j < g[0].size(); ++j) {
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	int RowSize, ColSize, K, u, v;
	cin >> RowSize >> ColSize >> K;
	int size = (++RowSize) * (++ColSize);

	AdjMatrix g(size, vector<float>(size, INF));

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == j)
				g[i][j] = 0;
			else if (i / RowSize == j / RowSize && (i - j == 1 || j - i == 1) )
				g[i][j] = Unit;
			else if (i - j == RowSize || j - i == RowSize)
				g[i][j] = Unit;
		}
	}
	
	for (int i = 0; i < K; ++i) {
		cin >> u >> v;
		int a = (u - 1) + (v - 1) * RowSize, b = u + v * RowSize;
		g[a][b] = g[b][a] = Dig;
	}

	for (int k = 0; k < size; ++k) {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				double tmp = g[i][k] + g[k][j];
				if (tmp < g[i][j])
					g[i][j] = tmp;
			}
		}
	}

	cout << (int)(g[0][size-1] + 0.5) << endl;

	return 0;
}