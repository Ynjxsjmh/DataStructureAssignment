#include<iostream>
#include<cstdio>
using namespace std;
struct circle{
	double x;
	double y;
	double r;
	int name;
	int fa;
};
circle  cc[7000];

void make_set(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cc[i].r=cc[i].x=cc[i].y=0;
		cc[i].name=i;
		cc[i].fa=-1;
	}
}

int findfa(int x)
{
	if(cc[x].fa<0)
	{
		return x;
	}
	return cc[x].fa=findfa(cc[x].fa);
}

void union_(int x,int y)
{
	int fx;
	int fy;
	fx=findfa(x);
	fy=findfa(y);
	if(fx==fy)
	{
		return;
	}else 
	{
		cc[x].fa=y;
	}
}

int main()
{
	FILE* in,*out;
	in=fopen("circle.in","r");
	out=fopen("circle.out","w");
	int n,i,j,d,sum,a[7000],r,k;
	sum=0;
	for(i=0;i<7000;i++)
	{
		a[i]=0;
	}
	fscanf(in,"%d",&n);
	if(n==0)
	{
		return sum;
	}
	sum=1;
	make_set(n);
	for(i=0;i<n;i++)
	{
		fscanf(in,"%d %d %d",&cc[i].x,&cc[i].y,&cc[i].r); 
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			d=(cc[i].x-cc[j].x)*(cc[i].x-cc[j].x)+(cc[i].y-cc[j].y)*(cc[i].y-cc[j].y);
			if(d<=(cc[i].r+cc[j].r))
			{
				union_(i,j);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		a[i]=findfa(i);
	}
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}
		r=a[i];
		a[i]=a[k];
		a[k]=r;
	}
	for(i=0;i<n-1;i++)
	{
		k=a[i];
		r=a[i+1];
		if(k!=r)
		{
			sum++;
		}
	}
	cout<<sum;
	fprintf(out,"%d",sum);
	fclose(in);
	fclose(out);
	return 0;
}
