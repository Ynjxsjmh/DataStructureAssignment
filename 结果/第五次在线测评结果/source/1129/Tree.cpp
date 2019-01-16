#include<iostream>
#include<stdio.h>

using namespace std;

const int N=1001;

int Father[N];

int Find(int x)
{
    if(Father[x]!=x)
        Father[x]=Find(Father[x]);
    return Father[x];
}

void Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return;
    if(Father[x]!=Father[y]) Father[fy]=fx;
}
int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("tree.in","r");
    fp2=fopen("tree.out","w");
    int n;
    int sum=0,d=1,w=0;
    fscanf(fp1,"%d",&n);
    for(int i=1;i<=n;i++)
        Father[i]=i;
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        Union(x,y);
    }
    for(int i=n;i!=Find(i);i=Find(i),d++)
           w++;
    int u,v;
    fscanf(fp1,"%d %d",&u,&v);
    fprintf(fp2,"%d",d);
    fprintf(fp2,"%d",w);
    fprintf(fp2,"%d",sum);
}
