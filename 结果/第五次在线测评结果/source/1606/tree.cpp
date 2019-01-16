#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
//coder:mortal
using namespace std;

const int maxn = 505;
int st[maxn], to[maxn], nxt[maxn], dep[maxn], cnt[maxn], vis[maxn];
int head, tail, q[maxn*10], ansdep, anscnt, ans, node;
int len = 0, n, u, v, x, y, root = 1;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int gmax(int a, int b) { return a > b ? a : b; }

void upgo(int now, int mode)
{
	//printf("haha: %d \n", now);
	if (mode == 1) vis[now] = 1;
	if (mode == 1 && now == 1) return;
	if (mode == 2 && vis[now] == 1) { node = now; return; }
	for (int i = st[now]; i; i = nxt[i])
		if (dep[to[i]] + 1 == dep[now])
		{
			upgo(to[i], mode);
		}
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	memset(st, 0, sizeof(st));
	memset(nxt, 0, sizeof(nxt));
	memset(to, 0, sizeof(to));
	memset(dep, 0, sizeof(dep));
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	n = read();
	for (int i = 1; i < n; i++)
	{
		x = read();  y = read();
		len++; to[len] = y; nxt[len] = st[x]; st[x] = len;
		len++; to[len] = x; nxt[len] = st[y]; st[y] = len;
	}
	head = 0; tail = 1; q[1] = 1; dep[1] = 1; cnt[1] = 1;
	while (head != tail)
	{
		head++; int now = q[head];
		for (int i = st[now]; i; i = nxt[i])
			if (dep[to[i]] == 0)
			{
				dep[to[i]] = dep[now] + 1;
				cnt[dep[to[i]]]++;
				tail++; q[tail] = to[i];
			}
	}
	ansdep = 0; anscnt = 0;
	x = read(); y =read(); 
	for (int i = 1; i <= n; i++) ansdep=gmax(ansdep, dep[i]), anscnt=gmax(anscnt, cnt[i]);	
	upgo(x, 1); upgo(y, 2); ans = (dep[x] - dep[node]) * 2 + (dep[y] - dep[node]);

	/*for (int i = 1; i <= n; i++) printf("%d ",dep[i]);
	printf("\n");
	for (int i = 1; i <= n; i++) printf("%d ", vis[i]);
	printf("\n");*/
	//printf("%d %d %d\n", x, y, node);
	printf("%d\n%d\n%d", ansdep, anscnt, ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
