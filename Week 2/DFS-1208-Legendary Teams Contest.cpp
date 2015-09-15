// 1208-Legendary Teams Contest, http://acm.timus.ru/problem.aspx?space=1&num=1208
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int ans = 0, n;
map<string, bool> select; 
vector<vector<string> > teams;

void dfs(int x, int k) {
	if (x == n) {
		ans = max(ans, k);
		return ;
	}
	dfs(x+1, k);
	if (select[teams[x][0]] || select[teams[x][1]] || select[teams[x][2]])
		return ;
	select[teams[x][0]] = select[teams[x][1]] = select[teams[x][2]] = true;
	dfs(x+1, k+1);
	select[teams[x][0]] = select[teams[x][1]] = select[teams[x][2]] = false;
}

int main() {
	string a, b, c;
	cin >> n;
	teams = vector<vector<string> >(n, vector<string>(3));

	for (int i = 0; i < n; ++i) {
		cin >> teams[i][0] >> teams[i][1] >> teams[i][2];
	}

	dfs(0, 0);

	cout << ans << endl;
	return 0;
}