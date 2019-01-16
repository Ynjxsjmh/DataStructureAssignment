#include<stdio.h>

int map[104][104];
int deep[104];
int que[104];

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,i,j,x,y,head,tail,d,wide,depth,u,v,style;
	style = 0;
	depth = 0;
	wide = 1;
	scanf("%d",&n);
	for(i = 1; i <= n-1; i++)
	{
		scanf("%d%d",&x,&y);
		map[x][++map[x][0]] = y;
		map[y][++map[y][0]] = x;
	}
	head = 1;
	tail = 2;
	que[1] = 1;
	deep[1] = 1;
	d = 1;
	while(head < tail)
	{
		i = que[head];
		depth = depth > deep[i] ? depth : deep[i];
		if(deep[i] != d)
		{
			d = deep[i];
			wide = wide > tail - head ? wide : tail - head;
		}
		for(j = 1; j <= map[i][0]; j++)
		{
			if(deep[map[i][j]] == 0)
			{
				que[tail++] = map[i][j];
				deep[map[i][j]] = deep[i]+1;
			}
		}
		head++;
	}
	scanf("%d%d",&u,&v);
	x = u;
	y = v;
	while(deep[x] > deep[y])
	{
		for(i = 1; i <= map[x][0]; i++)
		{
			if(deep[map[x][i]] < deep[x])
			{
				x = map[x][i];
			}
		}
	}
	while(deep[y] > deep[x])
	{
		for(i = 1; i <= map[y][0]; i++)
		{
			if(deep[map[y][i]] < deep[y])
			{
				y = map[y][i];
			}
		}
	}
	while(x != y)
	{
		for(i = 1; i <= map[x][0]; i++)
		{
			if(deep[map[x][i]] < deep[x])
			{
				x = map[x][i];
			}
		}
		for(i = 1; i <= map[y][0]; i++)
		{
			if(deep[map[y][i]] < deep[y])
			{
				y = map[y][i];
			}
		}
	}
	printf("%d\n%d\n",depth,wide);
	printf("%d",(deep[u] - deep[x])*2 + deep[v] - deep[x]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}