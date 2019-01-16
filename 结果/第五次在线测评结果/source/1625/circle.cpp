#include<stdio.h>
#include<math.h>

struct circleNode{int x,y,r;};
int main()
{	
	freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
	circleNode circle [8000];
	int n;
	int count=0;
	bool flag=1;
	scanf("%d",&n);
	scanf("%d%d%d",&circle[0].x,&circle[0].y,&circle[0].r);
	count++;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&circle[i].x,&circle[i].y,&circle[i].r);
		for(int j=0;j<i;j++)
		{	
			int dx=(circle[i].x-circle[j].x)*(circle[i].x-circle[j].x);
			int dy=(circle[i].y-circle[j].y)*(circle[i].y-circle[j].y);
			if(sqrt(dx+dy)<=circle[i].r+circle[j].r)
			{flag=0;break;}
			if(flag)
				count++;
		}
	}
	printf("%d",count);
	return 0;
} 
