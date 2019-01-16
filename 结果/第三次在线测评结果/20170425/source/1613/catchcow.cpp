#include<stdio.h>
#define N 200020
int n,k;
struct xxx
{
	int x,step;
}q[N];
bool vis[N];
void bfs()
{
	int head=0,tail=1;
	q[0].x=n;q[0].step=0;
	vis[n]=1;
	while(head<tail)
	{
		xxx a=q[head++];
		if(a.x==k)
		{
			printf("%d\n",a.step);
			break;
		}
		if(a.x-1>=0&&!vis[a.x-1])
		{
			vis[a.x-1]=1;
			q[tail].x=a.x-1;
			q[tail++].step=a.step+1;
		}
		if(a.x<=k&&!vis[a.x+1])
		{
			vis[a.x+1]=1;
			q[tail].x=a.x+1;
			q[tail++].step=a.step+1;
		}
		if(a.x<=k&&!vis[a.x*2])
		{
			vis[a.x*2]=1;
			q[tail].x=a.x*2;
			q[tail++].step=a.step+1;
		}
	}
	return ;
}
int main()
{
	freopen("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);
	scanf("%d%d",&n,&k);
	bfs();
	fclose(stdin);
	fclose(stdout);
	return 0;
}