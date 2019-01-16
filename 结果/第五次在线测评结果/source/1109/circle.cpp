#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 7005;
int father[MAXN];
int n,x[MAXN],y[MAXN],r[MAXN];

int find(int x)
{
	while (x != father[x]) {
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y) {
		father[x] = y;
	}
	return ;
}

inline bool ok(int i, int j)
{
	return !((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) > (r[i] + r[j]) * (r[i] + r[j]));
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	
	scanf("%d",&n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d%d",&x[i],&y[i],&r[i]);
	}
	for (int i = 1; i <= n; i ++) {
		father[i] = i;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (ok(i, j)) {
				merge(i, j);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (father[i] == i) {
			++ ans;
		}
	}
	printf("%d\n",ans);
	
	return 0;
}
