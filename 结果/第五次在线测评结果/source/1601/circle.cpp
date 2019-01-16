#include<stdio.h>
int kuai=1;
int main()
{
	FILE *in, *out;
	int n, a[7001][3], v[7001];
	in=fopen("circle.in", "r");
	out=fopen("circle.out", "w");
	fscanf(in, "%d", &n);
	for(int i=0; i<n; i++)
	{
		for (int j = 0; j < 3; j++)
			fscanf(in, "%d", &a[i][j]);
	}
	for(int i=0; i<n; i++)
	{
		v[i]=i;
	}
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			if(v[j]!=v[i])
			{
				int x, y, r, l;
				x=a[i][0]-a[j][0];
				y=a[i][1]-a[j][1];
				l=x*x+y*y;
				r=(a[i][2]+a[j][2])*(a[i][2]+a[j][2]);
				if(l<=r)v[j]=v[i];
			}
			
			
		}
	}
	int p[101], pp=1;
	p[0]=v[0];
	for(int i=1; i<n; i++)
	{
		for (int j = 0; j < pp; j++)
		{
			if (v[i]!=p[j])
			{
				pp++;
				p[pp]=v[i];
			}
		}
	}
//	printf("%d", kuai);
	fprintf(out, "%d", kuai);
	return 0;
}
