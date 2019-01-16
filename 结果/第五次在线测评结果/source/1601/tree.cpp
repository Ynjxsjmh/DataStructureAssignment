#include<stdio.h>
int kuai=1;
int main()
{
	FILE *in, *out;
	int n, a[101][3], v[7001], c[101], b[101], d[101], dis1=0, dis2=0, dis=0;
	in=fopen("tree.in", "r");
	out=fopen("tree.out", "w");
	fscanf(in, "%d", &n);
	for(int i=0; i<n; i++)
	{
		for (int j = 0; j < 2; j++)
			fscanf(in, "%d", &a[i][j]);
	}
	for(int i=0; i<n-1; i++)
	{
		b[a[i][0]]=1;
		c[i]=0;
	}
	for(int i=1; i<n-1; i++)
	{
		if(a[i][0]==a[i-1][0])
		{
			b[a[i][0]]++;
		}
	}
	int k=0, wide=0, deep=0;
	c[0]=1;
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<c[i-1]; j++)
		{
			c[i]+=b[++k];
		} 
	}
	for(int i=0; i<n; i++)
	{
		if(c[i]!=0)
		{
			deep=i+1;	
		}
	}
	for(int i=0; i<n; i++)
	{
		if(c[i]>wide)
		{
			wide=c[i];	
		}
	}
	int p, q; 
	p=a[n-1][0];	 	 			
	q=a[n-1][1];
	while(p!=1)
	{
		dis1++;
		for(int i=0; i<n-1; i++)
		{
			if(a[i][1]==p)
			{
				p=a[i][0];
				break;
			}
		}
	}
	while(q!=1)
	{
		dis2++;
		for(int i=0; i<n-1; i++)
		{
			if(a[i][1]==q)
			{
				q=a[i][0];
				break;
			}
		}
	}
	dis=dis1*2+dis2;
	fprintf(out, "%d\n%d\n%d", wide, deep, dis);
	return 0;
}