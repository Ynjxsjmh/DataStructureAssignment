#include<stdio.h>
int n,a[7],b[7];
int ans[7];
int main()
{
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<7;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		int temp=0;
		for(int j=0;j<7;j++)
		{
			scanf("%d",&b[j]);
			for(int k=0;k<7;k++)
			{
				if(b[j]==a[k])temp++;
			}
		}
		if(temp!=0)ans[7-temp]++;
	}
	printf("%d",ans[0]);
	for(int i=1;i<7;i++)
	{
		printf(" %d",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}