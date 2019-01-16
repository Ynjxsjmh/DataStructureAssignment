#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 210000

struct node
{
    int x;
    int step;
};

int n,k;
bool vist[maxn];
node que[maxn];
void bfs()
{
	int head,tail;
	head=tail=0;
	tail++;
	que[tail].x=n;
	que[tail].step=0;

	vist[n]=1;

	while(head<tail)
	{
	    head++;
		node now=que[head];
		if(now.x==k)
		{
			cout<<now.step<<endl;
			return ;
		}

		if(now.x-1>=0 && !vist[now.x-1])
		{
			vist[now.x-1]=1;
			tail++;
			que[tail].x=now.x-1;
			que[tail].step=now.step+1;
		}
		if(now.x<=k && !vist[now.x+1])
		{
			vist[now.x+1]=1;
			tail++;
			que[tail].x=now.x+1;
			que[tail].step=now.step+1;
		}
		if(now.x<=k && !vist[2*now.x])
		{
			vist[2*now.x]=1;
			tail++;
			que[tail].x=2*now.x;
			que[tail].step=now.step+1;
		}
	}

	return;
}

int main()
{
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
	cin>>n>>k;
    bfs();
	return 0;
}
