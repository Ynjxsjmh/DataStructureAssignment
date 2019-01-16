#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	
	int zhang[8],jiang[7],buy[7];
	int time=0,test,i,j,n;
	
	scanf("%d",&n);
	
	memset(zhang,0,sizeof(zhang));
	memset(jiang,0,sizeof(jiang));
	memset(buy,0,sizeof(buy));
	
	for(i=0;i<7;i++)
		scanf("%d",&jiang[i]);
	
	for(test=1;test<=n;test++)
	{
		time=0;
		
		for(i=0;i<7;i++)
			scanf("%d",&buy[i]);
		
		for(i=0;i<7;i++)
		{
			for(j=0;j<7;j++)
			{
				if(jiang[i]==buy[j])
				{
					time++;
				}
			}
		}
		zhang[time]++;	
	}
	
	for(i=7;i>1;i--)
		printf("%d ",zhang[i]);
	printf("%d",zhang[i]);
	
	fclose(stdin);
	fclose(stdout);	
	
	return 0;
}
