#include<stdio.h>
#include<stdlib.h>
int n,u,v,dep_max=0,wid_max=0,dis;
int a[101][3];
int dep[101];
bool vis[101];
int ss(int x,int val)
{
	vis[x]=1;
	if(x==v)
	{
		dis=val;
		return 1;
	}
	if(a[x][1]!=0&&vis[a[x][1]]==0)
	{
		if(ss(a[x][1],val+1)==1)return 1;
	}
	if(a[x][2]!=0&&vis[a[x][2]]==0)
	{
		if(ss(a[x][2],val+1)==1)return 1;
	}
	if(a[x][0]!=0&&vis[a[x][0]]==0)
	{
		if(ss(a[x][0],val+2)==1)return 1;
	}
	return 0;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(a[x][1]==0)a[x][1]=y;
		else a[x][2]=y;
		a[y][0]=x;
	}
	dep[1]=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i][1]!=0)dep[a[i][1]]=dep[i]+1;
		if(a[i][2]!=0)dep[a[i][2]]=dep[i]+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(dep[i]>dep_max)dep_max=dep[i];
	}
	for(int i=1;i<=n;i++)
	{
		int wid=0;
		for(int j=1;j<=n;j++)
		{
			if(dep[j]==i)wid++;
		}
		if(wid>wid_max)wid_max=wid;
	}
	scanf("%d%d",&u,&v);
	ss(u,0);
	printf("%d\n%d\n%d\n",dep_max,wid_max,dis);
	fclose(stdin);
	fclose(stdout);
	return 0;
}