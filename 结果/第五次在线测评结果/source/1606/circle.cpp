#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long 
//coder:mortal
using namespace std;

const int maxn = 7010;
int x[maxn], y[maxn], r[maxn];
int fa[maxn], n, cnt;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int find(int x)
{
	return x == fa[x]? x : fa[x] = find(fa[x]);
}

void init()
{
	n = read();
	for (int i = 1; i <= n; i++)
		x[i] = read(), y[i] = read(), r[i] = read();
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	cnt = n;
}

int work()
{
	int fx, fy;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			LL len = (LL)(x[i]-x[j]) * (LL)(x[i]-x[j]) + (LL)(y[i]-y[j]) * (LL)(y[i]-y[j]);
			LL ri = (LL)(r[i]+r[j]) * (LL)(r[i]+r[j]);
			if (len <= ri)
			{
				fx = find(i); fy = find(j);
				if (fx != fy) 
				{
					fa[fx] = fy; 
					cnt--;
				}
			}
		}
	return cnt;
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	init();
	printf("%d\n", work());
	fclose(stdin);
	fclose(stdout);
	return 0;
}