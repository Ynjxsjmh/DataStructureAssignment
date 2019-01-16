#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
//coder:mortal
using namespace std;
int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int num[50];
int ans[10];
int n, a, cnt; 
int main()
{
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	memset(num, 0, sizeof(num));
	memset(ans, 0, sizeof(ans));
	n = read();
	for (int i = 1; i <= 7; i++)
	{
		a = read(); num[a] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		cnt = 7;
		for (int i = 1; i <= 7; i++)
		{
			a = read(); if (num[a]) cnt--;
		}
		ans[cnt]++;
	}
	for (int i = 0; i < 6; i++) 
		printf("%d ", ans[i]);
	printf("%d",ans[6]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}