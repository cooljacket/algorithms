// 1033-Labyrinth, http://acm.timus.ru/problem.aspx?space=1&num=1033
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int ans = 0, N;
vector<vector<char> > m;
vector<vector<bool> > visited;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const char BLOCK = '#';

bool checkBound(int row, int col) {
	return row >= 0 && row <= N+1 && col >= 0 && col <= N+1;
}

void dfs(int row, int col) {
	if (visited[row][col] || m[row][col] == BLOCK)
		return ;
	int beg = 0, end = 3;
	if (row == 1 && col == 1)
		end = 1;
	else if (row == N && col == N)
		beg = 2;

	visited[row][col] = true;
	for (int i = beg; i <= end; ++i) {
		int r = row + dir[i][0], c = col + dir[i][1];
		if (!checkBound(r, c)) {
			continue;
		}

		if (m[r][c] == BLOCK) {
			++ans;
		}
		else if (!visited[r][c]) {
			dfs(r, c);
		}
	}
}

int main() {
	char buf;
	cin >> N;
	m = vector<vector<char> >(N+2, vector<char>(N+2, '#'));
	visited = vector<vector<bool> >(N+1, vector<bool>(N+1, false));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> m[i][j];
		}
	}

	dfs(1, 1);
	dfs(N, N);
	cout << ans * 9 << endl;

	return 0;
}