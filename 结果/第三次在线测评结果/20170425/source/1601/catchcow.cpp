#include<stdio.h>
int rear=0, fro=0, dis[100010], que[100010];
void qins(int x)
{
	que[rear++]=x;
}
int qdel()
{
	return que[fro++];
}

int getfrom()
{
	return que[fro];
}

int main()
{
	int n, m, x, i;
	FILE* f1;
	FILE* f2;
	f1 = fopen("catchcow.in","r");
	f2 = fopen("catchcow.out","w");
	fscanf(f1, "%d %d", &n, &m);
	for(i=0; i<=100002; i++)dis[i]=-1;
	dis[n]=0;
	qins(n);
	x=n;
	if(n==m)fprintf(f2, "0\n");
	else
	{
		while(x>=0)
		{
			x=qdel();
			if(x>0)
			{
				if(x - 1 == m)
				{
					fprintf(f2, "%d\n", dis[x]+1);
					return 0;
				}
				if(dis[x-1]==-1)
				{
					dis[x-1]=dis[x]+1;
					qins(x-1);
				}
			}
			if(x<100000)
			{
				if(x + 1 == m)
				{
					fprintf(f2, "%d\n", dis[x]+1);
					return 0;
				}
				if(dis[x+1]==-1)
				{
					dis[x+1]=dis[x]+1;
					qins(x+1);
				}
			}
			if(x<50001)
			{
				if(2 * x == m)
				{
					fprintf(f2, "%d\n", dis[x]+1);
					return 0;
				}
				if(dis[2*x]==-1)
				{
					dis[2*x]=dis[x]+1;
					qins(2*x);
				}
			}
		}
	}
	return 0;
}
