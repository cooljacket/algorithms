// 1106-Two Teams, http://acm.timus.ru/problem.aspx?space=1&num=1106
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main() {
	int n, f;
	cin >> n;
	vector<int> part;
	// true: have friends, false: no friends in this group
	vector<bool> first(n+1, false), second(n+1, false);

	for (int i = 1; i <= n; ++i) {
		vector<int> tmp;
		while (cin >> f && f != 0) {
			tmp.push_back(f);
		}
		if (!first[i]) {
			first[i] = true;
			part.push_back(i);
			for (int j = 0; j < tmp.size(); ++j) {
				first[tmp[j] ] = true;
			}
		}
		else if (!second[i]) {
			second[i] = true;
			for (int j = 0; j < tmp.size(); ++j) {
				second[tmp[j] ] = true;
			}
		}

	}

	int len = part.size();
	cout << len << endl;
	for (int i = 0; i < len; ++i) {
		cout << part[i];
		(i == len-1) ? (cout << endl) : (cout << ' ');
	}

	return 0;
}