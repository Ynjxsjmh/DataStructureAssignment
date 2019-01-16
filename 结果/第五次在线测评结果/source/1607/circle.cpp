#include<stdio.h>
long long fa[8000];
long long used[8000];
struct circle
{
	long long x;
	long long y;
	long long r;
}c[8000];
long long find(long long a)
{
	if(a == fa[a])return a;
	fa[a] = find(fa[a]);
	return fa[a];
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	long long n,m,i,j,fi,fj,sum;
	sum = 0;
	scanf("%I64d",&n);
	for(i = 1; i <= n; i++)
	{
		scanf("%I64d%I64d%I64d",&c[i].x,&c[i].y,&c[i].r);
		fa[i] = i;
	}
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j < i; j++)
		{
			if((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y) <= (c[i].r+c[j].r)*(c[i].r+c[j].r))
			{
				fi = find(i);
				fj = find(j);
				if(fi != fj)
				{
					fa[fi] = fj;
				}
			}
		}
	}
	for(i = 1; i <= n; i++)
	{
		if(used[find(i)] == 0)
		{
			sum++;
			used[find(i)] = 1;
		}
	}
	printf("%I64d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}