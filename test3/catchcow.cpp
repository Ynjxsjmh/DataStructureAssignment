#include <cstring>
#include <iostream>
using namespace std;

int q[10000000];
int visit[1000000];

int main()
{
	freopen("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);
	
	int n,k;
	int i;
	int head,tail;
	int first=0,time=0;
	
	scanf("%d%d",&n,&k);
	
	memset(q,0,sizeof(q)); 
	memset(visit,0,sizeof(visit));
	
	head=tail=0;	
	q[head]=n;
	tail++;
	
	if(n>=k)
	{
		time=n-k;
		printf("%d",time);
	}
	else
	{
		while(head<tail)
		{
			if(q[head]>=0&&q[head]<=100000&&visit[ q[head] ]==0)	
			{
				for(i=0;i<3;i++)
				{
					if(i==0)
					{
						visit[ q[head] ]=1;
						q[tail++]=q[head]-1;
					}
					else if(i==1)
					{
						visit[ q[head] ]=1;
						q[tail++]=q[head]+1;
					}
					else
					{
						visit[ q[head] ]=1;
						q[tail++]=q[head]*2;
					}
				}
			}
		
			if(!first)
			{
				q[tail++]=-100;
				first=1;
			}
		
			if(q[head]==-100)
			{
				time++;
				head++;
				q[tail++]=-100;
			}
			else
			{
				if(q[head]==k)
				{
					head++;
					time++;
					printf("%d",time);
					return 0;
				}
			
				else 
				{
					head++;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
