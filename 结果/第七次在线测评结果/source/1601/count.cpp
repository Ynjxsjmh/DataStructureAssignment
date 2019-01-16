#include<stdio.h>
int main()
{
	FILE *in, *out;
	int n, a[50000], t, k;
	in=fopen("count.in", "r");
	out=fopen("count.out", "w");
	fscanf(in, "%d", &n);
	for(int i=0; i<n; i++)
	{
		fscanf(in, "%d", &a[i]);
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		if(a[j]>a[j+1])
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
	t=a[1];
	k=0;
	for(int i=0; i<n; i++)
	{
		if(a[i]==t)k++;
		else 
		{
			fprintf(out, "%d %d\n", t, k);
			t=a[i];
			k=1;
		} 
	}
	fprintf(out, "%d %d\n", t, k);
} 