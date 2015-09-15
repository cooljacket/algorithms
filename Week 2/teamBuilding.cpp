#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
const int maxn=100009;
int ind[maxn];
int next2[maxn];
int n;
int ansmin,ansmax;
int level[maxn];

vector<int> e[maxn];

int check[maxn];

queue<int> q;
void bfs(int x)
{
	check[x]=x;
	int sz=0,circle=0;
	q.push(x);
	level[x]=1;
	while (!q.empty())
	{
		sz++;
		int v=q.front(); q.pop();
		int v2=next2[v];
		if (v2==v) continue;
		
		if (check[v2]!=0 && check[v2]!=x) continue;

		if (check[v2]==x)
		{ 
			ansmax-=level[v]-level[v2]; 
			circle=level[v]-level[v2]+1;
		}else {
				level[v2]=level[v]+1;
				check[v2]=x;
				q.push(v2);
		}
	}
	if (sz==circle) ansmin++;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		//int v;
		scanf("%d",&next2[i]);
		if (next2[i]==i) continue;
		ind[next2[i]]++;
	}
	for (int i=1;i<=n;i++)
		if (ind[i]==0) ansmin++;
	ansmax=n;
	for (int i=1;i<=n;i++)
		if (ind[i]==0) bfs(i);
	for (int i=1;i<=n;i++)
		if (check[i]==0) bfs(i);

	printf("%d %d\n",ansmin,ansmax);
}