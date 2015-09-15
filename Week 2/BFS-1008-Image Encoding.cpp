// 1008-Image Encoding, http://acm.timus.ru/problem.aspx?space=1&num=1008
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <map>
using namespace std;

typedef vector<vector<int> > Graph;
enum Color
{
	White, Black
};
struct Point
{
	int x, y;
};
const int MAX = 12;
Graph g(MAX, vector<int>(MAX, White));
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char Description[] = {'R', 'T', 'L', 'B'};
int N, x, y, begX, begY;

void pointToDir();
void dirToPoint();

int main() {
	string str;
	getline(cin, str);
	if (str.find(' ') == string::npos) {
		stringstream ss(str);
		ss >> N;
		pointToDir();
	} else {
		stringstream ss(str);
		ss >> begX >> begY;
		dirToPoint();
	}

	return 0;
}

void pointToDir() {
	cin >> begX >> begY;
	g[begX][begY] = Black;
	for (int i = 1; i < N; ++i) {
		cin >> x >> y;
		g[x][y] = Black;
	}

	queue<Point> q;
	q.push((Point){begX, begY});
	vector<vector<bool> > visited(MAX, vector<bool>(MAX, false));
	visited[begX][begY] = true;
	cout << begX << ' ' << begY << endl;

	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			x = now.x + dir[i][0];
			y = now.y + dir[i][1];
			if (g[x][y] == Black && !visited[x][y]) {
				q.push((Point){x, y});
				visited[x][y] = true;
				cout << Description[i];
			}
		}
		if (!q.empty())
			cout << ',' << endl;
	}

	cout << '.' << endl;
}

void dirToPoint() {
	char ch = '*';
	map<char, int> m;
	m['R'] = 0;
	m['T'] = 1;
	m['L'] = 2;
	m['B'] = 3;
	queue<Point> q;
	q.push((Point){begX, begY});
	g[begX][begY] = Black;
	int num = 1;
	while (cin >> ch && ch != '.') {
		Point p = q.front();	q.pop();
		begX = p.x;
		begY = p.y;
		while (ch != ',') {
			int index = m[ch];
			x = begX + dir[index][0];
			y = begY + dir[index][1];
			if (g[x][y] != Black) {
				++num;
				g[x][y] = Black;
			}
			q.push((Point){x, y});
			cin >> ch;
		}
	}
	cout << num << endl;
	for (int row = 1; row < MAX; ++row) {
		for (int col = 1; col < MAX; ++col) {
			if (g[row][col] == Black)
				cout << row << ' ' << col << endl;
		}
	}
}
/*
test Case:
(1) WA 1
10
1 1
1 2
2 2
2 3
2 4
2 5
3 1
3 2
4 2
4 3

1 1
T,
R,
RT,
RB,
T,
T,
,
T,
,
.

(2) WA 6
1 1
.

1
1 1
*/