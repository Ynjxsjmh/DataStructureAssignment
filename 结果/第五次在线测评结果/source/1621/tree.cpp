// 二叉树问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"
#include"queue"
using namespace std;
int edge[101][101];
int A[101][101];
int vis[101];
int fa[105];
bool clca[105];
int num, i, x1, x2, x3, x4[50], x5, i1 = 1, j, k, ji[50];
int m1, m2;
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int shen=0, kuan=0, juli=0;
	scanf("%d", &num);
	memset(edge, 0, sizeof(edge));
	memset(vis, 0, sizeof(vis));
	memset(x4, 0, sizeof(x4));
	memset(ji, 0, sizeof(ji));
	memset(clca, false, sizeof(clca));
	for (i = 1; i <= num-1; i++)
	{
		scanf("%d %d", &x1, &x2);
		edge[x1][x2] = 1;
		edge[x2][x1] = 1;
	}
	scanf("%d %d", &m1, &m2);
	queue<int>q1;
	q1.push(1); x4[i1]=1;
	fa[1] = 0;
	while (!q1.empty())
	{
		x3 = q1.front(); q1.pop();
		vis[x3] = 1;
		x4[i1]--;
		shen = max(shen, i1);
		for (i =  1; i <= num; i++)
			if (edge[x3][i] == 1&&vis[i]==0)
			{
				fa[i] = x3;
				x4[i1 + 1]++;
				q1.push(i);
				vis[i] = 1;
			}
		if (x4[i1] == 0)
		{
			i1++;
			ji[i1] = x4[i1];
		}
	}
	fa[1] = 0;
	for (i1 = 0; i1 < 50; i1++)
		if (kuan < ji[i1])
			kuan = ji[i1];
	for (i = 1; i <= num; i++) {
		A[i][i] = 0;
		for (j = 1; j <= num; j++)
			if (i!=j) if (edge[i][j] > 0) A[i][j] = edge[i][j]; else A[i][j] = -1;
	}
	for (k = 1; k <= num; k++)
		for (i = 1; i <= num; i++)
			for (j = 1; j <= num; j++)
				if (A[i][k]!=-1 && A[k][j]!=-1 && (A[i][j]==-1 || A[i][k] + A[k][j]<A[i][j]))
					A[i][j] = A[i][k] + A[k][j];
	/*for (i = 0; i <= 50; i++)
		if (ji[i]!=0)
			shen = i;*/
	int lca = 0;
	for (int now = m1; now; now = fa[now]) clca[now] = true;
	for (int now = m2; lca == 0; now = fa[now]) if (clca[now]) lca = now;
	juli = 2 * A[lca][m1] + A[lca][m2];
	printf("%d\n%d\n%d\n", shen, kuan, juli);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

