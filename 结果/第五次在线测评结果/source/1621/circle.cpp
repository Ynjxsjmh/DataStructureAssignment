// 园的划分.cpp : 定义控制台应用程序的入口点。
//

#include"stdio.h"
#include<queue>
#include"math.h"
using namespace std;
int vis[7000];
int x[7001], y[7001], r[7001], edge[7000][7000];
int judge(int x1, int y1, int r1, int x2, int y2, int r2);
int main() {
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	int num,i1,i2,a1,a2,result=0;
	queue<int>q1;
	int w;
	scanf("%d", &num);
	
	memset(edge, 0, sizeof(edge));
	memset(vis, 0, sizeof(vis));
	for (i1 = 1; i1 <= num; i1++)
	{
		scanf("%d %d %d", &x[i1], &y[i1], &r[i1]);
	}
	for(i1=1;i1<=num;i1++)
		for (i2 = i1 + 1; i2 <= num; i2++)
		{
			w = judge(x[i1], y[i1], r[i1], x[i2], y[i2], r[i2]);
			if (w == 1)
				edge[i1][i2] = 1;
		}
	q1.push(1);
	while (!q1.empty()) {
		a1 = q1.front(); q1.pop();
		vis[a1] = 1;
		for (i1 = a1 + 1; i1 <= num; i1++)
		{
			if (edge[a1][i1] == 1)
			{
				q1.push(i1);
				vis[i1] = 1;
			}
		}
	}
	result++;
	while (1)
	{
		for (i1 = 1; i1 <= num&&vis[i1] == 1; i1++);
		if (i1 = num + 1) break;
		else
		{
			q1.push(i1);
			while (!q1.empty()) {
				a1 = q1.front(); q1.pop();
				vis[a1] = 1;
				for (i1 = a1 + 1; i1 <= num; i1++)
				{
					if (edge[a1][i1] == 1)
					{
						q1.push(i1);
						vis[i1] = 1;
					}
				}
			}
			result++;
		}

	}
	printf("%d", result);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int judge(int x1, int y1, int r1, int x2, int y2, int r2) {
	int length,k1,k2;
	length = pow((r2 + r1), 2);
	k1 = pow((x2 - x1), 2) + pow((y2 - y1), 2);
	if (length < k1)
		return 1;
	else
		return 0;
}
