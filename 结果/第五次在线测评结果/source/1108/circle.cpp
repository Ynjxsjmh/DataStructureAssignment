#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

int father[7005];
int visit[7005];

int find(int v);
void united(int x,int y);

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	
	int n;                         //n用来表示有多少个圆; 
	int xx[7005],yy[7005],r[7005];
	int num=0;
	
	memset(visit,0,sizeof(visit));
	for(int i=0;i<7005;i++)
		father[i]=i;
		
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d %d %d",&xx[i],&yy[i],&r[i]);
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if( (xx[i]-xx[j])*(xx[i]-xx[j]) + (yy[i]-yy[j])*(yy[i]-yy[j]) <= (r[i]+r[j])*(r[i]+r[j]))
			{
				united(i,j);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(father[i]==i)
			num++;
	}
	
	printf("%d",num);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


int find(int v)
{
	if( father[v]==v ) 
		return v;
    return find( father[v] );
}

void united(int x,int y)
{
	father[find (y)] = find(x);
}
