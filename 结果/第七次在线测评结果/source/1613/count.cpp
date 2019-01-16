#include<stdio.h>
#include<stdlib.h>
int n,x[50005];
int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	qsort(x,n,sizeof(int),cmp);
	for(int i=0;i<n;i++)
	{
		int ans=1;
		while(x[i+1]==x[i]&&i<n)
		{
			i++;
			ans++;
		}
		printf("%d %d\n",x[i],ans);
	}
	fclose(stdin);
	fclose(stdout);
}