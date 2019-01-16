#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int father[105];
int dep[105];
int find_num=0;

int find(int v)
{
	find_num++;
	if( father[v] == v )
		return v;
	return find( father[v] );
}

inline void swap(int &x,int &y)
{
	int z;
	z=x;
	x=y;
	y=z;
}

bool cmp(int a, int b)
{
	if(a<b)
		return false;
	return true;	
}

//void un(int x,int y)
//{
//	int xx=find(x);
//	int yy=find(y);
//	
//	if(xx!=yy)
//		father[yy]=xx;
//}

int nearest_father_node(int x,int y)
{
    int xx=dep[x];
    int yy=dep[y];
    while(xx>yy)
    {
        x=father[x];
        xx--;
    }
    while(yy>xx)
    {
        y=father[y];
        yy--;
    }
    while(x!=y)
    {
        x=father[x];
        y=father[y];
    }
    return x;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);	
	
	int n,u,v;
	int child[105];
	
	memset(dep,0,sizeof(dep));
	memset(child,0,sizeof(child));
	for(int i=0;i<105;i++)
		father[i]=i;
		
	scanf("%d",&n);
	int nn=n;
	
	nn--;
	while(nn--)
	{
		scanf("%d%d",&u,&v);
		father[v]=u;
//		printf("%d的父亲节点是%d\n",v,u);
	}
	scanf("%d%d",&u,&v);            //此时u,v里存放的是要查找距离的两节点
	
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d的父节点为%d\n",i,father[i]);
//	}
	
	int depth=0;                      //求深度 
//	cout<<"程序执行!"<<endl;
	
	for(int i=1 ; i <= n ; i ++)
	{
//		cout<<"程序执行!"<<endl;
		find(i);
//		printf("%d找到父节点用了%d次\n",i,find_num);
		dep[i]=find_num;
		if(depth<find_num)
			swap(depth,find_num);	
		find_num=0;
//		printf("%d的深度为%d\n",i,dep[i]);
	}
	printf("%d\n",depth);
	
	
	int width[105];                   //求宽度 
	memset(width,0,sizeof(105));
	for(int i=1;i<=n;i++)
		child[ father[i] ]++;
	child[1]--;
//	for(int i=1;i<=n;i++)
//		printf("%d节点的宽度为%d\n",i,child[i]);
	for(int i=1;i<n;i++)
	{
		width[i]=child[i];
		for(int j=i+1;j<=n;j++)
		{
			if(father[i]==father[j])
			{
				width[i]+=child[j];
			}
		}
	}
	sort(width,width+n,cmp);
	printf("%d\n",width[0]-2);
	
	int node=nearest_father_node(u,v);
	int distance=2*(dep[u]-dep[node])+dep[v]-dep[node];
	printf("%d",distance);
}
