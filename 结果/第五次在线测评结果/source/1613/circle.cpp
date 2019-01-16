#include<stdio.h>
#include<math.h>
int n,ans;
int x[7001],y[7001],r[7001],p[7001];
int find(int x)
{
    if(p[x]==x) return x;
    return p[x]=find(p[x]);
}
void un(int x,int y)
{
	int tx,ty;
	tx=find(x);ty=find(y);
	if(tx!=ty)p[tx]=ty;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&r[i]);
		p[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			float dis=sqrt(((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j])));
			if(dis<=(r[i]+r[j]))
			{
				int ti=find(i);
				int tj=find(j);
				if(ti!=tj)un(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==i)ans++;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}