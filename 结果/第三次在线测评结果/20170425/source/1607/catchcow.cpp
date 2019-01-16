#include<stdio.h>
#include<string.h>
int a[100100];
int min(int x,int y)
{
	return x<y?x:y;
}
int main()
{
	int i,n,m;
	freopen("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(a,0x3f,sizeof(a));
	for(i=0;i<=n;i++)
	{
		a[i]=n-i;
	}
	for(i=n+1;i<=m;i++)
	{
		if(i%2==0)
		{
			a[i]=min(a[i-1]+1,min(a[i/2]+1,a[i+1]-1));
		}
		else
		{
			a[i]=min(a[i-1]+1,min(a[i/2]+2,min(a[i/2+1]+2,a[i+1]+1)));
		}
	}
	printf("%d",a[m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}