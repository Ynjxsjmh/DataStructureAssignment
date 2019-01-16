#include<stdio.h>
#include<stdlib.h>

struct number
{
	int id;
	int cnt;
}a[50020];

int b[50020];

int cmp1(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,m,i,j;
	m = 0;
	scanf("%d",&n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d",&b[i]);
	}
	qsort(b+1,n,sizeof(b[0]),cmp1);
	for(i = 1; i <= n; i++)
	{
		if(b[i] != a[m].id)
			a[++m].id = b[i];
		a[m].cnt++;
	}
	for(i = 1; i <= m; i++)
	{
		printf("%d %d\n",a[i].id,a[i].cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}