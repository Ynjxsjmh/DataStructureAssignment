#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int maxn = 50050;
int n, a[maxn], cnt;

bool cmp(int a, int b)
{
	return a < b; 
}

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	memset(a, 0, sizeof(a));
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a+1, a+n+1);
	cnt = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] == a[i-1]) cnt++;
		else
		{
			printf("%d %d\n", a[i-1], cnt);
			cnt = 1;
		}
	}
	printf("%d %d", a[n], cnt);
	return 0;
}
