// 1136. Parliament, http://acm.timus.ru/problem.aspx?space=1&num=1136
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

// find the begin of the right branch
int upperBound(vector<int>& v, int key) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] >= key)
			return i;
	}
	return v.size() - 1;
}

void playBack(vector<int>& v) {
	if (v.empty())
		return ;
	if (v.size() == 1) {
		cout << v[0] << endl;
		return ;
	}

	int end = v[v.size() - 1];
	int key = upperBound(v, end);
	vector<int> left(v.begin(), v.begin() + key);
	vector<int> right(v.begin() + key, v.end()-1);
	playBack(right);
	playBack(left);
	cout << end << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	playBack(v);

	return 0;
}