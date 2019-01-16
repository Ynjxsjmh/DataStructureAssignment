#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 105;
const int INF = 0x3f3f3f3f;
struct Edge {
	int to,w,nt;
};

Edge e[MAX * 2];
int n,head[MAX], cnt, dis[MAX], vis[MAX];
int dep[MAX], maxdep, maxwid;

void init(void)
{
	cnt = 1;
	maxdep = 0;
	maxwid = 1;
	memset(head, 0, sizeof(head));
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(dep, 0, sizeof(dep));
	return ;
}

void add(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].w = w;
	e[cnt].nt = head[u];
	head[u] = cnt;
	++ cnt;
	return ;
}

void spfa(int u)
{
	dis[u] = 0;
	vis[u] = 1;
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int now = q.front(); q.pop(); 
		for (int i = head[now]; i; i = e[i].nt) {
			if (dis[e[i].to] > dis[now] + e[i].w) {
				dis[e[i].to] = dis[now] + e[i].w;
				if (!vis[e[i].to]) {
					vis[e[i].to] = 1;
					q.push(e[i].to);
				}
			}
		}
		vis[now] = 0;
	}
	return ;
}

void levelT(int root)
{
	queue<int> q;
	q.push(root);
	int widnow = 1;
	int pre = root;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = head[now]; i; i = e[i].nt) {
			if (e[i].w == 1) {
				q.push(e[i].to);
				dep[e[i].to] = dep[now] + 1;
				if (dep[e[i].to] > maxdep) {
					maxdep = dep[e[i].to];
				}
			}
		}
		if (dep[now] == dep[pre]) {
			++ widnow;
			if (widnow > maxwid) {
				maxwid = widnow;
			}
		} else {
			widnow = 1;
		}
		pre = now;
	}
	return ;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	init();
	int u,v;
	scanf("%d",&n);
	for (int i = 1; i <= n - 1; i ++) {
		scanf("%d%d",&u,&v);
		add(u,v,1);
		add(v,u,2);
	}
	scanf("%d%d",&u,&v);
	
	spfa(u);
	levelT(1);
	printf("%d\n%d\n",maxdep + 1, maxwid);
	printf("%d\n",dis[v]);
	
	return 0;
}



