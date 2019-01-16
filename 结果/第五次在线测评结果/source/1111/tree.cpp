#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 105;

int gate[maxn][maxn];

int creat()
{

}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	scanf("%d",&n);
	int t = n - 1;
	int x,y;
	memset(gate,0,sizeof(gate));
	while(t--)
	{
		scanf("%d %d",&x,&y);
		gate[x][y] = gate[y][x] = 1;
	}
	scanf("%d %d",&x,&y);

}