// Isenbaev's Number, http://acm.timus.ru/problem.aspx?space=1&num=1837
// http://paste.ubuntu.com/12132879/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef vector<vector<int> > Graph;

int main() {
    int n, current_id = 0, member = 3;
    string* name = new string[3];
    map<string, int> m;
    Graph g;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < member; ++j) {
            cin >> name[j];
            if (m.find(name[j]) == m.end()) {
                m[name[j] ] = current_id++;
                g.push_back(vector<int>());
            }
        }
        for (int j = 0; j < member; ++j) {
            int first = (j + 1) % member, second = (j + 2) % member, key = m[name[j] ];
            g[key].push_back(m[name[first] ]);
            g[key].push_back(m[name[second] ]);
        }
    }

    
    vector<int> dis(m.size(), -1);

    // int beg = m["Isenbaev"];     The wrong assignment
    if ( (m.find("Isenbaev") != m.end()) ) {
        int beg = m["Isenbaev"];
        queue<int> q;
        q.push(beg);
        dis[beg] = 0;

        while (!q.empty() ) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < g[now].size(); ++i) {
                int v = g[now][i];
                if (dis[v] == -1) {
                    q.push(v);
                    dis[v] = dis[now] + 1;
                }
            }
        }
    }

    map<string, int>::iterator it = m.begin();
    while (it != m.end() ) {
        cout << it->first << ' ';
        if (dis[it->second] == -1)
            cout << "undefined" << endl;
        else
            cout << dis[it->second] << endl;
        ++it;
    }

    return 0;
}