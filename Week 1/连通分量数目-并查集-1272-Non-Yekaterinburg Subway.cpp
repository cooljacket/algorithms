// 1272-Non-Yekaterinburg Subway, http://acm.timus.ru/problem.aspx?space=1&num=1272
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

int findSet(vector<int>& index, int x) {
	if (index[x] != x)
		index[x] = findSet(index, index[x]);
	return index[x];
}

int main() {
	int N, M, K, u, v;
	scanf("%d%d%d", &N, &K, &M);
	vector<int> index(N+1);

	for (int i = 1; i <= N; ++i) {
		index[i] = i;
	}

	for (int i = 0; i < K; ++i) {
		scanf("%d%d", &u, &v);
		u = findSet(index, u);
		v = findSet(index, v);
		if (u != v)
			index[u] = v;
	}

	set<int> s;
	for (int i = 1; i <= N; ++i) {
		int key = findSet(index, i);
		s.insert(key);
	}
	printf("%d\n", s.size() - 1);

	return 0;
}