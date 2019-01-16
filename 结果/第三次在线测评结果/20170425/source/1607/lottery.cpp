#include<stdio.h>
int a[40];
int s[10];
int main()
{
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	int n,m,i,j,sum;
	scanf("%d",&n);
	for(i = 1; i <= 7; i++)
	{
		scanf("%d",&m);
		a[m] = 1;
	}
	for(i = 1; i <= n; i++)
	{
		sum = 0;
		for(j = 1; j <= 7; j++)
		{
			scanf("%d",&m);
			if(a[m] == 1)sum++;
		}
		s[8-sum]++;
	}
	for(i = 1; i <= 7; i++)
		printf("%d ",s[i]);
	return 0;
	fclose(stdin);
	fclose(stdout); 
}