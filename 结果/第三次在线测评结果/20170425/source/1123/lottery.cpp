#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int ans[7]={0};

struct lottery
{
	int num[7];
	lottery()
	{
		memset(num,0,sizeof(num));
	}
};

int main()
{
	queue<lottery*> que;
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	int i,j,k,n,same=0;
	int std[7]={0};
	lottery* temp;
	scanf("%d",&n);
	for(i=0;i<7;i++)
	{
        scanf("%d",&std[i]);
	}
	for(i=0;i<n;i++)
	{
		lottery* in=new lottery();
		for(j=0;j<7;j++)
		{
			scanf("%d",&(in->num[j]));
		}
		que.push(in);
	}
    for(i=0;i<n;i++)
    {
        same=0;
        if(!que.empty())
        {
             temp=que.front();
             que.pop();
        }
        for(j=0;j<7;j++)
        {
            for(k=0;k<7;k++)
            {
                if(temp->num[k]==std[j])
                {
                    same++;
                    continue;
                }
            }
        }
        ans[7-same]++;
    }
    for(i=0;i<7;i++)
    {
        printf("%d ",ans[i]);
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
